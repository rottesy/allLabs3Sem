#include "../include/Bicycle.hpp"
#include "../include/const.hpp"
#include <iostream>

using namespace std;

Bicycle::Bicycle() : Transport(kBicycleSpeedInKm,kBicycleCostPerKm,kBicycleLoadCap) {}
double Bicycle::calculateCost(double distance, double weight) const
{
    if (weight > getCapacity())
    {
        cout << "A bicycle can't carry such a load!" << "\n";
        return -1;
    }
    return distance * getCostPerKm() * (1 + weight / BICYCLE_WEIGHT_FACTOR);
}

double Bicycle::calculatePassengerCost(double distance, int passengers) const
{
    if (passengers > 1)
    {
        cout << "The bicycle can only carry 1 passenger!" << "\n";
        return -1;
    }
    return distance * getCostPerKm();
}

void Bicycle::displayInfo() const
{
    cout << "Type: Bicycle" << "\n";
    Transport::displayInfo();
    cout << "===" << "\n";
}

const char *Bicycle::getType() const { return "Bicycle"; }