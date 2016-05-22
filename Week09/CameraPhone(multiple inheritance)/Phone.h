#pragma once
#include <iostream>

class Phone
{
protected:
  char* brand;
  char* model;
  int totalMemory;  // in MB
  int freeMemory;
  bool isTouchScreen;
  double screenSize; // in inches/centimeters
  double weight;
  double hoursBatteryLasts;
  int currentBattery;
public:
  Phone();
  Phone(char* brand, char* model, int totalMemory, int freeMemory, bool isTouchScreen, double screenSize, double weight, double hoursBatteryLasts, int currentBattery);
  Phone(const Phone& other);
  Phone& operator=(const Phone& other);
  ~Phone();

  friend std::ostream& operator<<(std::ostream& os, const Phone& obj);
  void charge(int minutes, int percentPerMinute);
  void drain(int percentToDrain);
};
