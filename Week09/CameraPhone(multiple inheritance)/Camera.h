#pragma once
#include <iostream>

class Camera
{
protected:
  double resolution; // in megapixels
  bool hasFlash;
  double photoSizeWithoutFlash;
  double photoSizeWithFlash;
public:
  Camera();
  Camera(double resolution, bool hasFlash, double photoSizeWithoutFlash, double photoSizeWithFlash);
  Camera(const Camera& other);
  Camera& operator=(const Camera& other);
  ~Camera();

  friend std::ostream& operator<<(std::ostream& os, const Camera& obj);
};
