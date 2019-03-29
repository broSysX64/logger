#ifndef LOG_LEVEL_H
#define LOG_LEVEL_H

#include <chrono>
#include <unordered_map>

namespace logging {

enum class log_level : int {
  TRACE = 0,
  DEBUG = 1,
  INFO = 2,
  WARN = 3,
  ERROR = 4
};

enum class error_type : int {
  NO_ERROR = 0,
  UNKNOWN_ERROR = 1,
  REGISTER_LOG_LEVEL_ERROR = 2,
  LOG_ERROR = 3,
  CONFIG_ERROR = 4
};

struct generate_hash {
  template <typename T> std::size_t operator()(T t) const {
    return static_cast<std::size_t>(t);
  }
};

const std::unordered_map<log_level, std::string, generate_hash> uncolors{
    {log_level::ERROR, " [ERROR] "},
    {log_level::WARN, " [WARN] "},
    {log_level::INFO, " [INFO] "},
    {log_level::DEBUG, " [DEBUG] "},
    {log_level::TRACE, " [TRACE] "}};

const std::unordered_map<log_level, std::string, generate_hash> colors{
    {log_level::ERROR, " \x1b[39;1m[ERROR]\x1b[0m "},
    {log_level::WARN, " \x1b[41;1m[WARN]\x1b[0m "},
    {log_level::INFO, " \x1b[42;1m[INFO]\x1b[0m "},
    {log_level::DEBUG, " \x1b[43;1m[DEBUG]\x1b[0m "},
    {log_level::TRACE, " \x1b[44;1m[TRACE]\x1b[0m "}};

constexpr log_level REGISTER_LOG_LEVEL = log_level::INFO;

inline std::string get_timestamp() {
  std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
  std::time_t tt = std::chrono::system_clock::to_time_t(tp);
  std::tm gmt{};
  gmtime_r(&tt, &gmt);
  std::chrono::duration<double> fractional_seconds =
      (tp - std::chrono::system_clock::from_time_t(tt)) +
      std::chrono::seconds(gmt.tm_sec);
  std::string buffer("year/mo/dy hr:mn:sc.xxxxxx");
  sprintf(&buffer.front(), "%04d/%02d/%02d %02d:%02d:%09.6f",
          gmt.tm_year + 1900, gmt.tm_mon + 1, gmt.tm_mday, gmt.tm_hour,
          gmt.tm_min, fractional_seconds.count());
  return buffer;
}

template <typename T> void ignore(T &&) {}

} // namespace logging

#endif // LOG_LEVEL_H
