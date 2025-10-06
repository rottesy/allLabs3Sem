#pragma once

#include <iostream>
#include <limits>

#include "../include/consts.hpp"

template <typename T> T getValue(const std::string &msg)
{
    T value;
    int sym = 0;

    std::cout << msg;

    while (true)
    {
        if (std::cin.peek() != '\n' && std::cin.peek() != ' ' && (std::cin >> value).good())
        {
            sym = std::cin.peek();
            if ((char)sym == '\n' || (char)sym == EOF)
            {
                std::cin.get();
                return value;
            }
        }

        std::cin.clear();
        while (std::cin.get() != '\n' && !std::cin.eof())
            ;
        std::cout  << "\nError, invalid input. Please try again: ";
    }
}

template <>
inline std::string getValue<std::string>(const std::string &msg) {
    std::string value;
    std::cout << msg;
    
    
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }
    
    std::getline(std::cin, value);  
    
   
    if (value.empty()) {
        std::cout << "Error: string cannot be empty. Please try again: ";
        
        return getValue<std::string>(msg);
    }
    
    return value;
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