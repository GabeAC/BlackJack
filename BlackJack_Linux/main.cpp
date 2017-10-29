//@author: Kevin Mitchell (Original Java Program), Gabe Cummings (Converted c++ program)
//@version: 1.0
//Description: 
/*Pseudocode:
*Create private static variables that can be used across all methods
*Create a method to display the game's instructions/rules
*Create a method to draw a new and unused card from the deck
* Create a method to determine the starting value of the dealer's deck
* Create a method to add a new card's value to the dealer's deck
* Create a method to add up the total of the dealer's deck if they want aces to count as 1
* Create a method to add up the total of the dealer's deck if they want aces to count as 11
* Create a method to determine the winner of the round
* Display instructions to user/greet the user
* Get the user's name
* start a while loop in the main method
* reset all values for the user/dealer's deck arrays and running totals
* use the draw card method to draw the first two cards for both user and dealer
* See if the user wants to draw more cards
* keep the loop going until the use no longer wants to draw cards
* now, if the sum of the dealer's initial draws are less than 17, keep drawing more cards until the running total is at least 17
* check to see if the user wants to count aces as 1 or 11 and use the appropriate method for summing their deck
* use the method for seeing who won the round and display the results to the user
* check to see if the user wants to play again, if they do, restart the loop */



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
#include <cmath>

#ifdef _WIN32
#include <Windows.h>
#include <tchar.h>

#define CLEAR "cls"
#endif

// gotta get that linux support boiii
#ifdef linux
#include <cstdio>

#define CLEAR "clear"
#endif


using namespace std;



string deck[52] = { "2 of hearts","3 of hearts","4 of hearts","5 of hearts","6 of hearts","7 of hearts","8 of hearts","9 of hearts",
"10 of hearts","jack of hearts","queen of hearts","king of hearts","ace of hearts",
"2 of diamonds","3 of diamonds","4 of diamonds","5 of diamonds","6 of diamonds","7 of diamonds","8 of diamonds","9 of diamonds",
"10 of diamonds","jack of diamonds","queen of diamonds","king of diamonds","ace of diamonds",
"2 of clubs","3 of clubs","4 of clubs","5 of clubs","6 of clubs","7 of clubs","8 of clubs","9 of clubs",
"10 of clubs","jack of clubs","queen of clubs","king of clubs","ace of clubs",
"2 of spades","3 of spades","4 of spades","5 of spades","6 of spades","7 of spades","8 of spades","9 of spades",
"10 of spades","jack of spades","queen of spades","king of spades","ace of spades" };


int playerTotal = 0;
int dealerTotal = 0;
vector <string> playerDeck;
vector <string> dealerDeck;


bool in_array(const std::string &value, const std::vector<string> &array)
{
	return std::find(array.begin(), array.end(), value) != array.end();
}

//A method to make typing out print statements faster
void print(std::string whatToPrint) {
	std::cout << whatToPrint << std::endl;
}
void print(int whatToPrint) {
	std::cout << whatToPrint << std::endl;
}


//A method for determining the starting deck value of the dealer
void startingValueDealer() {
	std::string tempCard = "";
	for (int i = 0; i < 2; i++) {
		tempCard = dealerDeck[i];
		if (tempCard.find("2") != string::npos) {
			dealerTotal += 2;
		}
		else if (tempCard.find("3") != string::npos) {
			dealerTotal += 3;
		}
		else if (tempCard.find("4") != string::npos) {
			dealerTotal += 4;
		}
		else if (tempCard.find("5") != string::npos) {
			dealerTotal += 5;
		}
		else if (tempCard.find("6") != string::npos) {
			dealerTotal += 6;
		}
		else if (tempCard.find("7") != string::npos) {
			dealerTotal += 7;
		}
		else if (tempCard.find("8") != string::npos) {
			dealerTotal += 8;
		}
		else if (tempCard.find("9") != string::npos) {
			dealerTotal += 9;
		}
		else if (tempCard.find("ace") != string::npos) {
			dealerTotal += 11;
		}
		else
			dealerTotal += 10;
	}
}

//A method for determining the value of the users deck when aces are 1
void acesAre1() {
	std::string tempCard = "";
	int i = 0;
	int index = 0;
	bool isNotEmpty = true;
	while (isNotEmpty) {
		tempCard = playerDeck[i];
		if (tempCard.find("2") != string::npos) {
			dealerTotal += 2;
		}
		else if (tempCard.find("3") != string::npos) {
			dealerTotal += 3;
		}
		else if (tempCard.find("4") != string::npos) {
			dealerTotal += 4;
		}
		else if (tempCard.find("5") != string::npos) {
			dealerTotal += 5;
		}
		else if (tempCard.find("6") != string::npos) {
			dealerTotal += 6;
		}
		else if (tempCard.find("7") != string::npos) {
			dealerTotal += 7;
		}
		else if (tempCard.find("8") != string::npos) {
			dealerTotal += 8;
		}
		else if (tempCard.find("9") != string::npos) {
			dealerTotal += 9;
		}
		else if (tempCard.find("ace") != string::npos) {
			dealerTotal += 1;
		}
		else
			dealerTotal += 10;
		i++;
		if (playerDeck[i] == "")
			isNotEmpty = false;
	}
}

//A method for determining the value of the users deck when aces are 11
void acesAre11() {
	string tempCard = "";
	int i = 0;
	int index = 0;
	bool isNotEmpty = true;
	while (isNotEmpty) {
		tempCard = playerDeck[i];
		if (tempCard.find("2") != string::npos) {
			playerTotal += 2;
		}
		else if (tempCard.find("3") != string::npos) {
			playerTotal += 3;
		}
		else if (tempCard.find("4") != string::npos) {
			playerTotal += 4;
		}
		else if (tempCard.find("5") != string::npos) {
			playerTotal += 5;
		}
		else if (tempCard.find("6") != string::npos) {
			playerTotal += 6;
		}
		else if (tempCard.find("7") != string::npos) {
			playerTotal += 7;
		}
		else if (tempCard.find("8") != string::npos) {
			playerTotal += 8;
		}
		else if (tempCard.find("9") != string::npos) {
			playerTotal += 9;
		}
		else if (tempCard.find("ace") != string::npos) {
			playerTotal += 11;
		}
		else
			playerTotal += 10;
		i++;
		if (playerDeck[i] == "")
			isNotEmpty = false;
	}
}

//A method to draw a new UNUSED card
std::string drawCard() {
	//Variables********************************
	int cardNumber = 0;
	string tempCard = "";
	bool cardNotUsed = true;
	bool cardVarified = false;
	//*****************************************
	while (cardVarified == false) { //begin new card loop
									//get a card number from 0 to 52 and grab the corresponding card
									//int v1 = rand() % 100;
		cardNumber = (int)(rand() % 52);
		tempCard = deck[cardNumber];

		// verify that the card isn't already taken 
		//Reset to true 
		cardNotUsed = true;
		if (in_array(tempCard, playerDeck) && in_array(tempCard, dealerDeck)) {
			cardNotUsed = false;
		}
		if (cardNotUsed == true)
			cardVarified = true;
		else
			cardVarified = false;
	}//end of new card loop
	return tempCard;
	// string word = wordList[rand() % 4];
}

//A method to display the game's instructions
void displayInstructions() {
	cout << "The goal of the game is to get as close to 21 card points as possible. " << endl
		<< "Having a card total of 21 points results in a win, unless the dealer also has" << endl
		<< "21 points, they automatically lose. If both the dealer and player get over " << endl
		<< "21 card points, it is a tie. Otherwise, whoever is closest to 21 is deemed winner." << endl;
}


//A method for determining the winner of the game 
std::string determineWinner() {
	std::string winner = "";

	if ((playerTotal > 21 && dealerTotal > 21) || (playerTotal == 21 && dealerTotal == 21) || (playerTotal == dealerTotal))
		winner = "tie";
	else if ((playerTotal == 21 && dealerTotal != 21) || (dealerTotal > 21 && (playerTotal < 21 || playerTotal == 21)) || (std::abs(playerTotal - 21) < std::abs(dealerTotal - 21)))
		winner = "player";
	else
		winner = "dealer";

	return winner;

}

int main()
{

	std::string playerName = "";
	int goAgain = 0;
	int cardNumber = 0;
	std::string tempCard = "";
	bool cardNotUsed = true;
	bool cardVarified = false;
	int whichAce = 0;
	std::string winner = "";

	// Update the title of console application

#ifdef _WIN32
	SetConsoleTitle(_T("Black Jack"));
#elif __linux__ 
	//nothing
#else

#endif

	//Display instructions to the user
	displayInstructions();


	//Greet the user and get their name 
	std::cout << "\n\nTo begin playing, first enter your name...\n";
	std::cin >> playerName;
	system(CLEAR);
	while (goAgain == 0) { //begin main while loop
						   //Make sure all values are reset
		for (int i = 0; i < 52; i++) {
			dealerDeck.push_back("");
			playerDeck.push_back("");

			//dealerDeck[i] = "";
			//playerDeck[i] = "";
		}
		playerTotal = 0;
		dealerTotal = 0;

		//draw first two cards for player and dealer 
		playerDeck[0] = drawCard();
		dealerDeck[0] = drawCard();
		playerDeck[1] = drawCard();
		dealerDeck[1] = drawCard();

		//Display results to user and see if they want to draw more cards 
		std::cout << "Okay " + playerName + ", looks like you drew a " + playerDeck[0] + " and a " + playerDeck[1] + "." << std::endl;
		std::cout << "Would you like to draw another card? \nEnter 0 to draw again and 1 to end your turn..." << std::endl;
		int drawAgain;
		std::cin >> drawAgain;

		if (drawAgain == 0) {
			int count = 2;
			while (drawAgain == 0) {
				//start counter at 2 since the 0 and 1 index have already been used
				playerDeck[count] = drawCard();
				system(CLEAR);
				std::cout << "\nOkay " + playerName + ", It looks like you drew a " + playerDeck[count] + ", would you like to go again? " << std::endl;
				std::cout << "Enter 0 to draw again or enter 1 to end your turn..." << std::endl;
				std::cin >> drawAgain;
				count++;
			}//end of while loop 
		}//end of if statement 


		 //draw more cards for the dealer
		startingValueDealer();
		if (dealerTotal < 17) {
			while (dealerTotal < 17) {
				//start counter at 2 since the 0 and 1 index have already been used
				int count = 2;
				dealerDeck[count] = drawCard();
				//addNewCard(count);
				count++;
			}//end while
		}//end if

		 //Check to see if the user wants aces to count as 1 or 11
		system(CLEAR);
		print("Would you like to count aces as 1 or 11? \nEnter 1 to count aces as 1 or enter 11 to count aces as 11...");
		int whichAce;
		std::cin >> whichAce;

		if (whichAce == 1)
			acesAre1();
		else if (whichAce == 11)
			acesAre11();

		//Determine winner
		winner = determineWinner();

		system(CLEAR);
		if (winner == "tie")
			std::cout << "\nIt appears we have a tie! The value of " << playerName << "'s deck was: " << playerTotal << "\nAnd the value of the dealer's deck was: " << dealerTotal << std::endl;
		else if (winner == "player")
			std::cout << "\nIt appears that you won! The value of " << playerName << "'s deck was: " << playerTotal << "\nAnd the value of the dealer's deck was: " << dealerTotal << std::endl;
		else
			std::cout << "\nIt appears the dealer won :( The value of " << playerName << "'s deck was: " << playerTotal << "\nAnd the value of the dealer's deck was: " << dealerTotal << std::endl;


		//see if the user would like to play again
		print("Would you like to play again " + playerName + "? \nEnter 0 to play again or enter 1 to quit the program...");
		int goAgain;
		std::cin >> goAgain;

		if (goAgain != 0)
			print("Thanks for playing!");

		std::cin.get();
		return 0;
	}
}