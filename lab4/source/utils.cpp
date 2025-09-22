#include "../include/utils.hpp"
#include "../include/const.hpp"
#include <iostream>

int myStrlen(const char *str)
{
    if (str == nullptr)
    {
        return 0;
    }
    int len = 0;

    for (int ind = 0; str[ind] != '\0'; ind++)
    {
        len++;
    }

    return len;
}

int getNumber(const char *msg)
{
    int num = 0;

    std::cout << msg;

    while (true)
    {
        if (std::cin.peek() == '\n' || std::cin.peek() == ' ' || std::cin.fail())
        {
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "\nError, invalid input. Please try again: ";
            continue;
        }
        if ((std::cin >> num).good() && std::cin.get() == '\n' && (kMinInt <= num) && (num <= kMaxInt))
        {
            return num;
        }
    }
}