#ifndef KID_HPP
#define KID_HPP

#include "ancestor.hpp"

class Kid : public Ancestor
{
  public:
    explicit Kid(const char *name);
    void print() const override;
};

#endif