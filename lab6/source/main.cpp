#include "../include/exceptions.hpp"
#include "../include/menu.hpp"
#include "../include/utils.hpp"
#include <iostream>


using namespace std;

int main()
{

    try
    {
        double distance = 0;
        double weight = 0;
        int passengers = 0;
        inputTransportationDetails(distance, weight, passengers);

        Transport *transport = createTransport();
        demonstrateTransport(transport, distance, weight, passengers);
        delete transport;
    }
    catch (const invalid_argument &e)
    {
        cout << "=== INPUT ERROR ===" << "\n";
        cout << e.what() << "\n";
        cout << "Program terminated." << "\n";
        return 1;
    }
    catch (const InvalidInputException &e)
    {
        cout << "=== REGISTRATION ERROR ===" << "\n";
        cout << e.what() << "\n";
        cout << "Program terminated." << "\n";
        return 1;
    }

    return 0;
}