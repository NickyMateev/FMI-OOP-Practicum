#pragma once
#include "Phone.h"
#include "Camera.h"

class CameraPhone : public Phone, public Camera
{
  int batteryNeededCameraWork;
  int batteryNeededPhotoWithoutFlash;
  int batteryNeededPhotoWithFlash;
public:
  CameraPhone();
  CameraPhone(int batteryNeededCameraWork, int batteryNeededPhotoWithoutFlash, int batteryNeededPhotoWithFlash, char* brand, char* model, int totalMemory, int freeMemory, bool isTouchScreen, double screenSize, double weight, double hoursBatteryLasts, int currentBattery, double resolution, bool hasFlash, double photoSizeWithoutFlash, double photoSizeWithFlash);
  CameraPhone(const CameraPhone& other);
  CameraPhone& operator=(const CameraPhone& other);
  ~CameraPhone();

  friend std::ostream& operator<<(std::ostream& os, const CameraPhone& obj);
  int numberOfPicsLeft();
  void takePhoto(bool useFlash);
};
