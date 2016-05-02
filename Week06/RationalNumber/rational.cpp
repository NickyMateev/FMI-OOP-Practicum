#include <iostream>
using namespace std;

class RationalNumber
{
  int numerator;
  int denominator;
public:
  RationalNumber();
  RationalNumber(int numerator, int denominator);
  RationalNumber(const RationalNumber& other);

  RationalNumber& operator=(const RationalNumber& other);

  ~RationalNumber();

  RationalNumber operator+(const RationalNumber& other) const;
  RationalNumber operator-(const RationalNumber& other) const;
  RationalNumber operator*(const RationalNumber& other) const;
  RationalNumber operator/(const RationalNumber& other) const;

  bool operator==(const RationalNumber& other) const;
  bool operator!=(const RationalNumber& other) const;
  bool operator<(const RationalNumber& other) const;
  bool operator>(const RationalNumber& other) const;

  friend ostream& operator<<(ostream& os, const RationalNumber& number);
  friend istream& operator>>(istream& is, RationalNumber& number);
};

RationalNumber::RationalNumber()
{
  numerator = 0;
  denominator = 1;
}

RationalNumber::RationalNumber(int numerator, int denominator)
{
  this->numerator = numerator;
  this->denominator = denominator;
}

RationalNumber::RationalNumber(const RationalNumber& other)
{
  this->numerator = other.numerator;
  this->denominator = other.denominator;
}

RationalNumber& RationalNumber::operator=(const RationalNumber& other)
{
  if(this != &other)
  {
    this->numerator = other.numerator;
    this->denominator = other.denominator;
  }
  return *this;
}

RationalNumber::~RationalNumber() { }

RationalNumber RationalNumber::operator+(const RationalNumber& other) const
{
  return RationalNumber(this->numerator * other.denominator + other.numerator * this->denominator, this->denominator * other.denominator);
}

RationalNumber RationalNumber::operator-(const RationalNumber& other) const
{
  return RationalNumber(this->numerator * other.denominator - other.numerator * this->denominator, this->denominator * other.denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& other) const
{
  return RationalNumber(this->numerator * other.numerator, this->denominator * other.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber& other) const
{
  return RationalNumber(this->numerator * other.denominator, this->denominator * other.numerator);
}

bool RationalNumber::operator==(const RationalNumber& other) const
{
  return (this->numerator == other.numerator) && (this->denominator == other.denominator);
}

bool RationalNumber::operator!=(const RationalNumber& other) const
{
  return !(*this == other);
}

bool RationalNumber::operator<(const RationalNumber& other) const
{
  return (this->numerator * other.denominator < other.numerator * this->denominator);
}

bool RationalNumber::operator>(const RationalNumber& other) const
{
  return !(*this < other) && (*this != other);
}

ostream& operator<<(ostream& os, const RationalNumber& number)
{
  os << number.numerator << "/" << number.denominator;
  return os;
}

istream& operator>>(istream& is, RationalNumber& number)
{
  is >> number.numerator;
  is >> number.denominator;
  return is;
}

int main()
{
  RationalNumber rat1(1,2);
  RationalNumber rat2(1,3);

  cout << rat1 + rat2 << endl;  // 5/6

  return 0;
}
