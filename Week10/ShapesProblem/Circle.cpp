#include "Circle.h"

Circle::Circle() : Shape()
{
  this->radius = 1;
}

Circle::Circle(double x, double y, double z, double radius) : Shape(x,y,z)
{
  this->radius = radius;
}

Circle::Circle(const Point& point, double radius) : Shape(point)
{
  this->radius = radius;
}

void Circle::print() const
{
  std::cout << "Circle center: (" << this->point.x << ", " << this->point.y << ", " << this->point.z << ")" << std::endl;
  std::cout << "Circle radius = " << this->radius << std::endl;
}

void Circle::draw() const
{
  std::cout << "Drawing circle..." << std::endl;
}

double Circle::getArea() const
{
  return (this->radius)*(this->radius)*PI;
}

