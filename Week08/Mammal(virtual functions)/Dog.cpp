#include "Dog.h"

Dog::Dog() : Mammal(true, 4, 5, NULL, 0, BROWN)
{
}

Dog::Dog(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color) : Mammal(hasFur, numberOfLegs, age, food, foodCount, color)
{
}

Dog::Dog(const Dog& other) : Mammal(other)
{
}

Dog& Dog::operator=(const Dog& other)
{
  if(this != &other)
  {
    Mammal::operator=(other);
  }
  return *this;
}

Dog::~Dog()
{
}

const char* Dog::getSpeciesName() const
{
  return "Dog";
}

bool Dog::canJump() const
{
  return true;
}

bool Dog::canSwim() const
{
  return true;
}

bool Dog::isSameSpeciesLike(Mammal* otherMammal)
{
  return (strcmp(this->getSpeciesName(), otherMammal->getSpeciesName()) == 0);
}
