#pragma once

#include "product.hpp"

class Program
{
    Product product;

    void addProduct();
    void showAllProducts() const;
    void displayQuantityByYear() const;

  public:
    Program();

    void run();
};