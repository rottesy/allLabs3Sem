#include "../include/kid.hpp"
#include <iostream>

Kid::Kid(const char *name) : Ancestor(name) {}

void Kid::print() const { std::cout << "Kid: " << getName() << "\n"; }