#include "../include/program.hpp"
#include "../include/utils.hpp"
#include <iostream>

void choiceRingType()
{
    int choice = 0;

    system("clear");
    std::cout << "\t\t\t\tTASK" << "\n";
    std::cout << "Implement classes Container and Iterator for a one-directional ring." << "\n";
    std::cout << "Implement a class Algorithm that defines methods for searching and sorting." << "\n";

    std::cout << "\nSelect ring element type:" << "\n";
    std::cout << "1. int" << "\n";
    std::cout << "2. long" << "\n";
    std::cout << "3. float" << "\n";
    std::cout << "4. double" << "\n";
    std::cout << "5. char" << "\n";
    std::cout << "6. string" << "\n";

    while (true)
    {
        std::cout << "\nPlease choose a ring type: ";
        choice = getValue<int>();

        switch (choice)
        {
            case 1:
            {
                Program<int> program;
                program.run();
                return;
            }
            case 2:
            {
                Program<long> program;
                program.run();
                return;
            }
            case 3:
            {
                Program<float> program;
                program.run();
                return;
            }
            case 4:
            {
                Program<double> program;
                program.run();
                return;
            }
            case 5:
            {
                Program<char> program;
                program.run();
                return;
            }
            case 6:
            {
                Program<std::string> program;
                program.run();
                return;
            }
            default:
                std::cout << "\033[31m" << "Error, invalid choice. Please try again." << "\033[0m" << "\n";
        }
    }
}