#include "../include/menu.hpp"

#include <iostream>

void showTaskMenu()
{
    std::cout << "\n\t\t\t\tTASK" << "\n";
    std::cout << "Task: Implement the class 'Product' with the following fields:" << "\n";
    std::cout << "  - Product name" << "\n";
    std::cout << "  - Quantity" << "\n";
    std::cout << "  - Price" << "\n";
    std::cout << "  - Receipt date" << "\n";
    std::cout << "Overload the << and >> operators for file input/output," << "\n";
    std::cout << "and implement a method to return quantity of products by a given year.\n" << "\n";

    std::cout << "\n\t\t\t\tMENU" << "\n";
    std::cout << "1. Add a new product." << "\n";
    std::cout << "2. Show all products." << "\n";
    std::cout << "3. Find total quantity by year." << "\n";
    std::cout << "4. Exit program." << "\n";
}