#include "../include/menu.hpp"

#include <iostream>

void showTaskMenu()
{
    std::cout << "\n\t\t\t\tTASK" << std::endl;
    std::cout << "Task: Implement the class 'Product' with the following fields:" << std::endl;
    std::cout << "  - Product name" << std::endl;
    std::cout << "  - Quantity" << std::endl;
    std::cout << "  - Price" << std::endl;
    std::cout << "  - Receipt date" << std::endl;
    std::cout << "Overload the << and >> operators for file input/output," << std::endl;
    std::cout << "and implement a method to return quantity of products by a given year.\n" << std::endl;

    std::cout << "\n\t\t\t\tMENU" << std::endl;
    std::cout << "1. Add a new product." << std::endl;
    std::cout << "2. Show all products." << std::endl;
    std::cout << "3. Find total quantity by year." << std::endl;
    std::cout << "4. Exit program." << std::endl;
}