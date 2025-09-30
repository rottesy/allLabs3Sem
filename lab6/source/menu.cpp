#include "../include/menu.hpp"
#include "../include/bicycle.hpp"
#include "../include/car.hpp"
#include "../include/carriage.hpp"
#include "../include/utils.hpp"
#include <iostream>

using namespace std;

Transport *createTransport()
{
    string regNumber;
    cout << "Enter registration number (digits and latin letters only): ";
    cin >> regNumber;
    validateString(regNumber, "Registration number");
    getchar();
    int choice;
    cout << "=== Select Transport Type ===" << "\n";
    cout << "1. Car" << "\n";
    cout << "2. Bicycle" << "\n";
    cout << "3. Carriage" << "\n";
    choice = getNumber("Enter your choice (1-3): ");

    Transport *transport = nullptr;

    switch (choice)
    {
        case 1:
            transport = new Car;
            break;
        case 2:
            transport = new Bicycle;
            break;
        case 3:
            transport = new Carriage;
            break;
        default:
            cout << "Invalid choice!" << "\n";
            cout << "Using car by default" << "\n";
            transport = new Car;
            break;
    }

    transport->setRegistrationNumber(regNumber);

    return transport;
}