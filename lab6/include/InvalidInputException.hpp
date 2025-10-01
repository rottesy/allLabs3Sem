#ifndef INVALIDINPUTEXCEPTION_HPP
#define INVALIDINPUTEXCEPTION_HPP

#include <stdexcept>
#include <string>

class InvalidInputException : public std::exception
{
  private:
    std::string message;

  public:
    InvalidInputException(const std::string &input, const std::string &requirement);
    explicit InvalidInputException(const std::string_view &customMessage);
    [[nodiscard]] const char *what() const noexcept override;
};

#endif