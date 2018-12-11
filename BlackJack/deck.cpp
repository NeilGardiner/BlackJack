#include "deck.h"
#include "card.h"

using namespace std;

Deck::Deck()
{
	for (int s(0); s < SUIT_TOTAL; s++)
	{
		for (int r(0); r < RANK_TOTAL; r++) // Telling me undeclared but says declared when mouseOver 
		{
			Card card(s, r);
			m_deck.push_back(card);
		}
	}
}

void Deck::print_Deck()
{
	int count(1);

	for (int i(0); i < m_deck.size(); i++)
	{
		cout << m_deck[i].stCard() << " ";
		if (count = 13)
		{
			cout << endl;
			count = 0;
		}
		++count;
	}
}

void Deck::getOneCard() // 
{
	Card goc(m_deck.back().get_suit(), m_deck.back().get_rank()); // (.back) Returns a reference to the last element in the vector.
	m_deck.pop_back(); // (.pop_back) Removes the last element in the vector, effectively reducing the container size by one.

	cout << goc.stCard() << endl;

}