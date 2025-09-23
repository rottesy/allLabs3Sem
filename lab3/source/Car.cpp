#include "../include/Car.hpp"
#include "../include/const.hpp"
#include "../include/utils.hpp"
#include "iostream"

using namespace std;

Car::Car(double speed, double cost, double cap, int maxPass) : Transport(speed, cost, cap), maxPassengers(maxPass) {}

double Car::calculateCost(double distance, double weight) const
{
    if (weight > getCapacity())
    {
        cout << "A car can't carry such a load!!" << "\n";
        return -1;
    }
    return distance * getCostPerKm() * (1 + weight / CAR_WEIGHT_FACTOR);
}

double Car::calculatePassengerCost(double distance, int passengers) const
{
    if (passengers > maxPassengers)
    {
        cout << "A car can't carry that many passengers." << "\n";
        return -1;
    }
    return distance * getCostPerKm() * passengers;
}

void Car::displayInfo() const
{
    cout << "Type: Car" << "\n";
    Transport::displayInfo();
    cout << "Max number of passengers: " << maxPassengers << "\n";
    cout << "===" << "\n";
}

const char *Car::getType() const { return "Car"; }

void Car::inputDetails()
{
    Transport::inputDetails();
    maxPassengers = getNumber("Enter max number of passengers : ");
}