#pragma once
#include <iostream>
#include <limits>

template <typename T> T getValue()
{
    T value;
    while (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[31m" << "Invalid input. Try again: " << "\033[0m";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

inline void showMenu()
{
    std::cout << "\n\t\t\t\tRING MENU" << std::endl;
    std::cout << "1. Create ring." << std::endl;
    std::cout << "2. Add element." << std::endl;
    std::cout << "3. Remove element." << std::endl;
    std::cout << "4. Display ring." << std::endl;
    std::cout << "5. Sort ring." << std::endl;
    std::cout << "6. Search for element." << std::endl;
    std::cout << "7. Clear ring." << std::endl;
    std::cout << "8. Exit program." << std::endl;
}

inline void showAddMenu()
{
    std::cout << "\n\t\t\t\tADD MENU" << std::endl;
    std::cout << "1. Add to the beginning (push_front)." << std::endl;
    std::cout << "2. Add to the end (push_back)." << std::endl;
}

inline void showRemoveMenu()
{
    std::cout << "\n\t\t\t\tREMOVE MENU" << std::endl;
    std::cout << "1. Remove from the beginning (pop_front)." << std::endl;
    std::cout << "2. Remove from the end (pop_back)." << std::endl;
}

void choiceRingType();