#include "Car.h"

Car::Car(const char* color, const char* model, size_t manufactureYear, size_t seats, size_t maxSpeed, size_t doorCount, size_t horsePower) : Vechicle(color, model, manufactureYear, seats, maxSpeed)
{
  this->doorCount = doorCount;
  this->horsePower = horsePower;
}

Car::Car(const Car& other) : Vechicle(other)
{
  this->doorCount = other.doorCount;
  this->horsePower = other.horsePower;
}

Car& Car::operator=(const Car& other)
{
  if(this != &other)
  {
    Vechicle::operator=(other);

    this->doorCount = other.doorCount;
    this->horsePower = other.horsePower;
  }

  return *this;
}

Car::~Car() { }

size_t Car::getDoorCount() const
{
  return this->doorCount;
}

size_t Car::getHorsePower() const
{
  return this->horsePower;
}

void Car::setDoorCount(size_t doorCount)
{
  this->doorCount = doorCount;
}

void Car::setHorsePower(size_t horsePower)
{
  this->horsePower = horsePower;
}
