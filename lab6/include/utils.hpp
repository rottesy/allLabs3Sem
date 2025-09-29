#ifndef UTILS_HPP
#define UTILS_HPP

#include "transport.hpp"

void inputTransportationDetails(double &distance, double &weight, int &passengers);
void demonstrateTransport(const Transport *transport, double distance, double weight, int passengers);
int getNumber(const char *msg);
void validateString(const std::string& input, const std::string& fieldName);

#endif