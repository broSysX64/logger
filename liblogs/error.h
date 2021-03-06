#ifndef ERROR_H
#define ERROR_H

#include <memory>
#include <string>

#include "log_level.h"

namespace logging {

class error_private;

class error {
public:
  explicit error(error_type type = logging::error_type::NO_ERROR,
                 const std::string &text = std::string());
  error(const error &other);
  ~error();

  error &operator=(const error &other);

  error_type type() const;

  // Return true if there is an error
  bool has_error() const;
  std::string text() const;

  explicit operator bool() const { return !has_error(); }

private:
  std::shared_ptr<error_private> p_;
};
} // namespace logging

#endif // ERROR_H
