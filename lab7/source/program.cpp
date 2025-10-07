#include "../include/program.hpp"

#include <fstream>

#include "../include/consts.hpp"
#include "../include/menu.hpp"
#include "../include/utils.hpp"

Program::Program() = default;

void Program::addProduct()
{
    Product::add();

    std::cout << "\nYou successfully added the product!" << "\n";
}

void Program::showAllProducts()
{
    if (isFileEmpty(FILE_WITH_PRODUCTS))
    {
        std::cout << "\nError: Product list is empty! Please add a product first (use "
                     "option 1)."
                  << "\n";
        return;
    }

    Product::showAll();

    std::cout << "\nYou successfully printed all products!" << "\n";
}

void Program::displayQuantityByYear()
{
    if (isFileEmpty(FILE_WITH_PRODUCTS))
    {
        std::cout << "\nError: Product list is empty! Please add a product first (use "
                     "option 1)."
                  << "\n";
        return;
    }

    int year = getValue<int>("\nEnter year to search for: ");
    int totalQuantity = Product::getQuantityByYear(year);

    if (totalQuantity == 0)
    {
        std::cout << "\nNo products found for year " << year << "." << "\n";
        return;
    }

    std::cout << "\nTotal quantity of products received in " << year << ": " << totalQuantity << "\n";

    std::cout << "\nYou successfully found total quantity by year!" << "\n";
}

void Program::run()
{
    system("cls");

    int opt = 0;

    while (true)
    {
        showTaskMenu();
        opt = getValue<int>("\nPlease enter menu option: ");

        switch (opt)
        {
            case 1:
                addProduct();
                break;
            case 2:
                showAllProducts();
                break;
            case 3:
                displayQuantityByYear();
                break;
            case 4:
                std::cout << "\nYou have successfully exited the program." << "\n";
                return;
            default:
                std::cout << "\nError, you picked is an incorrect menu option. "
                             "Please try again."
                          << "\n";
        }
    }
}