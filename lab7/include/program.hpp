#pragma once

#include "product.hpp"

class Program
{
    Product product;

    static void addProduct();
    static void showAllProducts();
    static void displayQuantityByYear();

  public:
    Program();

    static void run();
};