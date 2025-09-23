#include "../include/Transport.hpp"
#include "../include/const.hpp"
#include "../include/utils.hpp"

using namespace std;

Transport::Transport(double speed, double cost, double cap) : speedPerH(speed), costPerKm(cost), capacity(cap) {}

double Transport::getSpeed() const { return speedPerH; }

double Transport::getCostPerKm() const { return costPerKm; }

double Transport::getCapacity() const { return capacity; }

double Transport::calculateTime(double distance) const { return distance / speedPerH; }

double Transport::calculateCost(double distance, double weight) const
{
    if (weight > capacity)
    {
        cout << "Attention: the load capacity has been exceeded!" << "\n";
        return -1;
    }
    return distance * costPerKm * (weight / WEIGHT_DIVISOR);
}

double Transport::calculatePassengerCost(double distance, int passengers) const
{
    return distance * passengers * costPerKm;
}

void Transport::displayInfo() const
{
    cout << "Speed: " << speedPerH << " km/h" << "\n";
    cout << "Cost per km: " << costPerKm << " BYN" << "\n";
    cout << "Load capacity: " << capacity << " kg" << "\n";
}

const char *Transport::getType() const { return "Transport vehicle"; }

void Transport::inputDetails()
{
    
    speedPerH = getNumber("Enter speed (km/h): ");
    
    costPerKm = getNumber("Enter cost per km (BYN): ");
    
    capacity = getNumber("Enter load capacity (kg): ");
}