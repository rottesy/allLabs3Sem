#include "../include/menu.hpp"
#include "../include/bicycle.hpp"
#include "../include/car.hpp"
#include "../include/carriage.hpp"
#include "../include/utils.hpp"
#include <iostream>

using namespace std;

Transport *createTransport()
{
    int choice;
    cout << "=== Select Transport Type ===" << "\n";
    cout << "1. Car" << "\n";
    cout << "2. Bicycle" << "\n";
    cout << "3. Carriage" << "\n";
    choice = getNumber("Enter your choice (1-3): ");

    string regNumber;
    cout << "Enter registration number (digits and latin letters only): ";
    cin >> regNumber;
    validateString(regNumber, "Registration number");

    Transport *transport = nullptr;

    switch (choice)
    {
        case 1:
            transport = new Car(CAR_SPEED_IN_KM, CAR_COST_PER_KM, CAR_LOAD_CAP, regNumber);
            break;
        case 2:
            transport = new Bicycle(BICYCLE_SPEED_IN_KM, BICYCLE_COST_PER_KM, BICYCLE_LOAD_CAP, regNumber);
            break;
        case 3:
            transport = new Carriage(CARRIAGE_SPEED_IN_KM, CARRIAGE_COST_PER_KM, CARRIAGE_LOAD_CAP, regNumber);
            break;
        default:
            cout << "Invalid choice!" << "\n";
            cout << "Using car by default" << "\n";
            transport = new Car(CAR_SPEED_IN_KM, CAR_COST_PER_KM, CAR_LOAD_CAP, regNumber);
            break;
    }

    return transport;
}