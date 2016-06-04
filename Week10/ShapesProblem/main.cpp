#include <iostream>
#include "Parallelepiped.h"

int main()
{
  Point point;
  point.x = 1;
  point.y = 2;
  point.z = 3;

  Parallelepiped p(point, 10, 20, 50);
  p.print();
  std::cout << "Parallelepiped surface area: " << p.getArea() << std::endl;

  return 0;
}
