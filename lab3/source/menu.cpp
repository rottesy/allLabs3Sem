#include "../include/menu.hpp"
#include "../include/Bicycle.hpp"
#include "../include/Car.hpp"
#include "../include/Carriage.hpp"
#include <iostream>

using namespace std;

Transport *createTransport()
{
    int choice;
    cout << "=== Select Transport Type ===" << "\n";
    cout << "1. Car" << "\n";
    cout << "2. Bicycle" << "\n";
    cout << "3. Carriage" << "\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    Transport *transport = nullptr;

    switch (choice)
    {
        case 1:
            transport = new Car(0, 0, 0, 0);
            break;
        case 2:
            transport = new Bicycle(0, 0, 0);
            break;
        case 3:
            transport = new Carriage(0, 0, 0, 0);
            break;
        default:
            cout << "Invalid choice! Using default transport." << "\n";
            transport = new Transport(0, 0, 0);
    }

    cout << "\nEnter details for " << transport->getType() << ":\n";
    transport->inputDetails();
    cout << "\n";

    return transport;
}