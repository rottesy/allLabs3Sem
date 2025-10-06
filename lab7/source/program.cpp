#include "../include/program.hpp"

#include <fstream>

#include "../include/consts.hpp"
#include "../include/menu.hpp"
#include "../include/utils.hpp"

Program::Program() = default;

void Program::addProduct()
{
    product.add();

    std::cout << kGreenColor << "\nYou successfully added the product!" << kWhiteColor << "\n";
}

void Program::showAllProducts()
{
    if (isFileEmpty(kFileWithProducts))
    {
        std::cout << kRedColor
                  << "\nError: Product list is empty! Please add a product first (use "
                     "option 1)."
                  << kWhiteColor << "\n";
        return;
    }

    Product::showAll();

    std::cout << kGreenColor << "\nYou successfully printed all products!" << kWhiteColor << "\n";
}

void Program::displayQuantityByYear()
{
    if (isFileEmpty(kFileWithProducts))
    {
        std::cout << kRedColor
                  << "\nError: Product list is empty! Please add a product first (use "
                     "option 1)."
                  << kWhiteColor << "\n";
        return;
    }

    int year = getValue<int>("\nEnter year to search for: ");
    int totalQuantity = Product::getQuantityByYear(year);

    if (totalQuantity == 0)
    {
        std::cout << kRedColor << "\nNo products found for year " << year << "." << kWhiteColor << "\n";
        return;
    }

    std::cout << "\nTotal quantity of products received in " << year << ": " << totalQuantity << "\n";

    std::cout << kGreenColor << "\nYou successfully found total quantity by year!" << kWhiteColor << "\n";
}

void Program::run()
{
    system("clear");

    showTaskMenu();

    int opt = 0;

    while (true)
    {
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
                std::cout << kGreenColor << "\nYou have successfully exited the program." << kWhiteColor << "\n";
                return;
            default:
                std::cout << kRedColor
                          << "\nError, you picked is an incorrect menu option. "
                             "Please try again."
                          << kWhiteColor << "\n";
        }
    }
}