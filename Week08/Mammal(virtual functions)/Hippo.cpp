#include "Hippo.h"

Hippo::Hippo() : Mammal(false, 4, 20, NULL, 0, GREY)
{
}

Hippo::Hippo(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color) : Mammal(hasFur, numberOfLegs, age, food, foodCount, color)
{
}

Hippo::Hippo(const Hippo& other) : Mammal(other)
{
}

Hippo& Hippo::operator=(const Hippo& other)
{
  if(this != &other)
  {
    Mammal::operator=(other);
  }
  return *this;
}

Hippo::~Hippo()
{
}

const char* Hippo::getSpeciesName() const
{
  return "Hippo";
}

bool Hippo::canJump() const
{
  return false;
}

bool Hippo::canSwim() const
{
  return true;
}

bool Hippo::isSameSpeciesLike(Mammal* otherMammal)
{
  return (strcmp(this->getSpeciesName(), otherMammal->getSpeciesName()) == 0);
}
