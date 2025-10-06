#pragma once

#include "product.hpp"

class Program
{
    Product product;

    void addProduct();
    static void showAllProducts();
    static void displayQuantityByYear();

  public:
    Program();

    void run();
};