#pragma once
#include "Vechicle.h"

class Car : Vechicle
{
  size_t doorCount;
  size_t horsePower;
public:
  Car(const char* color = "UnknownColor", const char* model = "UnknownModel", size_t manufactureYear = 0, size_t seats = 0, size_t maxSpeed = 0, size_t doorCount = 0, size_t horsePower = 0);
  Car(const Car& other);
  Car& operator=(const Car& other);
  ~Car();

  size_t getDoorCount() const;
  size_t getHorsePower() const;

  void setDoorCount(size_t doorCount);
  void setHorsePower(size_t horsePower);
};
