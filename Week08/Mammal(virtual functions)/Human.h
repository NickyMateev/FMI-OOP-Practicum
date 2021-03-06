#pragma once
#include "Mammal.h"

class Human : public Mammal
{
  public:
    Human();
    Human(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color);
    Human(const Human& other);
    Human& operator=(const Human& other);
    ~Human();

    const char* getSpeciesName() const;
    bool canJump() const;
    bool canSwim() const;
    bool isSameSpeciesLike(Mammal* otherMammal);
};
