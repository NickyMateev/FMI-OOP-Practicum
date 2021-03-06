#pragma once
#include <iostream>
#include <cstring>
#include "Food.h"
#include "Color.h"

class Mammal
{
  protected:
    Food* food;
    unsigned foodCount;
    Color color;
    bool hasFur;
    unsigned numberOfLegs;
    unsigned age;

  public:
    Mammal();
    Mammal(bool hasFur, unsigned numberOfLegs, unsigned age, Food* food, unsigned foodCount, Color color);
    Mammal(const Mammal& other);
    Mammal& operator=(const Mammal& other);
    ~Mammal();

    bool hasFurFunction() const;
    unsigned getNumberOfLegs() const;
    unsigned getAge() const;

    void setFur(bool hasFur);
    void setNumberOfLegs(unsigned numberOfLegs);
    void setAge(unsigned age);

    virtual const char* getSpeciesName() const; // returns the name of the class
    virtual bool eats(Food food) const; // Food is an enum
    virtual Color furColor() const; // Color is an enum
    virtual bool canJump() const;
    virtual bool canSwim() const;
    virtual bool isSameSpeciesLike(Mammal* otherMammal);
};
