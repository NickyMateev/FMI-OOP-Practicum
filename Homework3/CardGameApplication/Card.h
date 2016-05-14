#pragma once
#include <iostream>
using namespace std;

class Card
{
  int attackPoints;
  int maxHealthPts;
  int curHealthPts;
  int energyPoints;

  int CalculateEnergy(int healthPts, int attackPts);
public:
  Card();
  Card(int, int);
  Card(const Card& other);
  Card& operator=(const Card& other);
  ~Card();

  int getAttackPts() const;
  int getMaxHealthPts() const;
  int getCurHealthPts() const;
  int getEnergyPts() const;

  void setAttackPts(int attackPoints);
  void setMaxHealthPts(int maxHealthPts);
  void setCurHealthPts(int curHealthPts);

  bool operator==(const Card& other);
  bool operator!=(const Card& other);

  friend ostream& operator<<(ostream& os, const Card& card);
  friend istream& operator>>(istream& is, Card& card);

  Card& operator+=(int healthPts);
  Card& operator-=(int healthPts);
};
