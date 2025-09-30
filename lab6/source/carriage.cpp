#include "../include/carriage.hpp"
#include "../include/const.hpp"
#include "../include/utils.hpp"
#include <iostream>

using namespace std;

Carriage::Carriage() : Transport(CARRIAGE_SPEED_IN_KM, CARRIAGE_COST_PER_KM, CARRIAGE_LOAD_CAP, CARRIAGE_REG_NUMBER) {}

double Carriage::calculateCost(double distance, double weight) const
{
    if (weight > CARRIAGE_LOAD_CAP)
    {
        throw std::invalid_argument(
            "Carriage can't carry such a load! Capacity: " + std::to_string(static_cast<int>(CARRIAGE_LOAD_CAP)) +
            " kg, requested: " + std::to_string(static_cast<int>(weight)) + " kg");
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
