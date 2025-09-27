#include "../include/menu.hpp"
#include "../include/utils.hpp"
#include <iostream>

void showMenu()
{
    std::cout << "\n=== Minimum Value Finder Menu ===\n";
    std::cout << "1. Work with integers (int)\n";
    std::cout << "2. Work with floating-point numbers (double)\n";
    std::cout << "3. Work with characters (char)\n";
    std::cout << "0. Exit\n";
    std::cout << "Select option: ";
}

template <typename T> void handleArrayMenu(const char *typeName)
{
    std::cout << "\n=== Working with " << typeName << " type ===\n";
    std::cout << "Enter array size: ";
    int size = getInput<int>("");

    if (size <= 0)
    {
        std::cout << "Size must be positive!\n";
        return;
    }

    auto *arr = new T[size];
    inputArray(arr, size);
    displayArray(arr, size);

    T minVal = findMin(arr, arr + size);
    std::cout << "Minimum value: " << minVal << "\n";

    delete[] arr;
}

template void handleArrayMenu<int>(const char *typeName);
template void handleArrayMenu<double>(const char *typeName);
template void handleArrayMenu<char>(const char *typeName);
