#include <iostream>
using namespace std;

int mystrlen(const char* source)
{
  int length = 0;
  while(source[length] != '\0')
    length++;

  return length;
}

void mystrcpy(char*& destination, const char* source)
{
  size_t sourceLength = mystrlen(source);

  destination = new char[sourceLength + 1];
  for(int i = 0; i <= sourceLength; i++)
    destination[i] = source[i];
}

class Person
{
  char* name;
  char* EGN;
public:
  Person();
  Person(const char* name, const char* EGN);
  Person(const Person& other);
  Person& operator=(const Person& other);
  ~Person();

  const char* getName() const;
  const char* getEGN() const;

  void setName(const char* name);
  void setEGN(const char* EGN);
};

class BankAccount
{
  Person person;
  char* IBAN;
  double balance;
  char* currency;
public:
  BankAccount();
  BankAccount(const Person& person, const char* IBAN, double balance, const char* currency);
  BankAccount(const BankAccount& other);
  BankAccount& operator=(const BankAccount& other);
  ~BankAccount();

  Person getPerson() const;
  const char* getIBAN() const;
  double getBalance() const;
  const char* getCurrency() const;

  void setPerson(const Person& person);
  void setIBAN(const char* IBAN);
  void setBalance(double balance);
  void setCurrency(const char* currency);

  void Deposit(double amount);
  void Withdraw(double amount);
};

Person::Person()
{
  mystrcpy(name, "UnknownName");
  mystrcpy(EGN, "UnknownEGN");
}

Person::Person(const char* name, const char* EGN)
{
  mystrcpy(this->name, name);
  mystrcpy(this->EGN, EGN);
}

Person::Person(const Person& other)
{
  mystrcpy(this->name, other.name);
  mystrcpy(this->EGN, other.EGN);
}

Person& Person::operator=(const Person& other)
{
  if(this != &other)
  {
    delete[] name;
    delete[] EGN;

    mystrcpy(this->name, other.name);
    mystrcpy(this->EGN, other.EGN);
  }
  return *this;
}

Person::~Person()
{
  delete[] name;
  delete[] EGN;
}

const char* Person::getName() const
{
  return name;
}

const char* Person::getEGN() const
{
  return EGN;
}

void Person::setName(const char* name)
{
  delete[] this->name;
  mystrcpy(this->name, name);
}

void Person::setEGN(const char* EGN)
{
  delete[] this->EGN;
  mystrcpy(this->EGN, EGN);
}

BankAccount::BankAccount()
{
  person = Person();
  mystrcpy(IBAN, "UnknownIBAN");
  balance = 0;
  mystrcpy(currency, "UnknownCurrency");
}

BankAccount::BankAccount(const Person& person, const char* IBAN,double balance, const char* currency)
{
  this->person = person;
  mystrcpy(this->IBAN, IBAN);
  this->balance = balance;
  mystrcpy(this->currency, currency);
}

BankAccount::BankAccount(const BankAccount& other)
{
  this->person = other.person;
  mystrcpy(this->IBAN, other.IBAN);
  this->balance = other.balance;
  mystrcpy(this->currency, other.currency);
}

BankAccount& BankAccount::operator=(const BankAccount& other)
{
  if(this != &other)
  {
    delete[] this->IBAN;
    delete[] this->currency;

    this->person = other.person;
    mystrcpy(this->IBAN, other.IBAN);
    this->balance = other.balance;
    mystrcpy(this->currency, other.currency);
  }
  return *this;
}

BankAccount::~BankAccount()
{
  delete[] IBAN;
  delete[] currency;
}

Person BankAccount::getPerson() const
{
  return person;
}

const char* BankAccount::getIBAN() const
{
  return IBAN;
}

double BankAccount::getBalance() const
{
  return balance;
}

const char* BankAccount::getCurrency() const
{
  return currency;
}

void BankAccount::setPerson(const Person& person)
{
  this->person = person;
}

void BankAccount::setIBAN(const char* IBAN)
{
  delete[] this->IBAN;
  mystrcpy(this->IBAN, IBAN);
}

void BankAccount::setBalance(double balance)
{
  this->balance = balance;
}

void BankAccount::setCurrency(const char* currency)
{
  delete[] this->currency;
  mystrcpy(this->currency, currency);
}

void BankAccount::Deposit(double amount)
{
  balance += amount;
}

void BankAccount::Withdraw(double amount)
{
  if(amount <= balance)
    balance -= amount;
}

int main()
{
  Person p;
  BankAccount ba(p, "123456789", 1000, "Dollars");
  cout << "$" << ba.getBalance() << endl;
  ba.Deposit(123);
  ba.Withdraw(1000);
  cout << "$" << ba.getBalance() << endl;

  return 0;
}
