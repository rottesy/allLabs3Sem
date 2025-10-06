#pragma once

#include "../include/data.hpp"
#include <string>

class Product
{
    std::string name;
    int quantity = 0;
    double price = 0.0;
    Date receiptDate;

  public:
    Product() = default;

    friend std::ostream &operator<<(std::ostream &ostm, const Product &product)
    {
        ostm << product.name << "|" << product.quantity << " " << product.price << " " << product.receiptDate;

        return ostm;
    }

     friend std::istream &operator>>(std::istream &istm, Product &product) {
        
        std::getline(istm, product.name, '|');
       
        istm >> product.quantity >> product.price >> product.receiptDate;
       
        if (istm.peek() == ' ') {
            istm.ignore();
        }
        return istm;
    }

    void add();
    static void showAll();
    static int getQuantityByYear(int year);
    [[nodiscard]] bool isEmpty() const;
};