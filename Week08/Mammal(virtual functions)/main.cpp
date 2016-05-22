#include <iostream>
#include "Mammal.h"
#include "Hippo.h"
#include "Dog.h"
#include "Kangaroo.h"
#include "Human.h"


int main()
{
  Mammal mammal;
  Hippo hippo;
  Dog dog;
  Kangaroo kangaroo;
  Human human;

  Mammal* ptr = &human;
  std::cout << ptr->getSpeciesName() << std::endl;
  std::cout << human.isSameSpeciesLike(&mammal) << std::endl;
  std::cout << human.isSameSpeciesLike(&hippo) << std::endl;
  std::cout << human.isSameSpeciesLike(&dog) << std::endl;
  std::cout << human.isSameSpeciesLike(&kangaroo) << std::endl;

  std::cout << "---------------------------------------" << std::endl;
  ptr = &dog;
  std::cout << "Can a dog jump? -> ";
  if(ptr->canJump())
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  std::cout << "---------------------------------------" << std::endl;
  ptr = &hippo;
  std::cout << "Can a hippo jump? -> ";
  if(ptr->canJump())
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;


  return 0;
}
