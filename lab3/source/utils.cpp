#include "../include/utils.hpp"
#include <iostream>

using namespace std;

void inputTransportationDetails(double &distance, double &weight, int &passengers)
{
    cout << "=== Enter Transportation Details ===" << "\n";
    cout << "Enter distance (km): ";
    cin >> distance;
    cout << "Enter cargo weight (kg): ";
    cin >> weight;
    cout << "Enter number of passengers: ";
    cin >> passengers;
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

    cout << "=============================" << "\n\n";
}