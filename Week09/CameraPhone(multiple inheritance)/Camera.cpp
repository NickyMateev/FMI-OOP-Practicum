#include "Camera.h"

const double DEFAULT_RES = 10;
const double DEFAULT_PHOTOSIZE = 3;

Camera::Camera()
{
  this->resolution = DEFAULT_RES;
  this->hasFlash = false;
  this->photoSizeWithoutFlash = DEFAULT_PHOTOSIZE;
  this->photoSizeWithFlash = 0;
}

Camera::Camera(double resolution, bool hasFlash, double photoSizeWithoutFlash, double photoSizeWithFlash)
{
  this->resolution = resolution;
  this->hasFlash = hasFlash;
  this->photoSizeWithoutFlash = photoSizeWithoutFlash;
  if(!hasFlash)
    this->photoSizeWithFlash = 0;
  else
    this->photoSizeWithFlash = photoSizeWithFlash;
}

Camera::Camera(const Camera& other)
{
  this->resolution = other.resolution;
  this->hasFlash = other.hasFlash;
  this->photoSizeWithoutFlash = other.photoSizeWithoutFlash;
  if(!other.hasFlash)
    this->photoSizeWithFlash = 0;
  else
    this->photoSizeWithFlash = other.photoSizeWithFlash;
}

Camera& Camera::operator=(const Camera& other)
{
  if(this != &other)
  {
    this->resolution = other.resolution;
    this->hasFlash = other.hasFlash;
    this->photoSizeWithoutFlash = other.photoSizeWithoutFlash;
    if(!other.hasFlash)
      this->photoSizeWithFlash = 0;
    else
      this->photoSizeWithFlash = other.photoSizeWithFlash;
  }
  return *this;
}

Camera::~Camera() { }

std::ostream& operator<<(std::ostream& os, const Camera& obj)
{
  os << "Camera resolution: " << obj.resolution << "MP" << std::endl;
  os << "Has flash: " << obj.hasFlash << std::endl;
  os << "Picture size without flash: " << obj.photoSizeWithoutFlash << "MB" << std::endl;
  os << "Picture size with flash: " << obj.photoSizeWithFlash << "MB";

  return os;
}
