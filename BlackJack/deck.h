#ifndef DECK_H
#define DECK_H

#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include "card.h"

using namespace std;

class Deck
{
	//friend class Card; // Deck class needs to access Card class but not vice versa
public:
	explicit Deck();
	void print_Deck();
	void getOneCard();
	Card myCard;

private:
	//Card myCard;
	vector<Card> m_deck;

};

#endif // !DECK_H