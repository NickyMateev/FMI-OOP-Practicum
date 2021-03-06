#pragma once
#include "Mammal.h"

class Hippo : public Mammal
{
  public:
   Hippo();
   Hippo(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color);
   Hippo(const Hippo& other);
   Hippo& operator=(const Hippo& other);
   ~Hippo();

   const char* getSpeciesName() const;
   bool canJump() const;
   bool canSwim() const;
   bool isSameSpeciesLike(Mammal* otherMammal);
};
