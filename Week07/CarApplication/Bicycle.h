#pragma once
#include "Vechicle.h"

class Bicycle : public Vechicle
{
  size_t gears;
  bool lights;
  bool bell;
public:
  Bicycle(const char* color = "UnknownColor", const char* model = "UnknownModel", size_t manufactureYear = 0, size_t seats = 0, size_t maxSpeed = 0, size_t gears = 0, bool lights = false, bool bell = false);
  Bicycle(const Bicycle& other);
  Bicycle& operator=(const Bicycle& other);
  ~Bicycle();

  size_t getGears() const;
  bool hasLights() const;
  bool hasBell() const;

  void setGears(size_t gears);
  void setLights(bool lights);
  void setBell(bool bell);
};
