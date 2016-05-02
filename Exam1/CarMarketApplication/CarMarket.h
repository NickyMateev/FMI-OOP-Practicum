#pragma once
#include "CarMarketItem.h"

const int INIT_CAP = 100;
const int INIT_BUDGET = 100000;

class CarMarket
{
  CarMarketItem* cars;
  int numberOfCars;
  int capacity;
  double budget;
public:
  CarMarket();
  CarMarket(CarMarketItem* cars, int numberOfCars, int capacity, double budget);
  CarMarket(const CarMarket& other);
  CarMarket& operator=(const CarMarket& other);
  ~CarMarket();

  void AddCar(const Car& car, double priceSoldFor, const char* carID);
  void SellCar(const char* carID);
  const char* GetCheapestCarID();
  const char* GetNewestCarID();
};
