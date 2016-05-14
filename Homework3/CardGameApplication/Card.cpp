#include "Card.h"

const int DEFAULT_ATTACK = 500;
const int DEFAULT_HEALTH = 1000;

int Card::CalculateEnergy(int healthPts, int attackPts)
{
  return (healthPts / 100) + (attackPts / 20);
}

Card::Card()
{
  attackPoints = DEFAULT_ATTACK;
  maxHealthPts = DEFAULT_HEALTH;
  curHealthPts = DEFAULT_HEALTH;
  energyPoints = CalculateEnergy(maxHealthPts, attackPoints);
}

Card::Card(int attackPoints, int healthPts)
{
  this->attackPoints = attackPoints;
  this->maxHealthPts = healthPts;
  this->curHealthPts = healthPts;
  this->energyPoints = CalculateEnergy(this->maxHealthPts, this->attackPoints);
}

Card::Card(const Card& other)
{
  this->attackPoints = other.attackPoints;
  this->maxHealthPts = other.maxHealthPts;
  this->curHealthPts = other.maxHealthPts;
  this->energyPoints = other.energyPoints;
}

Card& Card::operator=(const Card& other)
{
  if(this != &other)
  {
    this->attackPoints = other.attackPoints;
    this->maxHealthPts = other.maxHealthPts;
    this->curHealthPts = other.maxHealthPts;
    this->energyPoints = other.energyPoints;
  }

  return *this;
}

Card::~Card() { }

int Card::getAttackPts() const
{
  return attackPoints;
}

int Card::getMaxHealthPts() const
{
  return maxHealthPts;
}

int Card::getCurHealthPts() const
{
  return curHealthPts;
}

int Card::getEnergyPts() const
{
  return energyPoints;
}

void Card::setAttackPts(int attackPoints)
{
  this->attackPoints = attackPoints;
  this->energyPoints = CalculateEnergy(this->maxHealthPts, this->attackPoints);
}

void Card::setMaxHealthPts(int maxHealthPts)
{
  this->maxHealthPts = maxHealthPts;
  this->energyPoints = CalculateEnergy(this->maxHealthPts, this->attackPoints);
}

void Card::setCurHealthPts(int curHealthPts)
{
  if(curHealthPts > this->maxHealthPts)
    this->curHealthPts = this->maxHealthPts;
  else
    this->curHealthPts = curHealthPts;
}


bool Card::operator==(const Card& other)
{
  return (this->attackPoints == other.attackPoints) && (this->maxHealthPts == other.maxHealthPts);
}

bool Card::operator!=(const Card& other)
{
  return !(*this == other);
}

ostream& operator<<(ostream& os, const Card& card)
{
  os << "Attack points: " << card.attackPoints << endl;
  os << "Max Health points: " << card.maxHealthPts << endl;
  os << "Current Health points: " << card.curHealthPts << endl;
  os << "Energy points: " << card.energyPoints;

  return os;
}

istream& operator>>(istream& is, Card& card)
{
  is >> card.attackPoints;
  is >> card.maxHealthPts;

  card.curHealthPts = card.maxHealthPts;
  card.energyPoints = card.CalculateEnergy(card.maxHealthPts, card.attackPoints);

  return is;
}

Card& Card::operator+=(int healthPts)
{
  if(curHealthPts + healthPts > maxHealthPts)
    curHealthPts = maxHealthPts;
  else
    curHealthPts += healthPts;

  return *this;
}

Card& Card::operator-=(int healthPts)
{
  if(curHealthPts - healthPts < 0)
    curHealthPts = 0;
  else
    curHealthPts -= healthPts;

  return *this;
}
