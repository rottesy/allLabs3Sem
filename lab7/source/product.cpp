#include "../include/product.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "../include/consts.hpp"
#include "../include/utils.hpp"

void Product::add()
{
    Product tmp;

    std::cout << "\n=== Adding New Product ===" << std::endl;

    std::cout << "Enter product name: ";
    std::cin.ignore();
    std::getline(std::cin, tmp.name);

    tmp.quantity = getValue<int>("Enter product quantity: ");

    tmp.price = getValue<double>("Enter product price: ");

    tmp.receiptDate.input();

    std::ofstream fileOut;
    fileOut.open(kFileWithProducts, std::ios::app);

    if (!isValidFileOpen(fileOut, kFileWithProducts))
    {
        return;
    }

    fileOut << tmp << " ";

    fileOut.close();

    *this = tmp;
}

void Product::showAll()
{
    std::ifstream fileIn;
    fileIn.open(kFileWithProducts);

    Product tmp;

    if (!isValidFileOpen(fileIn, kFileWithProducts))
    {
        return;
    }

    std::cout << "\n\t\t\t\tPRODUCTS LIST" << std::endl;
    std::cout << "Name\t\tQuantity\tPrice\t\tReceipt Date" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    while (fileIn >> tmp)
    {

        std::cout << tmp.name << "\t\t" << tmp.quantity << "\t\t" << tmp.price << "\t\t" << tmp.receiptDate
                  << std::endl;
    }

    fileIn.close();
}

int Product::getQuantityByYear(int year)
{
    std::ifstream fileIn;
    fileIn.open(kFileWithProducts);

    Product tmp;
    int totalQuantity = 0;

    if (!isValidFileOpen(fileIn, kFileWithProducts))
    {
        return 0;
    }

    while (fileIn >> tmp)
    {
        if (tmp.receiptDate.getYear() == year)
        {
            totalQuantity += tmp.quantity;
        }
    }

    fileIn.close();
    return totalQuantity;
}

bool Product::isEmpty() const { return (name.empty() && quantity == 0 && price == 0.0 && receiptDate.isEmpty()); }