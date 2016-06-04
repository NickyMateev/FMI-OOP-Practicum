#include "Shape.h"

void Shape::setPoint(double x, double y, double z)
{
	this->point.x = x;
	this->point.y = y;
	this->point.z = z;
}

Shape::Shape()
{
  this->setPoint(0, 0, 0);
}

Shape::Shape(double x, double y, double z)
{
  this->setPoint(x, y, z);
}

Shape::Shape(const Point& point)
{
  this->setPoint(point.x, point.y, point.z);
}
