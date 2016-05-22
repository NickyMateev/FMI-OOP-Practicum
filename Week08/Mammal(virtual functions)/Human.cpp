#include "Human.h"

Human::Human() : Mammal(false, 2, 2, NULL, 0, WHITE)
{
}

Human::Human(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color) : Mammal(hasFur, numberOfLegs, age, food, foodCount, color)
{
}

Human::Human(const Human& other) : Mammal(other)
{
}

Human& Human::operator=(const Human& other)
{
  if(this != &other)
  {
    Mammal::operator=(other);
  }
  return *this;
}

Human::~Human()
{
}

const char* Human::getSpeciesName() const
{
  return "Human";
}

bool Human::canJump() const
{
  return true;
}

bool Human::canSwim() const
{
  return true;
}

bool Human::isSameSpeciesLike(Mammal* otherMammal)
{
  return (strcmp(this->getSpeciesName(), otherMammal->getSpeciesName()) == 0);
}
