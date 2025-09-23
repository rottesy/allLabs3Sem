#ifndef UTILS_HPP
#define UTILS_HPP

#include "Transport.hpp"

void inputTransportationDetails(double &distance, double &weight, int &passengers);
void demonstrateTransport(const Transport *transport, double distance, double weight, int passengers);
int getNumber(const char *msg);

#endif