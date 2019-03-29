#ifndef CONSOLE_OUT_LOGGER_H
#define CONSOLE_OUT_LOGGER_H

#include "logger.h"

namespace logging {

class error;

class console_out_logger : public logger {
public:
  console_out_logger() = delete;
  console_out_logger(const logging_config_t &config);
  virtual error log(const std::string &message, const log_level level);
  virtual error log(const std::string &message);

private:
  explicit console_out_logger(const console_out_logger &) noexcept;
  console_out_logger &operator=(const console_out_logger &) noexcept;

protected:
  const std::unordered_map<log_level, std::string, generate_hash> levels;
};
} // namespace logging

#endif // CONSOLE_OUT_LOGGER_H
