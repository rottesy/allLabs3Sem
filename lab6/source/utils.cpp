#include "../include/utils.hpp"
#include "../include/const.hpp"
#include "../include/exceptions.hpp"
#include <iostream>

using namespace std;

void inputTransportationDetails(double &distance, double &weight, int &passengers)
{
    cout << "=== Enter Transportation Details ===" << "\n";

    distance = getNumber("Enter distance (km): ");

    weight = getNumber("Enter cargo weight (kg): ");

    passengers = getNumber("Enter number of passengers: ");
    cout << "\n";
}


void demonstrateTransport(const Transport *transport, double distance, double weight, int passengers) {
    cout << "=== Calculation for " << transport->getType() << " ===" << "\n";
    transport->displayInfo();

    double time = transport->calculateTime(distance);
    cout << "Transportation time for " << distance << " km: " << time << " hours (" << time * 60 << " minutes)" << "\n";

    try {
        double cost = transport->calculateCost(distance, weight);
        cout << "Transportation cost for " << weight << " kg: " << cost << " BYN" << "\n";
    } catch (const std::exception& e) {
        cout << "Error calculating cargo cost: " << e.what() << "\n";
    }

    try {
        double passengerCost = transport->calculatePassengerCost(distance, passengers);
        cout << "Transportation cost for " << passengers << " passengers: " << passengerCost << " BYN" << "\n";
    } catch (const std::exception& e) {
        cout << "Error calculating passenger cost: " << e.what() << "\n";
    }

    cout << "==============================" << "\n\n";
}

int getNumber(const char *msg)
{
    int num = 0;

    std::cout << msg;

    while (true)
    {
        if (std::cin.peek() == '\n' || std::cin.peek() == ' ' || std::cin.fail())
        {
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "\nError, invalid input. Please try again: ";
            continue;
        }
        if ((std::cin >> num).good() && std::cin.get() == '\n' && (MIN_INT <= num) && (num <= MAX_INT))
        {
            return num;
        }
    }
}

void validateString(const string &input, [[maybe_unused]] const string_view &fieldName)
{
    if (input.empty())
    {
        throw InvalidInputException(input, "Field cannot be empty");
    }

    for (char character : input)
    {
        if (!(isdigit(character) || (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')))
        {
            throw InvalidInputException(input, "Must contain only digits (0-9) and latin letters (a-z, A-Z)");
        }
    }
}