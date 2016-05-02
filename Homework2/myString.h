#pragma once
#include <iostream>
using namespace std;

class String
{
private:
  char* data;
  int length;
  int myStrLen(const char* data);
  void myStrCpy(char*& destination, char* source);
  int myStrCmp(const char* str1, const char* str2);
  void myStrCat(char*& str1, const char* str2);
public:
  String();
  String(char* data);
  String(const String& other);
  String& operator=(const String& other);
  ~String();

  char at(size_t index);

  size_t size() const;

  char& operator[](size_t index);
  const char operator[](size_t index) const;

  String& operator+=(const String& rhs);

  bool operator<(const String& rhs);
  bool operator>(const String& rhs);
  bool operator<=(const String& rhs);
  bool operator>=(const String& rhs);

  bool operator==(const String& rhs);
  bool operator!=(const String& rhs);

  friend String operator+(const String& lhs, const String& rhs);
  friend ostream& operator<<(ostream& os, const String& obj);
  friend istream& operator>>(istream& is, String& obj);
};
