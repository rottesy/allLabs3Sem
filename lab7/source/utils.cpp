#include "../include/utils.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>

bool isDigits(const std::string &str, const int pos, const int len)
{
    for (int i = 0; i < len; i++)
    {
        if (isdigit(str[pos + i]) != 1)
        {
            return false;
        }
    }

    return true;
}

bool isDigits(const std::string_view &str)
{
    return std::all_of(str.begin(), str.end(), [](unsigned char sym) { return std::isdigit(sym); });
}

bool isFileEmpty(const std::string &filename)
{
    std::ifstream file(filename);
    return !file.is_open() || file.peek() == std::ifstream::traits_type::eof();
}