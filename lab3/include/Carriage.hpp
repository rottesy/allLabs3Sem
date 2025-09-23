#ifndef CARRIAGE_HPP
#define CARRIAGE_HPP

#include "Transport.hpp"
#include "const.hpp"

class Carriage : public Transport
{
  private:
    int numberOfHorses = kNumberOfHorses;

  public:
    using Transport::Transport;
    Carriage();

    [[nodiscard]] double calculateCost(double distance, double weight) const override;
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
    [[nodiscard]] const char *getType() const override;
    void inputDetails() override;
};

#endif