#include <iostream>
#include <cstring>
using namespace std;

enum Genre
{
	Crime,
	Comedy,
	Adventure,
	Action,
	Educational,
	Romance
};

struct Author
{
	char* name;
	size_t age;
};

struct Book
{
  char* title;
  Author author;
	Genre genre;
	size_t ISBN;
	size_t numberOfPages;
	double price;
};

void mystrcpy(char*& destination, const char* source)
{
	destination = new char[strlen(source) + 1];
	for (int i = 0; i <= strlen(source); i++)
	{
		destination[i] = source[i];
	}
}

void InitAuthor(Author& author, char* name, size_t age)
{
	mystrcpy(author.name, name);
	author.age = age;
}

void InitBook(Book& book, char* title, const Author& author, const Genre& genre, size_t ISBN, size_t numberOfPages, double price)
{

	mystrcpy(book.title, title);
	InitAuthor(book.author, author.name, author.age);
	book.genre = genre;
	book.ISBN = ISBN;
	book.numberOfPages = numberOfPages;
	book.price = price;
}

void PrintAuthor(const Author& author)
{
  cout << "Author name: " << author.name << endl;
  cout << "Age: " << author.age << endl;
}

void PrintBook(const Book& book)
{
  cout << "Title: " << book.title << endl;
  PrintAuthor(book.author);
  cout << "Book genre: " << book.genre << endl;
  cout << "ISBN: " << book.ISBN << endl;
  cout << "Number of pages: " << book.numberOfPages << endl;
  cout << "Price: " << book.price << endl;
}

bool HaveSameAuthor(const Book& b1, const Book& b2)
{
  if((strcmp(b1.author.name, b2.author.name) == 0) && (b1.author.age == b2.author.age))
    return true;
  else
    return false;
}

double TotalBookPrice(const Book* books, int size)
{
  double total = 0;
  for(int i = 0; i < size; i++)
    total += books[i].price;

  return total;
}

const Book GetCheapestBook(const Book* books, int size)
{
  int index = 0;
  for(int i = 1; i < size; i++)
  {
    if(books[i].price < books[index].price)
      index = i;
  }

  return books[index];
}

int BooksFromSameGenre(const Book* books, int size, Genre genre)
{
  int count = 0;
  for(int i = 0; i < size; i++)
  {
    if(books[i].genre == genre)
      count++;
  }

  return count;
}

const Book BookWithMostPages(const Book* books, int size)
{
  int index = 0;
  for(int i = 1; i < size; i++)
  {
    if(books[i].numberOfPages > books[index].numberOfPages)
      index = i;
  }

  return books[index];
}

int CheckByISBN(const Book* books, int size, size_t ISBN)
{
  for(int i = 0; i < size; i++)
  {
    if(books[i].ISBN == ISBN)
      return i;
  }

  return -1;
}

int main()

{
	Author author;
	InitAuthor(author, "Bob", 32);

	Book book;
	InitBook(book, "The Book", author, Adventure, 12345, 200, 12.99);

    PrintBook(book);

	return 0;
}
