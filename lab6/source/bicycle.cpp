#include "../include/bicycle.hpp"
#include "../include/const.hpp"
#include "../include/InvalidInputException.hpp"
#include "../include/forceFormat.hpp"
#include <iostream>


using namespace std;

Bicycle::Bicycle() : Transport(BICYCLE_SPEED_IN_KM, BICYCLE_COST_PER_KM, BICYCLE_LOAD_CAP, BICYCLE_REG_NUMBER) {}
double Bicycle::calculateCost(double distance, double weight) const
{
    if (weight > BICYCLE_LOAD_CAP)
    {
        throw InvalidInputException(format("Carriage can't carry such a load! Capacity: {} kg, requested: {} kg",
                                           std::to_string(static_cast<int>(BICYCLE_LOAD_CAP)),
                                           std::to_string(static_cast<int>(weight))));
    }
    return distance * BICYCLE_COST_PER_KM * (1 + weight / BICYCLE_WEIGHT_FACTOR);
}

double Bicycle::calculatePassengerCost(double distance, int passengers) const
{
    if (passengers > 1)
    {
        throw InvalidInputException(
            format("Bicycle can only carry 1 passenger! Requested: {}", std::to_string(passengers)));
    }
    return distance * BICYCLE_COST_PER_KM;
}

const char *Bicycle::getType() const { return "Bicycle"; }
