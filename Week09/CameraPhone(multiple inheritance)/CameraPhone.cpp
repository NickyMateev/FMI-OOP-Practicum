#include "CameraPhone.h"

CameraPhone::CameraPhone() : Phone(), Camera()
{
  this->batteryNeededCameraWork = 5;
  this->batteryNeededPhotoWithoutFlash = 1;
  this->batteryNeededPhotoWithFlash = 2;
}

CameraPhone::CameraPhone(int batteryNeededCameraWork, int batteryNeededPhotoWithoutFlash, int batteryNeededPhotoWithFlash, char* brand, char* model, int totalMemory, int freeMemory, bool isTouchScreen, double screenSize, double weight, double hoursBatteryLasts, int currentBattery, double resolution, bool hasFlash, double photoSizeWithoutFlash, double photoSizeWithFlash) : Phone(brand, model, totalMemory, freeMemory, isTouchScreen, screenSize, weight, hoursBatteryLasts, currentBattery), Camera(resolution, hasFlash, photoSizeWithoutFlash, photoSizeWithFlash)
{
  this->batteryNeededCameraWork = batteryNeededCameraWork;
  this->batteryNeededPhotoWithoutFlash = batteryNeededPhotoWithoutFlash;
  this->batteryNeededPhotoWithFlash = batteryNeededPhotoWithFlash;
}

CameraPhone::CameraPhone(const CameraPhone& other) : Phone(other), Camera(other)
{
  this->batteryNeededCameraWork = other.batteryNeededCameraWork;
  this->batteryNeededPhotoWithoutFlash = other.batteryNeededPhotoWithoutFlash;
  this->batteryNeededPhotoWithFlash = other.batteryNeededPhotoWithFlash;
}

CameraPhone& CameraPhone::operator=(const CameraPhone& other)
{
  if(this != &other)
  {
    Phone::operator=(other);
    Camera::operator=(other);

    this->batteryNeededCameraWork = other.batteryNeededCameraWork;
    this->batteryNeededPhotoWithoutFlash = other.batteryNeededPhotoWithoutFlash;
    this->batteryNeededPhotoWithFlash = other.batteryNeededPhotoWithFlash;
  }
  return *this;
}

CameraPhone::~CameraPhone() { }

std::ostream& operator<<(std::ostream& os, const CameraPhone& obj)
{
  os << (Phone) obj << std::endl;
  os << (Camera) obj << std::endl;
  os << "Battery needed for the camera to work: " << obj.batteryNeededCameraWork << "%" << std::endl;
  os << "Battery needed to take photo without flash: " << obj.batteryNeededPhotoWithoutFlash << "%" << std::endl;
  os << "Battery needed to take photo with flash: " << obj.batteryNeededPhotoWithFlash << "%";

  return os;
}

int CameraPhone::numberOfPicsLeft()
{
  return (this->freeMemory / this->photoSizeWithoutFlash);
}

void CameraPhone::takePhoto(bool useFlash)
{
  if(!this->hasFlash)
    useFlash = false;

  if(useFlash)
  {
    if(this->currentBattery < this->batteryNeededPhotoWithFlash)
      std::cout << "Not enought battery!" << std::endl;
    else if(this->freeMemory < this->photoSizeWithFlash)
      std::cout << "Not enough memory!" << std::endl;
    else
    {
      this->currentBattery -= this->batteryNeededPhotoWithFlash;
      this->freeMemory -= this->photoSizeWithFlash;
    }
  }
  else
  {
    if(this->currentBattery < this->batteryNeededPhotoWithoutFlash)
      std::cout << "Not enought battery!" << std::endl;
    else if(this->freeMemory < this->photoSizeWithoutFlash)
      std::cout << "Not enough memory!" << std::endl;
    else
    {
      this->currentBattery -= this->batteryNeededPhotoWithoutFlash;
      this->freeMemory -= this->photoSizeWithoutFlash;
    }
  }

  std::cout << "Battery left: " << this->currentBattery << std::endl;
  std::cout << "Memory left: " << this->freeMemory << std::endl;
}
