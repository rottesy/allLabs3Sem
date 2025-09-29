#ifndef CARRIAGE_HPP
#define CARRIAGE_HPP

#include "transport.hpp"
#include "const.hpp"

class Carriage : public Transport
{
  private:
    int numberOfHorses = NUMBER_OF_HORSES;

  public:
    using Transport::Transport;
    Carriage();

    [[nodiscard]] double calculateCost(double distance, double weight) const override;
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override;
    void displayInfo() const override;
    [[nodiscard]] const char *getType() const override;
};

#endif