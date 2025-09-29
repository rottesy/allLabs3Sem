#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class InvalidInputException : public std::exception
{
  private:
    std::string message;

  public:
    InvalidInputException(const std::string &input, const std::string &requirement);
    [[nodiscard]] const char *what() const noexcept override;
};

#endif