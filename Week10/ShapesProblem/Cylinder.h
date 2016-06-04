#pragma once
#include "Circle.h"

class Cylinder : public Circle
{
  protected:
    double height;
  public:
    Cylinder();
    Cylinder(double, double, double, double, double);
    Cylinder(const Point&, double, double);

    virtual void print() const;
    virtual void draw() const;
    virtual double getArea() const;
};
