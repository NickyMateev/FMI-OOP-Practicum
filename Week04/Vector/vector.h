#include <iostream>
#pragma once
using namespace std;

class Vector
{
  int* container;
  size_t size;
  size_t capacity;

  void Resize(size_t newCapacity);
public:
  Vector();
  Vector(size_t capacity, size_t size = 0);
  Vector(const Vector& otherVector);
  ~Vector();

  void SetAt(int value, size_t index);
  int GetAt(size_t index) const;
  void PushBack(int element);
  void InsertAt(int element, size_t index);
  void DeleteAt(size_t index);

  bool IsEmpty() const;
  size_t Size() const;

  void Sort(bool sortIncreasing = true);
  bool IsSorted() const;
};
