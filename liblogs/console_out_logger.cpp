#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "console_out_logger.h"
#include "error.h"

namespace logging {

console_out_logger::console_out_logger(const logging::logging_config_t &config)
    : logger(config),
      levels(config.find("color") != config.end() ? colors : uncolors) {}

error console_out_logger::log(const std::string &message,
                              const log_level level) {
  if (level < REGISTER_LOG_LEVEL)
    return error(error_type::NO_ERROR);

  std::string output;
  output.reserve(message.length() + 64);
  output.append(get_timestamp());
  output.append(levels.find(level)->second);
  output.append(message);
  output.push_back('\n');
  log(output);

  return error(error_type::NO_ERROR);
}

error console_out_logger::log(const std::string &message) {
  std::cout << message;
  std::cout.flush();

  return error(error_type::NO_ERROR);
}

} // namespace logging
