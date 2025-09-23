#ifndef BICYCLE_HPP
#define BICYCLE_HPP

#include "Transport.hpp"

class Bicycle : public Transport
{
  public:
    Bicycle();

    [[nodiscard]] double calculateCost(double distance, double weight) const override;
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override;
    [[nodiscard]] const char *getType() const override;
    
};

#endif