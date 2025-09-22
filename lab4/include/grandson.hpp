#ifndef GRANDSON_HPP
#define GRANDSON_HPP

#include "kid.hpp"

class GrandSon : public Kid
{
  private:
    char *patronymic = nullptr;

  public:
    GrandSon(const char *name, const char *pat);
    ~GrandSon() override;
    void print() const override;
};

#endif