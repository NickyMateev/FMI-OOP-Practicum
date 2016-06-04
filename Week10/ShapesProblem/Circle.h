#pragma once
#include "Shape.h"

const double PI = 3.14;

class Circle : public Shape
{
  protected:
    double radius;
  public:
    Circle();
    Circle(double, double, double, double);
    Circle(const Point&, double);

    virtual void print() const;
    virtual void draw() const;
    virtual double getArea() const;
};
