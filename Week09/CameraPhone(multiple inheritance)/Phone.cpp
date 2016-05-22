#include "Phone.h"
#include "myFunctions.h"

const int DEFAULT_MEMORY = 2048;
const double DEFAULT_SCREENSIZE = 6.4;
const double DEFAULT_WEIGHT = 200;
const double DEFAULT_BATTERYLAST = 10;
const int DEFAULT_BATTERY = 100;

Phone::Phone()
{
  mystrcpy(this->brand, "UnknownBrand");
  mystrcpy(this->model, "UnknownModel");
  this->totalMemory = DEFAULT_MEMORY;
  this->freeMemory = DEFAULT_MEMORY;
  this->isTouchScreen = false;
  this->screenSize = DEFAULT_SCREENSIZE;
  this->weight = DEFAULT_WEIGHT;
  this->hoursBatteryLasts = DEFAULT_BATTERYLAST;
  this->currentBattery = DEFAULT_BATTERY;
}

Phone::Phone(char* brand, char* model, int totalMemory, int freeMemory, bool isTouchScreen, double screenSize, double weight, double hoursBatteryLasts, int currentBattery)
{
  mystrcpy(this->brand, brand);
  mystrcpy(this->model, model);
  this->totalMemory = totalMemory;
  this->freeMemory = freeMemory;
  this->isTouchScreen = isTouchScreen;
  this->screenSize = screenSize;
  this->weight = weight;
  this->hoursBatteryLasts = hoursBatteryLasts;
  this->currentBattery = currentBattery;
}

Phone::Phone(const Phone& other)
{
  mystrcpy(this->brand, other.brand);
  mystrcpy(this->model, other.model);
  this->totalMemory = other.totalMemory;
  this->freeMemory = other.freeMemory;
  this->isTouchScreen = other.isTouchScreen;
  this->screenSize = other.screenSize;
  this->weight = other.weight;
  this->hoursBatteryLasts = other.hoursBatteryLasts;
  this->currentBattery = other.currentBattery;
}

Phone& Phone::operator=(const Phone& other)
{
  if(this != &other)
  {
    delete[] this->brand;
    delete[] this->model;

    mystrcpy(this->brand, other.brand);
    mystrcpy(this->model, other.model);
    this->totalMemory = other.totalMemory;
    this->freeMemory = other.freeMemory;
    this->isTouchScreen = other.isTouchScreen;
    this->screenSize = other.screenSize;
    this->weight = other.weight;
    this->hoursBatteryLasts = other.hoursBatteryLasts;
    this->currentBattery = other.currentBattery;
  }
  return *this;
}

Phone::~Phone()
{
   delete[] this->brand;
   delete[] this->model;
}

std::ostream& operator<<(std::ostream& os, const Phone& obj)
{
  os << "Brand name: " << obj.brand << std::endl;
  os << "Model name: " << obj.model << std::endl;
  os << "Total memory: " << obj.totalMemory << std::endl;
  os << "Free memory: " << obj.freeMemory << std::endl;
  os << "Is touchscreen: " << obj.isTouchScreen << std::endl;
  os << "Screen size: " << obj.screenSize << std::endl;
  os << "Phone weight: " << obj.weight<< std::endl;
  os << "Hours battery lasts: " << obj.hoursBatteryLasts << std::endl;
  os << "Current battery: " << obj.currentBattery << "%";

  return os;
}

void Phone::charge(int minutes, int percentPerMinute)
{
  this->currentBattery += (minutes * percentPerMinute);

  if(this->currentBattery > 100)
    this->currentBattery = 100;
}

void Phone::drain(int percentToDrain)
{
  this->currentBattery -= percentToDrain;

  if(this->currentBattery < 0)
    this->currentBattery = 0;
}
