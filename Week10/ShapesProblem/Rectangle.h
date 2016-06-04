#include "Shape.h"

class Rectangle : public Shape
{
  protected:
    double width;
    double height;
  public:
    Rectangle();
    Rectangle(double, double, double, double, double);
    Rectangle(const Point&, double, double);

    virtual void print() const;
    virtual void draw() const;
    virtual double getArea() const;
};
