#pragma once
#include "algorithm.hpp"
#include "ring.hpp"
#include "utils.hpp"
#include "exceptions.hpp"
#include <iostream>

template <typename T>
class Program {
    Ring<T> ring;
    Algorithm<T> algorithm;

    void createRing();
    void addRingElement();
    void removeRingElement();
    void showRing();
    void sortRing();
    void searchRingElement();
    void clearRing();
    void demonstrateAlgorithms();

public:
    Program();
    void run();
};

template <typename T>
Program<T>::Program() {
    std::cout << "\033[32m" << "You successfully chose a type for ring!" << "\033[0m" << std::endl;
}

template <typename T>
void Program<T>::createRing() {
    if (!ring.empty()) {
        std::cout << "\033[31m" << "Error, ring is already created!" << "\033[0m" << std::endl;
        return;
    }

    std::cout << "Enter number of elements: ";
    auto count = getValue<size_t>();

    for (size_t i = 0; i < count; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        T value = getValue<T>();
        ring.push_back(value);
    }

    std::cout << "\033[32m" << "Ring created successfully!" << "\033[0m" << std::endl;
}

template <typename T>
void Program<T>::addRingElement() {
    std::cout << "Enter value to add: ";
    auto value = getValue<T>();

    int opt = 0;
    showAddMenu();

    while (true) {
        std::cout << "Please enter the add menu option: ";
        opt = getValue<int>();

        switch (opt) {
            case 1:
                ring.push_front(value);
                std::cout << "\033[32m" << "Element added to front!" << "\033[0m" << std::endl;
                return;
            case 2:
                ring.push_back(value);
                std::cout << "\033[32m" << "Element added to back!" << "\033[0m" << std::endl;
                return;
            default:
                std::cout << "\033[31m" << "Wrong choice, please try again!" << "\033[0m" << std::endl;
        }
    }
}

template <typename T>
void Program<T>::removeRingElement() {
    if (ring.empty()) {
        std::cout << "\033[31m" << "Error, ring is empty." << "\033[0m" << std::endl;
        return;
    }

    int opt = 0;
    showRemoveMenu();

    while (true) {
        std::cout << "Please enter the remove menu option: ";
        opt = getValue<int>();

        switch (opt) {
            case 1:
                ring.pop_front();
                std::cout << "\033[32m" << "Front element removed!" << "\033[0m" << std::endl;
                return;
            case 2:
                ring.pop_back();
                std::cout << "\033[32m" << "Back element removed!" << "\033[0m" << std::endl;
                return;
            default:
                std::cout << "\033[31m" << "Wrong choice, please try again!" << "\033[0m" << std::endl;
        }
    }
}

template <typename T>
void Program<T>::showRing() {
    if (ring.empty()) {
        std::cout << "\033[31m" << "Ring is empty." << "\033[0m" << std::endl;
        return;
    }

    std::cout << "Ring elements: ";
    
    
    auto it = ring.begin();
    for (size_t i = 0; i < ring.getSize(); i++) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << "\033[32m" << "You have successfully displayed the ring elements!" << "\033[0m" << std::endl;
}

template <typename T>
void Program<T>::sortRing() {
    if (ring.empty()) {
        std::cout << "\033[31m" << "Error, ring is empty." << "\033[0m" << std::endl;
        return;
    }

    try {
        algorithm.sort(ring);
        std::cout << "\033[32m" << "Ring sorted successfully!" << "\033[0m" << std::endl;
    } catch (const RingException& e) {
        std::cout << "\033[31m" << "Sorting error: " << e.what() << "\033[0m" << std::endl;
    }
}

template <typename T>
void Program<T>::searchRingElement() {
    if (ring.empty()) {
        std::cout << "\033[31m" << "Error, ring is empty." << "\033[0m" << std::endl;
        return;
    }

    std::cout << "Enter value to search: ";
    auto value = getValue<T>();

    try {
        if (algorithm.find(ring, value)) {
            std::cout << "\033[32m" << "Element found!" << "\033[0m" << std::endl;
        } else {
            std::cout << "\033[31m" << "Element not found." << "\033[0m" << std::endl;
        }
    } catch (const RingException& e) {
        std::cout << "\033[31m" << "Search error: " << e.what() << "\033[0m" << std::endl;
    }
}

template <typename T>
void Program<T>::clearRing() {
    if (ring.empty()) {
        std::cout << "\033[31m" << "Ring is already empty." << "\033[0m" << std::endl;
        return;
    }

   
    ring.clear();
    std::cout << "\033[32m" << "Ring cleared successfully!" << "\033[0m" << std::endl;
}



template <typename T>
void Program<T>::run() {
    showMenu();

    int opt = 0;

    while (true) {
        std::cout << "Please enter menu option: ";
        opt = getValue<int>();

        switch (opt) {
            case 1:
                createRing();
                break;
            case 2:
                addRingElement();
                break;
            case 3:
                removeRingElement();
                break;
            case 4:
                showRing();
                break;
            case 5:
                sortRing();
                break;
            case 6:
                searchRingElement();
                break;
            case 7:
                clearRing();
                break;
            
            case 9:
                std::cout << "\033[32m" << "Program exited successfully." << "\033[0m" << std::endl;
                return;
            default:
                std::cout << "\033[31m" << "Invalid option. Try again." << "\033[0m" << std::endl;
        }
    }
}