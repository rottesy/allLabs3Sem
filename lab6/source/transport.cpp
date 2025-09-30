#include "../include/transport.hpp"
#include "../include/const.hpp"
#include "../include/utils.hpp"

using namespace std;

Transport::Transport(double speed, double cost, double cap,const string& regNum) : speedPerH(speed), costPerKm(cost), capacity(cap),registrationNumber(regNum) {}

double Transport::calculateTime(double distance) const { return distance / speedPerH; }

double Transport::calculateCost(double distance, double weight) const
{
    if (weight > capacity)
    {
        throw invalid_argument("Load capacity exceeded! Capacity: " + to_string(static_cast<int>(capacity)) + " kg, requested: " + to_string(static_cast<int>(weight)) + " kg");
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
    cout << "Registratiom: " << registrationNumber << "\n";
}

const char *Transport::getType() const { return "Transport vehicle"; }
