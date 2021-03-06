#pragma once
#include "Mammal.h"

class Dog : public Mammal
{
  public:
    Dog();
    Dog(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    const char* getSpeciesName() const;
    bool canJump() const;
    bool canSwim() const;
    bool isSameSpeciesLike(Mammal* otherMammal);
};
