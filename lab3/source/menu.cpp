#include "../include/menu.hpp"
#include "../include/Bicycle.hpp"
#include "../include/Car.hpp"
#include "../include/Carriage.hpp"
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
    }

    return transport;
}