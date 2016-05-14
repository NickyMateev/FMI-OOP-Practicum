#include "Deck.h"
#include <cassert>

const int MIN_CARDS = 5;

void Deck::ShiftCards(int index)
{
  for(; index < cardsCount - 1; index++)
    cards[index] = cards[index + 1];
}

int Deck::GetTotalHealthAttackPts(const Deck& deck)
{
  int result = 0;
  for(int i = 0; i < deck.cardsCount; i++)
    result += (deck.cards[i].getMaxHealthPts() + deck.cards[i].getAttackPts());

  return result;
}

Deck::Deck()
{
  cardsCount = MIN_CARDS;
}

Deck::Deck(const Card* cards, int cardsCount)
{
  assert(("Maximum number of cards was exceeded!", cardsCount <= MAX_CARDS));
  assert(("Minimum number of cards was not reached!", cardsCount >= MIN_CARDS));

  this->cardsCount = cardsCount;
  for(int i = 0; i < cardsCount; i++)
    this->cards[i] = cards[i];
}

Deck::Deck(const Deck& other)
{
  this->cardsCount = other.cardsCount;
  for(int i = 0; i < this->cardsCount; i++)
    this->cards[i] = other.cards[i];
}

Deck& Deck::operator=(const Deck& other)
{
  if(this != &other)
  {
    this->cardsCount = other.cardsCount;
    for(int i = 0; i < this->cardsCount; i++)
      this->cards[i] = other.cards[i];
  }
  return *this;
}

Deck::~Deck() { }

void Deck::AddCard(const Card& card)
{
  assert(("Maximum number of cards has been reached already!", cardsCount < MAX_CARDS));

  cards[cardsCount] = card;
  cardsCount++;
}

void Deck::RemoveCard(const Card& card)
{
  for(int i = 0; i < cardsCount; i++)
  {
    if(cards[i] == card)
    {
      ShiftCards(i);
      cardsCount--;

      break;
    }
  }
}

void Deck::RemoveCard(int index)
{
  assert(("Invalid index!", index >= 0 && index < cardsCount));

  ShiftCards(index);
  cardsCount--;
}

void Deck::ModifyCard(const Card& card, int index)
{
  assert(("Invalid index!", index >= 0 && index < cardsCount));

  cards[index] = card;
}

bool Deck::operator==(const Deck& other)
{
  if(this->cardsCount != other.cardsCount)
  	return false;

  bool* tempArr = new bool[cardsCount];
  for(int i = 0; i < cardsCount; i++)
    tempArr[i] = false;

  for(int i = 0; i < cardsCount; i++)
  {
    for(int j = 0; j < cardsCount; j++)
    {
      if(tempArr[j])
        continue;
      else if(cards[i] == other.cards[j])
      {
        tempArr[j] = true;
        break;
      }
    }
  }

  for(int i = 0; i < cardsCount; i++)
  {
    if(tempArr[i] == false)
    {
      delete[] tempArr;
      return false;
    }
  }

  delete[] tempArr;
  return true;
}

bool Deck::operator!=(const Deck& other)
{
  return !(*this == other);
}

bool Deck::operator<(const Deck& other)
{
  return GetTotalHealthAttackPts(*this) < GetTotalHealthAttackPts(other);
}

bool Deck::operator>(const Deck& other)
{
  return GetTotalHealthAttackPts(*this) > GetTotalHealthAttackPts(other);
}

bool Deck::operator>=(const Deck& other)
{
  return (*this > other) || (*this == other);
}

bool Deck::operator<=(const Deck& other)
{
  return (*this < other) || (*this == other);
}

ostream& operator<<(ostream& os, const Deck& deck)
{
  for(int i = 0; i < deck.cardsCount; i++)
  {
    os << "Card #" << i + 1 << endl;
    os << deck.cards[i] << endl;
    cout << endl;
  }

  return os;
}

Deck& Deck::operator+=(const Card& card)
{
  AddCard(card);

  return *this;
}

Deck& Deck::operator+=(const Deck& deck)
{
  for(int i = 0; i < deck.cardsCount && cardsCount < MAX_CARDS; i++)
    (*this) += deck.cards[i];

  return *this;
}

Deck operator+(const Card& card, const Deck& deck)
{
  Deck tempDeck(deck);
  tempDeck += card;

  return tempDeck;
}

Deck operator+(const Deck& deck, const Card& card)
{
  Deck tempDeck(deck);
  tempDeck += card;

  return tempDeck;
}

Deck operator+(const Deck& deck1, const Deck& deck2)
{
  Deck tempDeck(deck1);
  tempDeck += deck2;

  return tempDeck;
}

Card* Deck::operator[](int index)
{
  assert(("Invalid index!", index >= 0 && index < cardsCount));

  return &cards[index];
}

bool Deck::operator&(const Card& card)
{
  for(int i = 0; i < cardsCount; i++)
  {
    if(cards[i] == card)
      return true;
  }

  return false;
}

int Deck::operator!()
{
  return cardsCount;
}

Card Deck::operator~()
{
  int index = 0;
  for(int i = 1; i < cardsCount; i++)
  {
    if(cards[index].getAttackPts() < cards[i].getAttackPts())
      index = i;
  }

  return cards[index];
}

Deck& Deck::operator^(int attackPoints)
{
  for(int i = 0; i < cardsCount; i++)
    cards[i].setAttackPts(cards[i].getAttackPts() + attackPoints);

  return *this;
}
