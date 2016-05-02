#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LENGTH = 30;
const int EGN_LENGTH = 11;
const int CURRENT_YEAR = 16;  // 2016, but we need the last two digits only

enum Gender
{
  MALE,
  FEMALE
};

enum RelationshipStatus
{
  SINGLE,
  TAKEN,
  MARRIED
};

struct Person
{
  char firstName[NAME_LENGTH];
  char middleName[NAME_LENGTH];
  char lastName[NAME_LENGTH];

  char EGN[EGN_LENGTH];
  Gender gender;
  RelationshipStatus status;
  bool studies;
  bool works;
};

void InitPerson(Person& person, char* firstName, char* middleName, char* lastName, char* EGN, Gender gender, RelationshipStatus status, bool studies, bool works)
{
  strcpy(person.firstName, firstName);
  strcpy(person.middleName, middleName);
  strcpy(person.lastName, lastName);
  strcpy(person.EGN, EGN);

  person.gender = gender;
  person.status = status;
  person.studies = studies;
  person.works = works;
}

void PrintPerson(const Person& person)
{
  cout << "First name: " << person.firstName << endl;
  cout << "Middle name: " << person.middleName << endl;
  cout << "Last name: " << person.lastName << endl;
  cout << "EGN: " << person.EGN << endl;
  cout << "Relationship status: ";
  if(person.status == 0)
    cout << "Single" << endl;
  else if (person.status == 1)
    cout << "Taken" << endl;
  else
    cout << "Married" << endl;

  cout << "Studies: ";
  if(person.studies)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  cout << "Works: ";
  if(person.works)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int GetAge(const Person& person)
{
  int firstTwoDigits = 10*(person.EGN[0] - 48) + (person.EGN[1] - 48); // 48 is the ASCII code for zero

  if(firstTwoDigits < CURRENT_YEAR)
    return CURRENT_YEAR - firstTwoDigits;
  else
    return CURRENT_YEAR + (100 - firstTwoDigits);
}

bool AreSiblings(const Person& p1, const Person& p2)
{
  return(strcmp(p1.middleName, p2.middleName) == 0) && (strcmp(p1.lastName, p2.lastName) == 0) && (strcmp(p1.firstName, p2.firstName) != 0);
}

bool AreMarried(const Person& p1, const Person& p2)
{
  return (p1.gender != p2.gender) && (p1.status == MARRIED) && (p2.status == MARRIED) && (strcmp(p1.lastName, p2.lastName) == 0);
}

int NumberOfUnemployedNotStudying(const Person* people, int size)
{
  int count = 0;
  for(int i = 0; i < size; i++)
  {
    if(!people[i].studies && !people[i].works)
      count++;
  }

  return count;
}

int NumberOfStudents(const Person* people, int size)
{
  int count = 0;
  for(int i = 0; i < size; i++)
  {
    if(people[i].studies && (GetAge(people[i]) >= 6) && (GetAge(people[i]) <= 19))
      count++;
  }

  return count;
}

int GetPotentialSiblings(const Person* people, int size)
{
  int count = 0;
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(i == j)
        continue;

      if(AreSiblings(people[j], people[i]))
        count++;
    }
  }

  return count / 2;
}


int main()
{
  Person p1, p2;
  InitPerson(p1, "Peter", "Petrov", "Petrov", "9512036412", MALE, TAKEN, true, false);
  InitPerson(p2, "Sara", "Jane", "Petrov", "9605235327", FEMALE, TAKEN, true, false);

  PrintPerson(p1);
  cout << endl;
  PrintPerson(p2);
  cout << endl;

  cout << "Age: " << GetAge(p1) << endl;
  cout << "Age: " << GetAge(p2) << endl;
  cout << endl;

  cout << "Are siblings: " << AreSiblings(p1, p2) << endl;

  return 0;
}
