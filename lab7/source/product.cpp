#include "../include/product.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "../include/consts.hpp"
#include "../include/utils.hpp"

void Product::add()
{
    Product tmp;

    std::cout << "\n=== Adding New Product ===" << "\n";

    tmp.name = getValue<std::string>("Enter product name: ");

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

void Product::showAll() {
    std::ifstream fileIn;
    fileIn.open(kFileWithProducts);

    Product tmp;

    if (!isValidFileOpen(fileIn, kFileWithProducts)) {
        return;
    }

    std::cout << "\n\t\t\t\tPRODUCTS LIST" << "\n";
    
   
    std::cout << std::left 
              << std::setw(25) << std::setfill(' ') << "Name" 
              << std::setw(12) << std::setfill(' ') << "Quantity" 
              << std::setw(12) << std::setfill(' ') << "Price" 
              << std::setw(15) << std::setfill(' ') << "Receipt Date" << "\n";
    std::cout << "------------------------------------------------------------" << "\n";

    while (fileIn >> tmp) {
        
        std::cout << std::left 
                  << std::setw(25) << std::setfill(' ') << (tmp.name.length() > 24 ? tmp.name.substr(0, 22) + ".." : tmp.name)
                  << std::setw(12) << std::setfill(' ') << tmp.quantity 
                  << std::setw(12) << std::setfill(' ') << tmp.price 
                  << std::setw(15) << std::setfill(' ') << tmp.receiptDate << "\n";
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