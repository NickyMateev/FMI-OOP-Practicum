#include <string.h>
#include <cassert>
#include "CarMarket.h"

const int CURRENT_YEAR = 2016;
const double PRICE_RATIO = 1.05;

void mystrcpy(char*& destination, const char* source)
{
  int sourceLength = strlen(source);

  destination = new char[sourceLength + 1];
  for(int i = 0; i <= sourceLength; i++)
    destination[i] = source[i];
}

Car::Car()
{
  mystrcpy(brand, "UnknownBrand");
  mystrcpy(model, "UnknownModel");
  mystrcpy(color, "UnknownColor");
  manufactureYear = 0;
}

Car::Car(const char* brand, const char* model, const char* color, int manufactureYear)
{
  mystrcpy(this->brand, brand);
  mystrcpy(this->model, model);
  mystrcpy(this->color, color);
  this->manufactureYear = manufactureYear;
}

Car::Car(const Car& other)
{
  mystrcpy(this->brand, other.brand);
  mystrcpy(this->model, other.model);
  mystrcpy(this->color, other.color);
  this->manufactureYear = other.manufactureYear;
}

Car& Car::operator=(const Car& other)
{
  if(this != &other)
  {
    delete[] this->brand;
    delete[] this->model;
    delete[] this->color;

    mystrcpy(this->brand, other.brand);
    mystrcpy(this->model, other.model);
    mystrcpy(this->color, other.color);
    this->manufactureYear = other.manufactureYear;
  }
  return *this;
}

Car::~Car()
{
  delete[] this->brand;
  delete[] this->model;
  delete[] this->color;
}

const char* Car::getBrand() const
{
  return brand;
}

const char* Car::getModel() const
{
  return model;
}

const char* Car::getColor() const
{
  return color;
}

int Car::getManufactureYear() const
{
  return manufactureYear;
}

void Car::setBrand(const char*& newBrand)
{
  delete[] this->brand;
  mystrcpy(this->brand, newBrand);
}

void Car::setModel(const char*& newModel)
{
  delete[] this->model;
  mystrcpy(this->model, newModel);
}

void Car::setColor(const char*& newColor)
{
  delete[] this->color;
  mystrcpy(this->color, newColor);
}

void Car::setManufactureYear(const int newManufactureYear)
{
  this->manufactureYear = newManufactureYear;
}

CarMarketItem::CarMarketItem(const Car& car, double price, const char* carID)
{
  this->car = car;
  this->price = price;
  mystrcpy(this->carID, carID);
}

CarMarketItem::CarMarketItem(const CarMarketItem& other)
{
  this->car = other.car;
  this->price = other.price;
  mystrcpy(this->carID, other.carID);
}

CarMarketItem& CarMarketItem::operator=(const CarMarketItem& other)
{
  if(this != &other)
  {
    delete[] this->carID;

    this->car = other.car;
    this->price = other.price;
    mystrcpy(this->carID, other.carID);
  }
  return *this;
}

CarMarketItem::~CarMarketItem()
{
  delete[] carID;
}

Car CarMarketItem::getCar() const
{
  return car;
}

double CarMarketItem::getPrice() const
{
  return price;
}

const char* CarMarketItem::getCarID() const
{
  return carID;
}

int CarMarketItem::getCarAge() const
{
  return CURRENT_YEAR - car.getManufactureYear();
}

void CarMarketItem::setCar(const Car& newCar)
{
  this->car = newCar;
}

void CarMarketItem::setPrice(const double newPrice)
{
  this->price = newPrice;
}

void CarMarketItem::setCarID(const char*& newCarID)
{
  delete[] this->carID;
  mystrcpy(this->carID, newCarID);
}

CarMarket::CarMarket()
{
  this->cars = new CarMarketItem[INIT_CAP];
  this->numberOfCars = 0;
  this->capacity = INIT_CAP;
  this->budget = INIT_BUDGET;
}

CarMarket::CarMarket(CarMarketItem* cars, int numberOfCars, int capacity, double budget)
{
  this->cars = new CarMarketItem[capacity];
  this->numberOfCars = numberOfCars;
  this->capacity = capacity;
  this->budget = budget;

  for(int i = 0; i < numberOfCars; i++)
    this->cars[i] = cars[i];
}

CarMarket::CarMarket(const CarMarket& other)
{
  this->cars = new CarMarketItem[other.capacity];
  this->numberOfCars = other.numberOfCars;
  this->capacity = other.capacity;
  this->budget = other.budget;

  for(int i = 0; i < other.numberOfCars; i++)
    this->cars[i] = other.cars[i];
}

CarMarket& CarMarket::operator=(const CarMarket& other)
{
  if(this != &other)
  {
    delete[] cars;

    this->cars = new CarMarketItem[other.capacity];
    this->numberOfCars = other.numberOfCars;
    this->capacity = other.capacity;
    this->budget = other.budget;

    for(int i = 0; i < other.numberOfCars; i++)
      this->cars[i] = other.cars[i];
  }
  return *this;
}

CarMarket::~CarMarket()
{
  delete[] cars;
}

void CarMarket::AddCar(const Car& car, double priceSoldFor, const char* carID)
{
  if(priceSoldFor > budget)
  {
    cout << "Not enough money."<<endl;
    return;
  }

  if(capacity == numberOfCars)
  {
    cout << "The store is full." << endl;
    return;
  }

  CarMarketItem newCarToAdd(car, priceSoldFor * PRICE_RATIO, carID);
  cars[numberOfCars] = newCarToAdd;

  budget -= priceSoldFor;
  numberOfCars++;
}

void CarMarket::SellCar(const char* carID)
{
  for(int i = 0; i < numberOfCars; i++)
  {
    if(strcmp(cars[i].getCarID(), carID) == 0)
    {
      cars[i] = cars[numberOfCars - 1];
      numberOfCars--;

      break;
    }
  }
}

const char* CarMarket::GetCheapestCarID()
{
  assert(("There are no cars to search through!", numberOfCars > 0));

  int index = 0;
  for(int i = 1; i < numberOfCars; i++)
  {
    if(cars[index].getPrice() > cars[i].getPrice())
      index = i;
  }

  return cars[index].getCarID();
}

const char* CarMarket::GetNewestCarID()
{
  assert(("There are no cars to search through!", numberOfCars > 0));

  int index = 0;
  for(int i = 1; i < numberOfCars; i++)
  {
    if(cars[index].getCar().getManufactureYear() < cars[i].getCar().getManufactureYear())
      index = i;
  }

  return cars[index].getCarID();
}

int main()
{
  CarMarket carMarket;
  Car c1("Tesla", "Model S", "Red", 2013);
  Car c2("Tesla", "Model 3", "Silver", 2017);
  carMarket.AddCar(c1, 400, "AB12S64");
  carMarket.AddCar(c2, 500, "FG324SA");

  cout << carMarket.GetCheapestCarID() << endl;
  cout << carMarket.GetNewestCarID() << endl;
  cout << endl;
  
  carMarket.SellCar("FG324SA");
  cout << carMarket.GetCheapestCarID() << endl;
  cout << carMarket.GetNewestCarID() << endl;

  return 0;
}
