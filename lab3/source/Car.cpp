#include "../include/Car.hpp"
#include "../include/const.hpp"
#include "../include/utils.hpp"
#include "iostream"

using namespace std;

Car::Car() : Transport(kCarSpeedInKm, kCarCostPerKm, kCarLoadCap) {}

double Car::calculateCost(double distance, double weight) const
{
    if (weight > kCarLoadCap)
    {
        cout << "A car can't carry such a load!!" << "\n";
        return -1;
    }
    return distance * kCarCostPerKm * (1 + weight / CAR_WEIGHT_FACTOR);
}

double Car::calculatePassengerCost(double distance, int passengers) const
{
    if (passengers > kCarMaxPass)
    {
        cout << "A car can't carry that many passengers." << "\n";
        return -1;
    }
    return distance * kCarCostPerKm * passengers;
}

const char *Car::getType() const { return "Car"; }

void Car::displayInfo() const{
    Transport::displayInfo();
    cout << "Max pass: " << kCarMaxPass << "\n";
}