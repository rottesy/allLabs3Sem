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
    std::cout << "\n\t\t\t\tRING MENU" << "\n";
    std::cout << "1. Create ring." << "\n";
    std::cout << "2. Add element." << "\n";
    std::cout << "3. Remove element." << "\n";
    std::cout << "4. Display ring." << "\n";
    std::cout << "5. Sort ring." << "\n";
    std::cout << "6. Search for element." << "\n";
    std::cout << "7. Clear ring." << "\n";
    std::cout << "8. Exit program." << "\n";
}

inline void showAddMenu()
{
    std::cout << "\n\t\t\t\tADD MENU" << "\n";
    std::cout << "1. Add to the beginning (push_front)." << "\n";
    std::cout << "2. Add to the end (push_back)." << "\n";
}

inline void showRemoveMenu()
{
    std::cout << "\n\t\t\t\tREMOVE MENU" << "\n";
    std::cout << "1. Remove from the beginning (pop_front)." << "\n";
    std::cout << "2. Remove from the end (pop_back)." << "\n";
}

void choiceRingType();