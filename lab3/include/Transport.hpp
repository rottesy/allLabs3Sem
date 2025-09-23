#ifndef TRANSPORT_HPP
#define TRANSPORT_HPP

#include <iostream>

class Transport
{
  private:
    double speedPerH;
    double costPerKm;
    double capacity;

  public:
    Transport(double speed, double cost, double cap);
    virtual ~Transport() = default;

    [[nodiscard]] virtual double calculateTime(double distance) const;
    [[nodiscard]] virtual double calculateCost(double distance, double weight) const;
    [[nodiscard]] virtual double calculatePassengerCost(double distance, int passengers) const;
    virtual void displayInfo() const;
    [[nodiscard]] virtual const char *getType() const;
};

#endif