#include <iostream>
#include <cstring>
#include <cassert>
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

  void Print();
  bool operator==(const Person& other);

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

  void PrintAccountInfo();

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

class Bank
{
  char* name;
  BankAccount* bankAccounts;
  int numOfBankAccounts;
  Person* staff;
  int numOfStaff;
public:
  Bank();
  Bank(const char* name, const BankAccount* bankAccounts, int numOfBankAccounts, const Person* staff, int numOfStaff);
  Bank(const Bank& other);
  Bank& operator=(const Bank& other);
  ~Bank();

  const char* getBankName() const;
  BankAccount getBankAccount(int index) const;
  Person getStaffMember(int index) const;

  void setBankName(const char* name);
  void setBankAccount(const BankAccount& bankAccount, int index);
  void setStaffMember(const Person& person, int index);

  int CheckForBankAccount(const char* EGN);
  double TotalBalance(const char* EGN);
  bool IsStaffMember(const Person& person);
  int GetStaffMembersWithAccounts();
  void DepositIBAN(const char* IBAN, double amount);
  void WithdrawIBAN(const char* IBAN, double amount);
  void PrintAccounts(const char* EGN);
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

void Person::Print()
{
  cout << "Name: " << name << endl;
  cout << "EGN: " << EGN << endl;
}

bool Person::operator==(const Person& other)
{
  return (strcmp(this->name, other.name) == 0) && (strcmp(this->EGN, other.EGN) == 0);
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

void BankAccount::PrintAccountInfo()
{
  person.Print();
  cout << "IBAN: " << IBAN << endl;
  cout << "Balance: " << balance << endl;
  cout << "Currency: " << currency << endl;
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

Bank::Bank()
{
  mystrcpy(name, "UnknownBankName");
  bankAccounts = NULL;
  numOfBankAccounts = 0;
  staff = NULL;
  numOfStaff = 0;
}

Bank::Bank(const char* name, const BankAccount* bankAccounts, int numOfBankAccounts, const Person* staff, int numOfStaff)
{
  mystrcpy(this->name, name);
  this->bankAccounts = new BankAccount[numOfBankAccounts];
  this->staff = new Person[numOfStaff];

  this->numOfBankAccounts = numOfBankAccounts;
  this->numOfStaff = numOfStaff;

  for(int i = 0; i < numOfBankAccounts; i++)
    this->bankAccounts[i] = bankAccounts[i];

  for(int i = 0; i < numOfStaff; i++)
    this->staff[i] = staff[i];
}

Bank::Bank(const Bank& other)
{
  mystrcpy(this->name, other.name);
  this->bankAccounts = new BankAccount[other.numOfBankAccounts];
  this->staff = new Person[other.numOfStaff];

  this->numOfBankAccounts = other.numOfBankAccounts;
  this->numOfStaff = other.numOfStaff;

  for(int i = 0; i < other.numOfBankAccounts; i++)
    this->bankAccounts[i] = other.bankAccounts[i];

  for(int i = 0; i < other.numOfStaff; i++)
    this->staff[i] = other.staff[i];
}

Bank& Bank::operator=(const Bank& other)
{
  if(this != &other)
  {
    delete[] name;
    delete[] bankAccounts;
    delete[] staff;

    mystrcpy(this->name, other.name);
    this->bankAccounts = new BankAccount[other.numOfBankAccounts];
    this->staff = new Person[other.numOfStaff];

    this->numOfBankAccounts = other.numOfBankAccounts;
    this->numOfStaff = other.numOfStaff;

    for(int i = 0; i < other.numOfBankAccounts; i++)
      this->bankAccounts[i] = other.bankAccounts[i];

    for(int i = 0; i < other.numOfStaff; i++)
      this->staff[i] = other.staff[i];
  }
  return *this;
}

Bank::~Bank()
{
  delete[] name;
  delete[] bankAccounts;
  delete[] staff;
}

const char* Bank::getBankName() const
{
  return name;
}

BankAccount Bank::getBankAccount(int index) const
{
  assert(("Invalid index!", index >= 0 && index < numOfBankAccounts));

  return bankAccounts[index];
}

Person Bank::getStaffMember(int index) const
{
  assert(("Invalid index!", index >= 0 && index < numOfBankAccounts));

  return staff[index];
}

void Bank::setBankName(const char* name)
{
  delete[] this->name;
  mystrcpy(this->name, name);
}

void Bank::setBankAccount(const BankAccount& bankAccount, int index)
{
  assert(("Invalid index!", index >= 0 && index < numOfBankAccounts));

  bankAccounts[index] = bankAccount;
}

void Bank::setStaffMember(const Person& person, int index)
{
  assert(("Invalid index!", index >= 0 && index < numOfBankAccounts));

  staff[index] = person;
}

int Bank::CheckForBankAccount(const char* EGN)
{
  for(int i = 0; i < numOfBankAccounts; i++)
  {
    if(strcmp(bankAccounts[i].getPerson().getEGN(), EGN) == 0)
      return i;
  }

  return -1;
}

double Bank::TotalBalance(const char* EGN)
{
  double sum = 0;
  bool hasBankAccount = false;
  for(int i = 0; i < numOfBankAccounts; i++)
  {
    if(strcmp(bankAccounts[i].getPerson().getEGN(), EGN) == 0)
    {
      sum += bankAccounts[i].getBalance();
      hasBankAccount = true;
    }
  }

  if(hasBankAccount)
    return sum;
  else
  {
    cout << "No bank account was found with the specified EGN!" << endl;
    return 0;
  }
}

bool Bank::IsStaffMember(const Person& person)
{
  for(int i = 0; i < numOfStaff; i++)
  {
    if(staff[i] == person)
      return true;
  }
  return false;
}

int Bank::GetStaffMembersWithAccounts()
{
  int count = 0;
  for(int i = 0; i < numOfStaff; i++)
  {
    for(int j = 0; j < numOfBankAccounts; j++)
    {
      if(staff[i] == bankAccounts[j].getPerson())
      {
        count++;
        break;
      }
    }
  }

  return count;
}

void Bank::DepositIBAN(const char* IBAN, double amount)
{
  for(int i = 0; i < numOfBankAccounts; i++)
  {
    if((strcmp(bankAccounts[i].getIBAN(), IBAN) == 0))
    {
      bankAccounts[i].Deposit(amount);
      break;
    }
  }

  assert(("Invalid IBAN!", false));
}

void Bank::WithdrawIBAN(const char* IBAN, double amount)
{
  for(int i = 0; i < numOfBankAccounts; i++)
  {
    if((strcmp(bankAccounts[i].getIBAN(), IBAN) == 0))
    {
      bankAccounts[i].Withdraw(amount);
      break;
    }
  }

  assert(("Invalid IBAN!", false));
}

void Bank::PrintAccounts(const char* EGN)
{
  for(int i = 0; i < numOfBankAccounts; i++)
  {
    if(strcmp(bankAccounts[i].getPerson().getEGN(), EGN) == 0)
      bankAccounts[i].PrintAccountInfo();
  }
}

int main()
{
  Bank bank;
  bank.PrintAccounts("98765");
  cout << bank.GetStaffMembersWithAccounts() << endl;
  cout << bank.TotalBalance("12345") << endl;
  cout << bank.IsStaffMember(Person()) << endl;
  return 0;
}
