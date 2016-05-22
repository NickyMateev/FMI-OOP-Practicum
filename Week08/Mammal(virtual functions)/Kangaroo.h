#pragma once
#include "Mammal.h"

class Kangaroo : public Mammal
{
  public:
    Kangaroo();
    Kangaroo(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color);
    Kangaroo(const Kangaroo& other);
    Kangaroo& operator=(const Kangaroo& other);
    ~Kangaroo();

    const char* getSpeciesName() const;
    bool canJump() const;
    bool canSwim() const;
    bool isSameSpeciesLike(Mammal* otherMammal);
};
