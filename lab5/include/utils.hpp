#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

template <typename T> T getInput(const char *msg)
{
    T value;
    std::cout << msg;

    while (true)
    {
        if (std::cin >> value)
        {
            if (std::cin.get() == '\n')
            {
                return value;
            }
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "Error, invalid input. Please try again: ";
        }
        else
        {
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "Error, invalid input. Please try again: ";
        }
    }
}

template <typename T> T findMin(const T *begin, const T *end)
{
    if (begin == end || begin == nullptr || end == nullptr)
    {
        std::cout << "Array is empty or invalid pointers!" << "\n";
        return T();
    }

    T minVal = *begin;
    for (const T *it = begin + 1; it != end; it++)
    {
        if (*it < minVal)
        {
            minVal = *it;
        }
    }
    return minVal;
}

template <typename T> void inputArray(int size,T *arr)
{
    std::cout << "Input " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Element " << i + 1 << ": ";
        arr[i] = getInput<T>("");
    }
}

template <typename T> void printArray(const T *arr, int size)
{
    std::cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}




#endif