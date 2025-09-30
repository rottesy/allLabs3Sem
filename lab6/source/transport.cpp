#include "../include/transport.hpp"
#include "../include/const.hpp"
#include "../include/forceFormat.hpp"
#include "../include/utils.hpp"

using namespace std;

Transport::Transport(double speed, double cost, double cap, string regNum)
    : speedPerH(speed), costPerKm(cost), capacity(cap), registrationNumber(std::move(regNum))
{
}

double Transport::calculateTime(double distance) const { return distance / speedPerH; }

double Transport::calculateCost(double distance, double weight) const
{
    if (weight > capacity)
    {
        throw invalid_argument(format("Load capacity exceeded! Capacity: {} kg, requested: {} kg",
                                      to_string(static_cast<int>(capacity)), to_string(static_cast<int>(weight))));
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

void Transport::setRegistrationNumber(const std::string_view &regNum) { registrationNumber = regNum; }

const char *Transport::getType() const { return "Transport vehicle"; }
