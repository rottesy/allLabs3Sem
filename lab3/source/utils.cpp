#include "../include/utils.hpp"
#include "../include/const.hpp"
#include <iostream>

using namespace std;

void inputTransportationDetails(double &distance, double &weight, int &passengers)
{
    cout << "=== Enter Transportation Details ===" << "\n";
    
    distance = getNumber("Enter distance (km): ");
    
    weight = getNumber("Enter cargo weight (kg): ");
    
    passengers = getNumber("Enter number of passengers: ");
    cout << "\n";
}

void demonstrateTransport(const Transport *transport, double distance, double weight, int passengers)
{
    cout << "=== Calculation for " << transport->getType() << " ===" << "\n";
    transport->displayInfo();

    double time = transport->calculateTime(distance);
    cout << "Transportation time for " << distance << " km: " << time << " hours (" << time * 60 << " minutes)" << "\n";

    if (double cost = transport->calculateCost(distance, weight); cost >= 0)
    {
        cout << "Transportation cost for " << weight << " kg: " << cost << " BYN" << "\n";
    }

    if (double passengerCost = transport->calculatePassengerCost(distance, passengers); passengerCost >= 0)
    {
        cout << "Transportation cost for " << passengers << " passengers: " << passengerCost << " BYN" << "\n";
    }

    cout << "==============================" << "\n\n";
}

int getNumber(const char *msg)
{
    int num = 0;

    std::cout << msg;

    while (true)
    {
        if (std::cin.peek() == '\n' || std::cin.peek() == ' ' || std::cin.fail())
        {
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "\nError, invalid input. Please try again: ";
            continue;
        }
        if ((std::cin >> num).good() && std::cin.get() == '\n' && (kMinInt <= num) && (num <= kMaxInt))
        {
            return num;
        }
    }
}