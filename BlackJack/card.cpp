#include "card.h"

using namespace std;

string SUIT[SUIT_TOTAL] = { "D", "C", "H", "S" };
string RANK[RANK_TOTAL] = { "1","2","3","4","5", "6", "7","8","9","10","11","12","13" };

Card::Card()
{
	m_suit = set_suit();
	m_rank = set_rank();
}

Card::Card(int suit, int rank) // Created by Visual Studio as potential fix
{

}

//Card::Card(int &suit, int &rank) | m_suit(suit), m_rank(rank) // I broke this somehow and no idea what
//{

//}

int Card::set_suit() //Set the suit vale for card
{
	return rand() % (SUIT_TOTAL - 1) + 0;
}
int Card::set_rank()
{
	return rand() % (RANK_TOTAL - 1) + 0;
}
int Card::get_suit()
{
	return m_suit;
}
int Card::get_rank()
{
	return m_rank;
}
string Card::stCard()
{
	return ""; // SUIT[get_suit()] + RANK[get_rank()];
}

/*
// Card values switch from # to char wording
switch (string RANK)
{
case 1:
{
if (int 11)
{
cout << "Jack";
}
}
case 2:
{
if (int 12)
{
cout << "Queen";
}
}
case 3:
{
if (int 13)
{
cout << "King";
}
}
case 4:
{
if (int 1)
{
cout << "Ace";
}
}

default:
break;
}
*/