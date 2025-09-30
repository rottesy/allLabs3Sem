#include "../include/car.hpp"
#include "../include/const.hpp"
#include "../include/utils.hpp"
#include "iostream"

using namespace std;

Car::Car() : Transport(CAR_SPEED_IN_KM, CAR_COST_PER_KM, CAR_LOAD_CAP, CAR_REG_NUMBER) {}

double Car::calculateCost(double distance, double weight) const
{
    if (weight > CAR_LOAD_CAP)
    {
        throw std::invalid_argument(
            "Car can't carry such a load! Capacity: " + std::to_string(static_cast<int>(CAR_LOAD_CAP)) +
            " kg, requested: " + std::to_string(static_cast<int>(weight)) + " kg");
    }
    return distance * CAR_COST_PER_KM * (1 + weight / CAR_WEIGHT_FACTOR);
}

double Car::calculatePassengerCost(double distance, int passengers) const
{
    if (passengers > CAR_MAX_PASS)
    {
        throw std::invalid_argument("Car can't carry that many passengers! Max: 5, requested: " +
                                    std::to_string(passengers));
    }

    return distance * CAR_COST_PER_KM * passengers;
}

const char *Car::getType() const { return "Car"; }

void Car::displayInfo() const
{
    Transport::displayInfo();
    cout << "Max pass: " << CAR_MAX_PASS << "\n";
}