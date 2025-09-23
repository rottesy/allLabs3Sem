#include "../include/Bicycle.hpp"
#include "../include/const.hpp"
#include <iostream>

using namespace std;

Bicycle::Bicycle() : Transport(BICYCLE_SPEED_IN_KM, BICYCLE_COST_PER_KM, BICYCLE_LOAD_CAP) {}
double Bicycle::calculateCost(double distance, double weight) const
{
    if (weight > BICYCLE_LOAD_CAP)
    {
        cout << "A bicycle can't carry such a load!" << "\n";
        return -1;
    }
    return distance * BICYCLE_COST_PER_KM * (1 + weight / BICYCLE_WEIGHT_FACTOR);
}

double Bicycle::calculatePassengerCost(double distance, int passengers) const
{
    if (passengers > 1)
    {
        cout << "The bicycle can only carry 1 passenger!" << "\n";
        return -1;
    }
    return distance * BICYCLE_COST_PER_KM;
}

const char *Bicycle::getType() const { return "Bicycle"; }
