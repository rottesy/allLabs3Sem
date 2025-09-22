#include "../include/grandson.hpp"
#include "../include/utils.hpp"
#include <cstring>
#include <iostream>

GrandSon::GrandSon(const char *name, const char *pat) : Kid(name)
{
    patronymic = new char[myStrlen(pat) + 1];
    strcpy_s(patronymic, myStrlen(pat) + 1, pat);
}

GrandSon::~GrandSon() { delete[] patronymic; }

void GrandSon::print() const { std::cout << "GrandSon: " << getName() << " " << patronymic << "\n"; }