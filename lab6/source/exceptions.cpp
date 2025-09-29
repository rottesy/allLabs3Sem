#include "../include/exceptions.hpp"

InvalidInputException::InvalidInputException(const std::string &input, const std::string &requirement)
{
    message = "Invalid input: '" + input + "'. " + requirement;
}

const char *InvalidInputException::what() const noexcept { return message.c_str(); }