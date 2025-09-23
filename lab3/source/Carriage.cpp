#include "../include/Carriage.hpp"
#include "../include/const.hpp"
#include "../include/utils.hpp"
#include <iostream>

using namespace std;

Carriage::Carriage() : Transport(kCarriageSpeedInKm, kCarriageCostPerKm, kCarriageLoadCap) {}

double Carriage::calculateCost(double distance, double weight) const
{
    if (weight > getCapacity())
    {
        cout << "A carriage can't carry such a load!" << "\n";
        return -1;
    }
    return distance * getCostPerKm() * (weight / WEIGHT_DIVISOR) * kNumberOfHorses * CARRIAGE_HORSE_FACTOR;
}

double Carriage::calculatePassengerCost(double distance, int passengers) const
{
    return distance * getCostPerKm() * passengers * CARRIAGE_PASSENGER_DISCOUNT;
}

const char *Carriage::getType() const { return "Carriage"; }

void Carriage::displayInfo() const {
    cout << "Speed: " << getSpeed() << " km/h" << "\n";
    cout << "Cost per km: " << getCostPerKm() << " BYN" << "\n";
    cout << "Load capacity: " << getCapacity() << " kg" << "\n";
    cout << "Number of horses : " << kNumberOfHorses <<"\n";
}
