#ifndef BICYCLE_HPP
#define BICYCLE_HPP

#include "transport.hpp"

class Bicycle : public Transport
{
  public:
    using Transport::Transport;
    Bicycle();

    [[nodiscard]] double calculateCost(double distance, double weight) const override;
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override;
    [[nodiscard]] const char *getType() const override;
};

#endif