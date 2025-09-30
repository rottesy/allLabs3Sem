#ifndef TRANSPORT_HPP
#define TRANSPORT_HPP

#include <iostream>
#include <string>

class Transport
{
  private:
    double speedPerH;
    double costPerKm;
    double capacity;
    std::string registrationNumber;

  public:
    Transport(double speed, double cost, double cap, const std::string &regNum);
    virtual ~Transport() = default;

    [[nodiscard]] virtual double calculateTime(double distance) const;
    [[nodiscard]] virtual double calculateCost(double distance, double weight) const;
    [[nodiscard]] virtual double calculatePassengerCost(double distance, int passengers) const;
    virtual void displayInfo() const;
    [[nodiscard]] virtual const char *getType() const;

    [[nodiscard]] std::string getRegistrationNumber() const { return registrationNumber; }
    void setRegistrationNumber(const std::string& regNum);
};

#endif