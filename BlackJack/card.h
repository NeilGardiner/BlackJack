#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <stdlib.h>

#include "deck.h"

using namespace std;

#define SUIT_TOTAL 4
#define RANK_TOTAL 13
//const int SUIT_TOTAL(4);
//const int RANK_TOTAL(13);

class Card
{
	friend class Deck; // Deck class needs to access Card class but not vice versa

public:
	Card();
	Card(int suit, int rank);

	string stCard();

private:

	int set_suit(); 
	int set_rank(); 
	int get_suit();
	int get_rank();
	int m_suit;
	int m_rank;
};

#endif // !CARD_H