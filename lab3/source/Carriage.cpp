#include "../include/Carriage.hpp"
#include "../include/const.hpp"
#include "../include/utils.hpp"
#include <iostream>

using namespace std;

Carriage::Carriage() : Transport(CARRIAGE_SPEED_IN_KM, CARRIAGE_COST_PER_KM, CARRIAGE_LOAD_CAP) {}

double Carriage::calculateCost(double distance, double weight) const
{
    if (weight > CARRIAGE_LOAD_CAP)
    {
        cout << "A carriage can't carry such a load!" << "\n";
        return -1;
    }
    return distance * CARRIAGE_COST_PER_KM * (weight / WEIGHT_DIVISOR) * NUMBER_OF_HORSES * CARRIAGE_HORSE_FACTOR;
}

double Carriage::calculatePassengerCost(double distance, int passengers) const
{
    return distance * CARRIAGE_COST_PER_KM * passengers * CARRIAGE_PASSENGER_DISCOUNT;
}

const char *Carriage::getType() const { return "Carriage"; }

void Carriage::displayInfo() const
{
    Transport::displayInfo();
    cout << "Number of horses : " << NUMBER_OF_HORSES << "\n";
}
