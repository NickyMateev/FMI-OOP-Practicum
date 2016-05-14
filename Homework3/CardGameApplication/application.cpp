#include <iostream>
#include "Deck.h"

int main()
{
  int size;
  cout << "How many cards do you want to enter? -> ";
  cin >> size;

  Card* cards = new Card[size];
  int healthPts, attackPts;
  for(int i = 0; i < size; i++)
  {
    cout << "Card #" << i + 1 << endl;
    cout << "Health points: ";
    cin >> healthPts;
    cards[i].setMaxHealthPts(healthPts);
    cards[i].setCurHealthPts(healthPts);

    cout << "Attack points: ";
    cin >> attackPts;
    cards[i].setAttackPts(attackPts);
  }
  cout << endl;

  Deck deck(cards, size);
  cout << "Number of cards: " << !deck << endl;
  cout << endl;
  cout << "Card with maximum attack in the deck:" << endl;
  cout << ~deck << endl;
  cout << endl;

  int userInput;
  cout << "Increase every card in the deck's attack points by: ";
  cin >> userInput;
  cout << "Cards in the deck after the increase:" << endl;
  cout << (deck ^ userInput) << endl;

  delete[] cards;
  return 0;
}
