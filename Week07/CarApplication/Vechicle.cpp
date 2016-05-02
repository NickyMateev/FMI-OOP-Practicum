#include "Vechicle.h"

Vechicle::Vechicle(const char* color, const char* model, size_t manufactureYear, size_t seats, size_t maxSpeed)
{
  mystrcpy(this->color, color);
  mystrcpy(this->model, model);
  this->manufactureYear = manufactureYear;
  this->seats = seats;
  this->maxSpeed = maxSpeed;
}

Vechicle::Vechicle(const Vechicle& other)
{
  mystrcpy(color, other.color);
  mystrcpy(model, other.model);
  manufactureYear = other.manufactureYear;
  seats = other.seats;
  maxSpeed = other.maxSpeed;
}

Vechicle& Vechicle::operator=(const Vechicle& other)
{
  if(this != &other)
  {
    if(color)
      delete[] color;
    if(model)
      delete[] model;

    mystrcpy(color, other.color);
    mystrcpy(model, other.model);
    manufactureYear = other.manufactureYear;
    seats = other.seats;
    maxSpeed = other.maxSpeed;

  }
  return *this;
}

Vechicle::~Vechicle()
{
  if(color)
    delete[] color;
  if(model)
    delete[] model;
}

const char* Vechicle::getColor() const
{
  return color;
}

const char* Vechicle::getModel() const
{
  return model;
}

size_t Vechicle::getManufactureYear() const
{
  return manufactureYear;
}

size_t Vechicle::getSeats() const
{
  return seats;
}

size_t Vechicle::getMaxSpeed() const
{
  return maxSpeed;
}

void Vechicle::setColor(const char* color)
{
  if(this->color)
    delete[] this->color;

  mystrcpy(this->color, color);
}

void Vechicle::setModel(const char* model)
{
  if(this->model)
    delete[] this->model;

  mystrcpy(this->model, model);
}

void Vechicle::setManufactureYear(size_t manufactureYear)
{
  this->manufactureYear = manufactureYear;
}

void Vechicle::setSeats(size_t seats)
{
  this->seats = seats;
}

void Vechicle::setMaxSpeed(size_t maxSpeed)
{
  this->maxSpeed = maxSpeed;
}
