#ifndef CAR_HPP
#define CAR_HPP

#include "Transport.hpp"
#include "const.hpp"

class Car : public Transport
{
  private:
    int maxPassengers = kCarMaxPass;

  public:
    using Transport::Transport;
    Car();

    [[nodiscard]] double calculateCost(double distance, double weight) const override;
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
    [[nodiscard]] const char *getType() const override;
    void inputDetails() override;
};

#endif