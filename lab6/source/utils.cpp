#include "../include/utils.hpp"
#include "../include/const.hpp"
#include "../include/exceptions.hpp"
#include <iostream>

using namespace std;

void inputTransportationDetails(double &distance, double &weight, int &passengers)
{
    cout << "=== Enter Transportation Details ===" << "\n";

    distance = getNumber("Enter distance (km): ");

    if (distance <= 0)
        throw invalid_argument("Distance must be positive");

    weight = getNumber("Enter cargo weight (kg): ");

    if (weight < 0)
        throw invalid_argument("Weight cannot be negative");

    passengers = getNumber("Enter number of passengers: ");

    if (passengers < 0)
        throw invalid_argument("Number of passengers cannot be negative");

    cout << "\n";
}

void demonstrateTransport(const Transport *transport, double distance, double weight, int passengers)
{
    cout << "=== Calculation for " << transport->getType() << " ===" << "\n";
    transport->displayInfo();

    double time = transport->calculateTime(distance);
    cout << "Transportation time for " << distance << " km: " << time << " hours (" << time * 60 << " minutes)" << "\n";

    try
    {
        double cost = transport->calculateCost(distance, weight);
        cout << "Transportation cost for " << weight << " kg: " << cost << " BYN" << "\n";
    }
    catch (const invalid_argument &e)
    {
        cout << "Error calculating cargo cost: " << e.what() << "\n";
    }

    try
    {
        double passengerCost = transport->calculatePassengerCost(distance, passengers);
        cout << "Transportation cost for " << passengers << " passengers: " << passengerCost << " BYN" << "\n";
    }
    catch (const invalid_argument &e)
    {
        cout << "Error calculating passenger cost: " << e.what() << "\n";
    }

    cout << "==============================" << "\n\n";
}

int getNumber(const char *msg)
{
    std::string input;
    std::cout << msg;

    while (true)
    {
        std::getline(std::cin, input);

        bool isValid = true;
        for (size_t i = 0; i < input.length(); ++i)
        {
            if (i == 0 && (input[i] == '-' || input[i] == '+'))
            {
                continue;
            }
            if (!std::isdigit(static_cast<unsigned char>(input[i])))
            {
                isValid = false;
                break;
            }
        }

        if (!isValid || input.empty())
        {
            std::cout << "Error: please enter a valid number without spaces or symbols: ";
            continue;
        }

        try
        {
            int num = std::stoi(input);
            if (num >= MIN_INT && num <= MAX_INT)
            {
                return num;
            }
            std::cout << "Error: number out of range. Please enter between " << MIN_INT << " and " << MAX_INT << ": ";
        }
        catch (const std::exception &)
        {
            std::cout << "Error: invalid number format. Please try again: ";
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
        if (isspace(static_cast<unsigned char>(character)))
        {
            throw InvalidInputException(input, "Must not contain spaces or whitespace characters");
        }
        if (!isdigit(character) && (character < 'a' || character > 'z') && (character < 'A' || character > 'Z'))
        {
            throw InvalidInputException(input, "Must contain only digits (0-9) and latin letters (a-z, A-Z)");
        }
    }
}