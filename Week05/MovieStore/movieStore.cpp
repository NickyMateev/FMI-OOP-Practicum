#include <iostream>
#include <string.h>
using namespace std;

const int INIT_CAP = 64;

class Author
{
  char* firstName;
  char* lastName;
  int age;
  int rating;
public:
  Author(char* firstName = "UnknownName", char* lastName = "UnknownName", int age = 0, int rating = -1);
  Author(const Author& author);
  Author& operator=(const Author& other);
  ~Author();

  bool operator==(const Author& other);
  friend ostream& operator<<(ostream& os, const Author& author);

  const char* getFirstName() const; // see if it needs to return a const type
  const char* getLastName() const;  // same here
  int getAge() const;
  int getRating() const;
};

class Movie
{
  char* name;
  Author author;
  int price;
public:
  Movie(char* name = "UnknownName", Author author = Author(), int price = 0);
  Movie(const Movie& other);
  Movie& operator=(const Movie& other);
  ~Movie();

  bool operator==(const Movie& other);
  friend ostream& operator<<(ostream& os, const Movie& movie);

  const char* getName() const;
  const char* getAuthorFirstName() const;
  const char* getAuthorLastName() const;
  int getPrice() const;
  void newPrice(const int price);
};

class MovieStore
{
  Movie* movies;
  int budget;
  size_t size;
  size_t capacity;
public:
  MovieStore(Movie* movies = NULL, int budget = 0, size_t size = 0, size_t capacity = INIT_CAP);
  MovieStore(int budget);
  ~MovieStore();

  bool SearchByMovie(Movie movie);
  void Resize(size_t newCapacity);
  void SortMovies();
  void DeleteMovie(const char* name);
  void PushMovie(const Movie& movie);  // adds a movie to the MovieStore
  void Print();

  void setMovie(const Movie& movie, size_t index);
  void setBudget(int newBudget);
  void setSize(int newSize);
  Movie getMovie(size_t index) const;
  int getBudget() const;
};

void mystrcpy(char*& destination, char* source)
{
  destination = new char[strlen(source) + 1];
  for(int i = 0; i <= strlen(source); i++)
    destination[i] = source[i];
}

Author::Author(char* firstName, char* lastName, int age, int rating)
{
  mystrcpy(this->firstName, firstName);
  mystrcpy(this->lastName, lastName);
  this->age = age;
  this->rating = rating;
}


Author& Author::operator=(const Author& other)
{
  if(this != &other)
  {
    mystrcpy(this->firstName, other.firstName);
    mystrcpy(this->lastName, other.lastName);
    this->age = other.age;
    this->rating = other.rating;
  }
  return *this;
}

Author::Author(const Author& author)
{
  mystrcpy(this->firstName, author.firstName);
  mystrcpy(this->lastName, author.lastName);
  this->age = author.age;
  this->rating = author.rating;
}

Author::~Author()
{
  delete[] firstName;
  delete[] lastName;
}

bool Author::operator==(const Author& other)
{
  return (this->age == other.age) && (this->rating == other.rating) && (strcmp(this->firstName, other.firstName) == 0) && (strcmp(this->lastName, other.lastName) == 0);
}

ostream& operator<<(ostream& os, const Author& author)
{
  os << "Author first name: " << author.firstName << endl;
  os << "Author last name: " << author.lastName << endl;
  os << "Age: " << author.age << endl;
  os << "Rating: " << author.rating;

  return os;
}

const char* Author::getFirstName() const
{
  return firstName;
}

const char* Author::getLastName() const
{
  return lastName;
}

int Author::getAge() const
{
  return age;
}

int Author::getRating() const
{
  return rating;
}

Movie::Movie(char* name, Author author, int price)
{
  mystrcpy(this->name, name);
  this->author = author;
  this->price = price;
}

Movie::Movie(const Movie& other)
{
  mystrcpy(this->name, other.name);
  this->author = other.author;
  this->price = other.price;
}

Movie& Movie::operator=(const Movie& other)
{
  if(this != &other)
  {
    delete[] name;

    mystrcpy(this->name, other.name);
    this->author = other.author;
    this->price = other.price;
  }
  return *this;
}

Movie::~Movie()
{
  delete[] name;
}

bool Movie::operator==(const Movie& other)
{
  return (this->price == other.price) && (strcmp(this->name, other.name) == 0) && (this->author == other.author);
}

ostream& operator<<(ostream& os, const Movie& movie)
{
  os << "Movie name: " << movie.name << endl;
  os << movie.author << endl;
  os << "Price: " << movie.price;

  return os;
}

const char* Movie::getName() const
{
  return name;
}

const char* Movie::getAuthorFirstName() const
{
  return author.getFirstName();
}

const char* Movie::getAuthorLastName() const
{
  return author.getLastName();
}

int Movie::getPrice() const
{
  return price;
}

void Movie::newPrice(const int price)
{
  this->price = price;
}

// What's left: implement MovieStore

MovieStore::MovieStore(Movie* movies, int budget, size_t size, size_t capacity)
{
  this->budget = budget;
  this->capacity = capacity;
  this->size = size;
  this->movies = new Movie[capacity];

  for(int i = 0; i < size; i++)
    this->movies[i] = movies[i];
}

MovieStore::MovieStore(int budget)
{
  this->budget = budget;
  this->capacity = INIT_CAP;
  this->size = 0;
  this->movies = new Movie[this->capacity];
}

MovieStore::~MovieStore()
{
  delete[] movies;
}

bool MovieStore::SearchByMovie(Movie movie)
{
  for(int i = 0; i < size; i++)
  {
    if(movies[i] == movie)
      return true;
  }

  return false;
}

void MovieStore::Resize(size_t newCapacity)
{
  if(newCapacity < 1)
  {
    cout << "Invalid capacity!" << endl;
    return;
  }

  Movie* newMovies = new Movie[newCapacity];

  if(newCapacity < size)
    size = newCapacity - 1;

  for(int i = 0; i < size; i++)
    newMovies[i] = movies[i];

  movies = newMovies;
}

void swapMovies(Movie& movie1, Movie& movie2)
{
  Movie temp = movie1;
  movie1 = movie2;
  movie2 = temp;
}

void MovieStore::SortMovies()
{
  for(int i = 0; i < size - 1; i++)
  {
    for(int j = 0; j < size - 1 - i; j++)
    {
      if(strcmp(movies[j].getName(), movies[j+1].getName()) > 0)
        swapMovies(movies[j], movies[j+1]);
    }
  }
}

void MovieStore::DeleteMovie(const char* name)
{
  for(int i = 0; i < size; i++)
  {
    if(strcmp(movies[i].getName(), name) == 0)
    {
      swapMovies(movies[i], movies[size - 1]);
      size--;
      return;
    }
  }
}

void MovieStore::PushMovie(const Movie& movie)
{
  if(size == capacity)
    Resize(2 * capacity);

  movies[size] = movie;
  size++;
}

void MovieStore::Print()
{
  for(int i = 0; i < size; i++)
    cout << movies[i] << endl;
}

void MovieStore::setMovie(const Movie& movie, size_t index)
{
  if(index < 0 || index >= size)
  {
    cout << "Invalid index!" << endl;
    return;
  }

  movies[index] = movie;
}

void MovieStore::setBudget(int newBudget)
{
  this->budget = newBudget;
}

void MovieStore::setSize(int newSize)
{
  if(newSize > capacity)
  {
    cout << "Invalid size!" << endl;
    return;
  }

  this->size = newSize;
}

Movie MovieStore::getMovie(size_t index) const
{
  return movies[index];
}

int MovieStore::getBudget() const
{
  return budget;
}

int main()
{
  return 0;
}
