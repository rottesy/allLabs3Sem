#ifndef CAR_HPP
#define CAR_HPP

#include "Transport.hpp"

class Car : public Transport
{
  private:
    int maxPassengers;

  public:
    using Transport::Transport;
    Car(double speed, double cost, double cap, int maxPass);

    [[nodiscard]] double calculateCost(double distance, double weight) const override;
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
    [[nodiscard]] const char *getType() const override;
    void inputDetails() override;
};

#endif