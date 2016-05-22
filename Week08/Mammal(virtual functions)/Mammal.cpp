#include "Mammal.h"

const bool DEFAULT_CAN_JUMP = false;
const bool DEFAULT_CAN_SWIM = false;

Mammal::Mammal()
{
  food = NULL;
  foodCount = 0;
  color = BROWN;
  hasFur = true;
  numberOfLegs = 0;
  age = 0;
}

Mammal::Mammal(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color)
{
  this->hasFur = hasFur;
  this->numberOfLegs = numberOfLegs;
  this->age = age;
  this->color = color;
  this->food = new Food[foodCount];
  this->foodCount = foodCount;

  for(int i = 0; i < foodCount; i++)
    this->food[i] = food[i];
}

Mammal::Mammal(const Mammal& other)
{
  this->hasFur = other.hasFur;
  this->numberOfLegs = other.numberOfLegs;
  this->age = other.age;
  this->color = other.color;
  this->food = new Food[other.foodCount];
  this->foodCount = other.foodCount;

  for(int i = 0; i < other.foodCount; i++)
    this->food[i] = other.food[i];
}

Mammal& Mammal::operator=(const Mammal& other)
{
  if(this != &other)
  {
    delete[] this->food;

    this->hasFur = other.hasFur;
    this->numberOfLegs = other.numberOfLegs;
    this->age = other.age;
    this->color = other.color;
    this->food = new Food[other.foodCount];
    this->foodCount = other.foodCount;

    for(int i = 0; i < other.foodCount; i++)
      this->food[i] = other.food[i];
  }
  return *this;
}

Mammal::~Mammal()
{
  delete[] this->food;
}

bool Mammal::hasFurFunction() const
{
  return hasFur;
}

unsigned Mammal::getNumberOfLegs() const
{
  return numberOfLegs;
}

unsigned Mammal::getAge() const
{
  return age;
}

void Mammal::setFur(bool hasFur)
{
  this->hasFur = hasFur;
}

void Mammal::setNumberOfLegs(unsigned numberOfLegs)
{
  this->numberOfLegs = numberOfLegs;
}

void Mammal::setAge(unsigned age)
{
  this->age = age;
}

const char* Mammal::getSpeciesName() const
{
  return "Mammals";
}

bool Mammal::eats(Food food) const
{
  for(int i = 0; i < this->foodCount; i++)
    if(this->food[i] == food)
      return true;

  return false;
}

Color Mammal::furColor() const
{
  return color;
}

bool Mammal::canJump() const
{
  return DEFAULT_CAN_JUMP;
}

bool Mammal::canSwim() const
{
  return DEFAULT_CAN_SWIM;
}

bool Mammal::isSameSpeciesLike(Mammal* otherMammal)
{
  return (strcmp(this->getSpeciesName(), otherMammal->getSpeciesName()) == 0);
}

