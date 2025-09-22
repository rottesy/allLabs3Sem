#include "../include/familyprogram.hpp"
#include "../include/ancestor.hpp"
#include "../include/grandson.hpp"
#include "../include/kid.hpp"
#include "../include/utils.hpp"
#include <iostream>

void FamilyProgram::expandMembers()
{
    size = std::max(size, 0);
    if (size + 1 == capacity)
    {
        capacity *= 2;
        auto **newMembers = new Ancestor *[capacity];
        for (int i = 0; i < size; i++)
        {
            newMembers[i] = familyMemebrs[i];
        }
        delete[] familyMemebrs;
        familyMemebrs = newMembers;
    }
    size++;
}

void FamilyProgram::addMember()
{
    expandMembers();

    std::cout << "\n=== ADD FAMILY MEMBER ===" << "\n";
    std::cout << "1. Add Kid" << "\n";
    std::cout << "2. Add GrandSon" << "\n";

    int opt = getNumber("Choose type: ");

    auto *name = new char[100];
    std::cout << "Enter name: ";
    std::cin.getline(name, 100);

    if (myStrlen(name) == 0)
    {
        std::cout << "Error: Name cannot be empty!" << "\n";
        size--;
        return;
    }

    switch (opt)
    {
        case 1:
            familyMemebrs[size - 1] = new Kid(name);
            delete[] name;
            break;

        case 2:
        {
            auto *patronymic = new char[100];
            std::cout << "Enter patronymic: ";
            std::cin.getline(patronymic, 100);

            familyMemebrs[size - 1] = new GrandSon(name, patronymic);
            delete[] name;
            delete[] patronymic;
            break;
        }

        default:
            delete[] name;
            size--;
            std::cout << "Error: Invalid option!!" << "\n";
            break;
    }
}

// FamilyProgram::~FamilyProgram() { clear(); }

void FamilyProgram::addFamilyMember() { addMember(); }

void FamilyProgram::showAllMembers() const
{
    if (size == 0)
    {
        std::cout << "No family members!" << "\n";
        return;
    }
    std::cout << "\n=== FAMILY MEMBERS ===" << "\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". ";
        familyMemebrs[i]->print();
    }
}

void FamilyProgram::clear()
{
    for (int i = 0; i < size; i++)
    {
        delete familyMemebrs[i];
    }
    delete[] familyMemebrs;
    familyMemebrs = nullptr;
    size = capacity = 0;
}

void FamilyProgram::run()
{
    while (true)
    {
        std::cout << "\n=== FAMILY TREE ===" << "\n";
        std::cout << "1. Add member" << "\n";
        std::cout << "2. Show members" << "\n";
        std::cout << "3. Exit" << "\n";

        int opt = getNumber("Choose option: ");

        switch (opt)
        {
            case 1:
                addFamilyMember();
                break;
            case 2:
                showAllMembers();
                break;
            case 3:
                std::cout << "Goodbye!" << "\n";
                return;
            default:
                std::cout << "Error: Invalid menu option!" << "\n";
                break;
        }
    }
}