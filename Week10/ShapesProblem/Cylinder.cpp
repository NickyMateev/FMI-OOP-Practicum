#include "Cylinder.h"

Cylinder::Cylinder() : Circle()
{
  this->height = 1;
}

Cylinder::Cylinder(double x, double y, double z, double radius, double height) : Circle(x,y,z,radius)
{
  this->height = height;
}

Cylinder::Cylinder(const Point& point, double radius, double height) : Circle(point,radius)
{
  this->height = height;
}

void Cylinder::print() const
{
  std::cout << "Cylinder base info:" << std::endl;
  Circle::print();
  std::cout << "Cylinder height: " << this->height << std::endl;
}

void Cylinder::draw() const
{
  std::cout << "Drawing cylinder..." << std::endl;
}

double Cylinder::getArea() const
{
  return 2*PI*(this->radius)*(this->height + this->radius);
}
