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
        cout << "A car can't carry such a load!!" << "\n";
        return -1;
    }
    return distance * CAR_COST_PER_KM * (1 + weight / CAR_WEIGHT_FACTOR);
}

double Car::calculatePassengerCost(double distance, int passengers) const
{
    if (passengers > CAR_MAX_PASS)
    {
        cout << "A car can't carry that many passengers." << "\n";
        return -1;
    }
    return distance * CAR_COST_PER_KM * passengers;
}

const char *Car::getType() const { return "Car"; }

void Car::displayInfo() const
{
    Transport::displayInfo();
    cout << "Max pass: " << CAR_MAX_PASS << "\n";
}