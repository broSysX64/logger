#include <memory>

#include "error.h"
#include "file_out_logger.h"

namespace logging {

file_out_logger::file_out_logger(const logging_config_t &config)
    : logger(config) {
  auto name = config.find("file_name");
  if (name == config.end())
    throw std::runtime_error("No output file provided to file logger");
  file_name = name->second;

  reopen_interval = std::chrono::seconds(10);
  auto interval = config.find("reopen_interval");
  if (interval != config.end()) {
    try {
      reopen_interval = std::chrono::seconds(std::stoul(interval->second));
    } catch (...) {
      throw std::runtime_error(interval->second +
                               " is not a valid reopen interval");
    }
  }
  reopen();
}

error file_out_logger::log(const std::string &message, const log_level level) {
  if (level < REGISTER_LOG_LEVEL)
    return error(error_type::NO_ERROR);

  std::string output;
  output.reserve(message.length() + 64);
  output.append(get_timestamp());
  output.append(uncolors.find(level)->second);
  output.append(message);
  output.push_back('\n');
  log(output);

  return error(error_type::NO_ERROR);
}

error file_out_logger::log(const std::string &message) {
  lock.lock();
  file << message;
  file.flush();
  lock.unlock();
  reopen();

  return error(error_type::NO_ERROR);
}

void file_out_logger::reopen() {
  auto now = std::chrono::system_clock::now();
  lock.lock();
  if (now - last_reopen > reopen_interval) {
    last_reopen = now;
    try {
      file.close();
    } catch (...) {
    }
    try {
      file.open(file_name, std::ofstream::out | std::ofstream::app);
      last_reopen = std::chrono::system_clock::now();
    } catch (std::exception &e) {
      try {
        file.close();
      } catch (...) {
      }
      throw e;
    }
  }
  lock.unlock();
}
} // namespace logging
