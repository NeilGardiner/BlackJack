//////////////////////////////////////////////
//                BLACKJACK                 //      
//                   BY                     //
//              Neil Gardiner               //
//              Assignment #2               //
//                 VGP142                   //
//////////////////////////////////////////////

//**************DOES NOT RUN****************\\

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

#include "card.h"
#include "deck.h"

using namespace std;

int totalPlayer1 = 0;
int totalPlayer2 = 0;
int totalDealer = 0;

int betAmount = 10;
int p1Purse = 100;
int p2Purse = 100;

void holdCardsP1();
void holdCardsP2();
void winGameP1();
void winGameP2();
void loseGameP1();
void loseGameP2();
void loseHandP1();
void loseHandP2();
void bustP1();
void bustP2();
void dblBet();
void split();
void titlePage(); 
void instructions();

bool player1Turn = true;
bool player2Turn = false;

int main()
{
	srand(time_t(NULL)); // Randomizer or shuffler
	
	Card _card;
	_card.stCard(); // from card.h

	
	Deck _deck;
	_deck.print_Deck(); // from deck.h
	_deck.getOneCard(); // from deck.h

	cout << endl;
	_deck.print_Deck();

	cout << endl;
	cout << " Get Ready To Play!!!!" << endl;

	titlePage();

	system("PAUSE");

	system("CLS");

	setup(); // Game start

	system("PAUSE");

	return 0;
}
void setup()
{
	string name;
	int totalDealer, totalPlayer1, totalPlayer2, c1, c2, c3, c4, c5, p1, p2, p3, p4, p5, d1, d2, d3, d4, d5;
	char choice;

	
	

	cout << "Welcome to blackjack \nA Game By Neil Gardiner \nPlease enter your name: "<< endl;
	cin >> name;
	cout << "Thank You " << name << " Lets Play BLACKJACK!!!" << endl;
	cout << "Today you will be playing as two players vs the Dealer as Neil cannot program what he wants just yet" << endl;

	cout << "\n";

	
	
	//Dealing
	/*c1 = _deck.getOneCard().; // m_deck[i].stCard().rank possibly?? I have tried a few and I am missing the connection or if it can be done
	c2 = _deck.getOneCard();
	c3 = _deck.getOneCard();
	p1 = _deck.getOneCard();
	p2 = _deck.getOneCard();
	p3 = _deck.getOneCard();
	d1 = _deck.getOneCard();
	d2 = _deck.getOneCard();
	d3 = _deck.getOneCard();
	*/

	totalPlayer1 = c1 + c2;
	totalPlayer2 = p1 + p2;
	totalDealer = d1 + d2;

	cout << "Player 1: " << totalPlayer1 << endl;

	cout << "Player 2: " << totalPlayer2 << endl;

	cout << "Dealer: " << totalDealer << endl;

	cout << " Dealers has: " << totalDealer << endl;

	player1Turn = true;
	{
		betAmount++;

		cout << "Player 1 has: " << totalPlayer1 << ". Player 1 - Would you like to Hit (h) or Stand (s)????" << endl;

		cin >> choice;

		if (choice == 'h') //anything other than h will else
		{
			//cout << _deck.getOneCard(); // Broken!!!!! Not correct at all but what I thought I wanted says undefined but it is 
			cout << "Player 1's new total is: " << totalPlayer1 + c3 << endl;
		}
		else
		{
			holdCardsP1();
			player2Turn = true;
		}

		cout << "Player 1 - Would you like to Hit(h) or Stand(s) ? ? ? ? " << endl;

		cin >> choice;

		if (choice == 'h')
		{
			cout << "Player 1's new total is: " << totalPlayer1 + c3 + c4 << endl;
		}
		else
		{
			holdCardsP1();
			player2Turn = false;
		}
		cout << "Player 1 - Would you like to Hit(h) or Stand(s) ? ? ? ? " << endl;

		cin >> choice;

		if (choice == 'h')
		{
			cout << "Player 1's new total is: " << totalPlayer1 + c3 + c4 + c5 << endl;

			if (totalPlayer1 >= 22)
			{
				bustP1();
				player2Turn = true;
			}
		}
		else
		{
			holdCardsP1();
			player2Turn = true;
		}
		cout << "Player 1, you have reached your maximum amount of plays" << endl;
	}

	
	//// Player 2 start 
	
	player2Turn = true;

	cout << "Player 2 has: " << totalPlayer2 << ". Player 2 - Would you like to Hit (h) or Stand (s)????" << endl;

		 cin >> choice;

		 if (choice == 'h') // Tried a few syntax but no love
		 {
			 //cout << _deck.getOneCard(); // Broken!!!!! Not correct at all but what I thought I wanted //goc.stCard()
			 cout << "Player 2's new total is: " << totalPlayer2 + p3 << endl;
		 }
		 else
		 {
			 holdCardsP2();
			 player2Turn = false;
		 }

	cout << "Player 2 - Would you like to Hit(h) or Stand(s) ? ? ? ? " << endl;

		 cin >> choice;

		 if (choice == 'h')
		 {
			 cout << "Player 2's new total is: " << totalPlayer2 + p3 + p4 << endl;
			 if (totalPlayer2 >= 22)
			 {
				 loseHandP2();
			 }
		 }
		 else
		 {
			 holdCardsP2();
			 player2Turn = false;
		 }
	cout << "Player 2 - Would you like to Hit(h) or Stand(s) ? ? ? ? " << endl;

		 cin >> choice;

		 if (choice == 'h')
		 {
			 cout << "Player 2's new total is: " << totalPlayer1 + p3 + p4 + p5 << endl;

			 if (totalPlayer2 >= 22)
			 {
				 bustP2();
				 player2Turn = false;
			 }
		 }
		 else
		 {
			 holdCardsP2();
			 player2Turn = false;
		 }
	cout << "Player 2, you have reached your maximum amount of plays" << endl;

	if (totalDealer > totalPlayer1|| totalDealer > totalPlayer2) // Handles a double loss condition
	{
		cout << "Dealer got you both" << endl;

	}
	else if (totalPlayer1 > totalDealer || totalPlayer2 <= '21')
	{
		winGameP1;
	}
	else if (totalPlayer2 < totalDealer || totalPlayer2 <= '21')
	{
		winGameP2;
	}
}

void holdCardsP1()
{
	//Do Nothing
	player2Turn = true;
}

void holdCardsP2()
{
	//Do Nothing
	player1Turn = true;
}

void winGameP1()
{
	p1Purse + 10;

	if (p1Purse >= 500)
	{
		cout << "You took all our money you filthy animal!!!!" << endl;
		cout << "See you next time :)" << endl;

		system("pause");

		exit;
	}
}

void winGameP2()
{
	p2Purse + 10;

	if (p2Purse >= 500)
	{
		cout << "You took all our money you filthy animal!!!!" << endl;
		cout << "See you next time :)" << endl;

		system("pause");

		exit;
	}
}

void loseHandP1()
{
	if (totalDealer >= totalPlayer1 && totalPlayer1 <= 22) //Charity rules - no push - works in brain but not in system, somehow std is not being read when it was. checkef or ; missing
	{
		p1Purse - betAmount;
		cout << "You lose this hand" << endl;
	}
}

void loseHandP2()
{
	if (totalDealer >= totalPlayer2 && totalPlayer2 <= 22) //Charity rules - no push - works in brain but not in system, somehow std is not being read when it was. checkef or ; missing
	{
		p2Purse - betAmount;
		cout << "You lose this hand" << endl;
	}
}

void loseGameP1()
{
	if (p1Purse >= 0)
	{
		cout << " You Are Broke. GoodBye!!" << endl;
		
		system("pause");
		
		exit;
	}
}

void loseGameP2()
{
	if (p2Purse >= 0)
	{
		cout << " You Are Broke. GoodBye!!" << endl;

		system("pause");

		exit;
	}
}

void bustP1()
{
	cout << " YOU BUSTED!!!!" << endl;
	p1Purse - betAmount;
}

void bustP2()
{
	cout << " YOU BUSTED!!!!" << endl;
	p2Purse - betAmount;
}

void dblBet()
{
	betAmount * 2;
}

void split()
{
	//
}


void titlePage() // ripped from web alignment off
{
	cout <<  "___                  ___       __________       __               __________       __________       ______________      __________" << endl;
	cout << "\\  \\                /  /     |   _______|     |  |             |   _______|     |   ____   |     |   __    __   |    |   _______|" << endl;
	cout << " \\  \\              /  /      |  |___          |  |             |  |             |  |    |  |     |  |  |  |  |  |    |  |___" << endl;
	cout << "  \\  \\    ____    /  /       |   ___|         |  |             |  |             |  |    |  |     |  |  |__|  |  |    |   ___|" << endl;
	cout << "  \\  \\  /    \\  /  /        |  |             |  |             |  |             |  |    |  |     |  |        |  |    |  |" << endl;
	cout << "  \\  \\/  /\\  \\/  /         |  |_______      |  |_______      |  |_______      |  |____|  |     |  |        |  |    |  |_______" << endl;
	cout << "    \\____/  \\____/           |__________|     |__________|     |__________|     |__________|     |__|        |__|    |__________| " << endl;
	cout << endl << endl;

	cout << "                                         __________________       __________ " << endl;
	cout << "                                        |_______    _______|     |   ____   | " << endl;
	cout << "                                                |  |             |  |    |  | " << endl;
	cout << "                                                |  |             |  |    |  |" << endl;
	cout << "                                                |  |             |  |    |  |" << endl;
	cout << "                                                |  |             |  |____|  |" << endl;
	cout << "                                                |__|             |__________|" << endl;
	cout << endl << endl;

	cout << " _________         __               ________       __________       __   __            __       ________       __________       __   __ " << endl;
	cout << "|   ___   |       |  |             |   __   |     |   _______|     |  | /  /          |  |     |   __   |     |   _______|     |  | /  /" << endl;
	cout << "|  |   |  |       |  |             |  |  |  |     |  |             |  |/  /           |  |     |  |  |  |     |  |             |  |/  /" << endl;
	cout << "|  |___|  |_      |  |             |  |__|  |     |  |             |     /            |  |     |  |__|  |     |  |             |     /" << endl;
	cout << "|   ____    |     |  |             |   __   |     |  |             |     \\      __    |  |     |   __   |     |  |             |     \\" << endl;
	cout << "|  |____|   |     |  |_______      |  |  |  |     |  |_______      |  |\\  \\    |  |___|  |     |  |  |  |     |  |_______      |  |\\  \\" << endl;
	cout << "|___________|     |__________|     |__|  |__|     |__________|     |__| \\__\\   |_________|     |__|  |__|     |__________|     |__| \\__\\" << endl;
}

void instructions()
{
	char choice;

	cout << " Black Jack is a simple game to play \nPlayers will be dealt two cards face up \nIf you get the closest to 21 against the dealer without going over \nYOU WIN!!" << endl;

	cout << " Would you like to play (Y)es or (N)o" << endl;
	
	cin >> choice;

	if (choice == 'Y')
	{ 
		setup();
	}
	else
	{
		exit;
	}
	
}



// FootNotes
/*
http://www.cplusplus.com/reference/cstdlib/exit/
https://mathbits.com/MathBits/CompSci/Introduction/clear.htm
http://www.cplusplus.com/forum/general/120525/ //BlackJack Game much different than mine that I used for reference and help.
https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
http://www.cplusplus.com/reference/vector/vector/pop_back/
http://www.cplusplus.com/reference/vector/vector/back/
*/

