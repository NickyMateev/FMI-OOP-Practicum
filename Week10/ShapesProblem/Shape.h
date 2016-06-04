#pragma once
#include <iostream>
#include "Point.h"

class Shape
{
  protected:
    Point point;
    void setPoint(double, double, double);
  public:
    Shape();
    Shape(double, double, double);
    Shape(const Point&);
    virtual void print() const = 0;
    virtual void draw() const = 0;
    virtual double getArea() const = 0;
};
