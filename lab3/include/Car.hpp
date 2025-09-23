#ifndef CAR_HPP
#define CAR_HPP

#include "Transport.hpp"
#include "const.hpp"

class Car : public Transport
{
  private:
    int maxPassengers = CAR_MAX_PASS;

  public:
    using Transport::Transport;
    Car();

    [[nodiscard]] double calculateCost(double distance, double weight) const override;
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override;
    [[nodiscard]] const char *getType() const override;
    void displayInfo() const override;
};

#endif