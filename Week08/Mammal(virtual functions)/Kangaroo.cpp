#include "Kangaroo.h"

Kangaroo::Kangaroo() : Mammal(true, 2, 5, NULL, 0, BROWN)
{
}

Kangaroo::Kangaroo(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color) : Mammal(hasFur, numberOfLegs, age, food, foodCount, color)
{
}

Kangaroo::Kangaroo(const Kangaroo& other) : Mammal(other)
{
}

Kangaroo& Kangaroo::operator=(const Kangaroo& other)
{
  if(this != &other)
  {
    Mammal::operator=(other);
  }
  return *this;
}

Kangaroo::~Kangaroo()
{
}

const char* Kangaroo::getSpeciesName() const
{
  return "Kangaroo";
}

bool Kangaroo::canJump() const
{
  return true;
}

bool Kangaroo::canSwim() const
{
  return false;
}

bool Kangaroo::isSameSpeciesLike(Mammal* otherMammal)
{
  return (strcmp(this->getSpeciesName(), otherMammal->getSpeciesName()) == 0);
}
