#include "../include/menu.hpp"
#include "../include/utils.hpp"
#include <iostream>


using namespace std;

int main()
{
    double distance = 0;
    double weight = 0;
    int passengers = 0;
    inputTransportationDetails(distance, weight, passengers);

    Transport *transport = createTransport();

    demonstrateTransport(transport, distance, weight, passengers);

    delete transport;

    return 0;
}