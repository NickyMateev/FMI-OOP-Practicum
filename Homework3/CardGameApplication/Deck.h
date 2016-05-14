#pragma once
#include "Card.h"

const int MAX_CARDS = 10;

class Deck
{
  Card cards[MAX_CARDS];
  int cardsCount;

  void ShiftCards(int index);
  int GetTotalHealthAttackPts(const Deck& deck);
public:
  Deck();
  Deck(const Card* cards, int cardsCount);
  Deck(const Deck& other);
  Deck& operator=(const Deck& other);
  ~Deck();

  void AddCard(const Card& card);
  void RemoveCard(const Card& card);
  void RemoveCard(int index);
  void ModifyCard(const Card& card, int index);

  bool operator==(const Deck& other);
  bool operator!=(const Deck& other);
  bool operator<(const Deck& other);
  bool operator>(const Deck& other);
  bool operator>=(const Deck& other);
  bool operator<=(const Deck& other);

  Deck& operator+=(const Card& card);
  Deck& operator+=(const Deck& deck);

  friend ostream& operator<<(ostream& os, const Deck& deck);
  friend Deck operator+(const Card& card, const Deck& deck);
  friend Deck operator+(const Deck& deck1, const Deck& deck2);

  Card* operator[](int index);

  bool operator&(const Card& card); // checks if the deck contains this card or not
  int operator!();  // returns the current number of cards in the deck
  Card operator~();  // returns the card with maximum attack out of the whole deck
  Deck& operator^(int attackPoints); // adds to the attackPoints of every card in the deck the specified amount
};
