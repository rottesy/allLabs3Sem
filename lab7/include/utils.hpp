#pragma once

#include <iostream>
#include <limits>

#include "../include/consts.hpp"

template <typename T> T getValue(const std::string &msg)
{
    T value;

    std::cout << msg;

    while (true)
    {
        if (std::cin >> value)
        {

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << kRedColor << "\nError, invalid input. Please try again: " << kWhiteColor;
        }
    }
}

template <typename T> bool isValidFileOpen(T &file, const std::string &fileName)
{
    if (!file.is_open())
    {
        std::cerr << "\nError, could not open " << fileName << "\n";
        return false;
    }
    return true;
}

bool isDigits(const std::string &str, int pos, int len);



bool isFileEmpty(const std::string &filename);