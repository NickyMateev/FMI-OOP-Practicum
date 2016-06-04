#include "Parallelepiped.h"

Parallelepiped::Parallelepiped() : Rectangle()
{
  this->p_height = 1;
}

Parallelepiped::Parallelepiped(double x, double y, double z, double width, double height, double p_height) : Rectangle(x,y,z,width,height)
{
  this->p_height = p_height;
}

Parallelepiped::Parallelepiped(const Point& point, double width, double height, double p_height) : Rectangle(point, width, height)
{
  this->p_height = p_height;
}

void Parallelepiped::print() const
{
  std::cout << "Parallelepiped base info:" << std::endl;
  Rectangle::print();
  std::cout << "Parallelepiped height: " << this->p_height << std::endl;
}

void Parallelepiped::draw() const
{
  std::cout << "Drawing parallelepiped..." << std::endl;
}

double Parallelepiped::getArea() const
{
  return 2 * ((this->height)*(this->width) + (this->height)*(this->p_height) + (this->width)*(this->p_height));
}
