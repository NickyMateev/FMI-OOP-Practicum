#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
  this->width = 1;
  this->height = 1;
}

Rectangle::Rectangle(double x, double y, double z, double width, double height) : Shape(x,y,z)
{
  this->width = width;
  this->height = height;
}

Rectangle::Rectangle(const Point& point, double width, double height) : Shape(point)
{
  this->width = width;
  this->height = height;
}

void Rectangle::print() const
{
  std::cout << "Coordinate of upper left corner point of the rectangle: (" << this->point.x << ", " << this->point.y << ", " << this->point.z << ")" << std::endl;
  std::cout << "Rectangle width: " << this->width << std::endl;
  std::cout << "Rectangle height: " << this->height << std::endl;
}

void Rectangle::draw() const
{
  std::cout << "Drawing rectangle..." << std::endl;
}

double Rectangle::getArea() const
{
  return (this->width)*(this->height);
}
