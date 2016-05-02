#pragma once
#include "car.h"

class CarMarketItem
{
  Car car;
  double price;
  char* carID;
public:
  CarMarketItem(const Car& car = Car(), double price = -1, const char* carID = "UnknownID");
  CarMarketItem(const CarMarketItem& other);
  CarMarketItem& operator=(const CarMarketItem& other);
  ~CarMarketItem();
public:
  Car getCar() const;
  double getPrice() const;
  const char* getCarID() const;

  void setCar(const Car& newCar);
  void setPrice(const double newPrice);
  void setCarID(const char*& newCarID);

  int getCarAge() const;
};
