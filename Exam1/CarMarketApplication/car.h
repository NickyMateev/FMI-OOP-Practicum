#pragma once
#include <iostream>
using namespace std;

class Car
{
  char* brand;
  char* model;
  char* color;
  int manufactureYear;
public:
  Car();
  Car(const char* brand, const char* model, const char* color, int manufactureYear);
  Car(const Car& other);
  Car& operator=(const Car& other);
  ~Car();

  const char* getBrand() const;
  const char* getModel() const;
  const char* getColor() const;
  int getManufactureYear() const;

  void setBrand(const char*& newBrand);
  void setModel(const char*& newModel);
  void setColor(const char*& newColor);
  void setManufactureYear(const int newManufactureYear);
};
