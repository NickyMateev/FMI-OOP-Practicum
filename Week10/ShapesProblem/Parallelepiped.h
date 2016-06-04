#pragma once
#include "Rectangle.h"

class Parallelepiped : public Rectangle
{
  protected:
    double p_height;
  public:
    Parallelepiped();
    Parallelepiped(double, double, double, double, double, double);
    Parallelepiped(const Point&, double, double, double);

    virtual void print() const;
    virtual void draw() const;
    virtual double getArea() const;
};
