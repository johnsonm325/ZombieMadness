#include "MensBathroom.h"


MensBathroom::MensBathroom() : Space("Men's Bathroom")
{
	
}


/****************************************************************************************************
**							Menu function for the story room class
****************************************************************************************************/
int MensBathroom::menu(vector<string> *i)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "********************************************************************************" << endl;
		cout << "* You enter a long room, lit with what seem to be torches that have been burning" << endl;
		cout << "* for thousands of years. There are markings across the wall, none of which you" << endl;
		cout << "* can make out, but the text itself seems evil." << endl;
		cout << "*" << endl;

		cout << "* There's a rancid odor that permeates the air. You can't tell if it's just in" << endl;
		cout << "* this room, or if the entire dungeon is filled with the stench. Whatever it is" << endl;
		cout << "* it's been here for a very long time." << endl;
		cout << "*" << endl;

		cout << "* Further inspection of the room uncovers a chest with a keyhole, and a scroll" << endl;
		cout << "* neatly placed on a pedestal in the middle of the room." << endl;
		cout << "*" << endl;
		cout << "********************************************************************************" << endl;
		cout << endl;
	}


	/*************************************************
	* If the player does not have the key that is
	* in the chest, then it prints the menu with the
	* chest closed.
	*************************************************/
	if (hasFinalKey() == false)
	{
		cout << "********************************************************************************" << endl;
		cout << "* You're in the story room" << endl;
		cout << "*" << endl;

		cout << "* What will you do?" << endl;
		cout << "*" << endl;

		cout << "* 1: Go to the next room" << endl;
		cout << "* 2: Go back to the previous room" << endl;
		cout << "* 3: Open the chest" << endl;
		cout << "* 4: Read the scroll" << endl;
		cout << "* 5: Exit game" << endl;
		cout << "********************************************************************************" << endl;
		cout << endl;

		do
		{
			cout << "Choose an option: " << endl;
			choice = inputVal1.isPosInteger();
		} while (choice > 5 || choice < 1);

		if (choice == 1)
		{
			return 1;
		}

		else if (choice == 2)
		{
			return 2;
		}

		else if (choice == 3)
		{
			// Checks to see if the item is in the inventory, which was passed to the function
			if (itemSearch(*i, "aKey") == true)
			{
				// If so, it will call the openChest function and return a value to add
				// The final key to the inventory
				openChest(*i);
				return 10;
			}
			else
			{
				cout << "The chest is locked." << endl;
			}
		}

		// Calls the function to read the scroll
		else if (choice == 4)
		{
			readScroll();
		}

		// Exits the game
		else
		{
			return 50;
		}
	}


	/*************************************************
	* If the player has the key in the chest then the
	* program shows that the chest is already open
	*************************************************/
	else if (hasFinalKey() == true)
	{
		cout << "********************************************************************************" << endl;
		cout << "* What will you do?" << endl;
		cout << "*" << endl;
		cout << "* 1: Go to the next room" << endl;
		cout << "* 2: Go back to the previous room" << endl;
		cout << "* 3: Inspect empty chest" << endl;
		cout << "* 4: Read the scroll" << endl;
		cout << "* 5: Exit game" << endl;
		cout << "********************************************************************************" << endl;
		cout << endl;

		do
		{
			cout << "Choose an option: " << endl;
			choice = inputVal1.isPosInteger();
		} while (choice > 5 || choice < 1);

		if (choice == 1)
		{
			return 1;
		}

		else if (choice == 2)
		{
			return 2;
		}

		// Prints that the chest is already opened
		else if (choice == 3)
		{
			cout << "You've already gotten the key" << endl;
			cout << "The chest is empty" << endl;
		}

		else if (choice == 4)
		{
			readScroll();
		}

		else
		{
			return 50;
		}
	}
}


/****************************************************************************************************
**							Prints the contents of the scroll
****************************************************************************************************/
void StoryRoom::readScroll()
{
	cout << "#####################################################################################################" << endl;
	cout << "~ Welcome to Amul Ghul, your new vacation destination!" << endl;
	cout << "~" << endl;
	cout << "~ For 20,000 years, Amul Ghul has been a hot destination for instructors and TAs." << endl;
	cout << "~ While your circumstances are less than ideal, we hope your stay is a pleasant one." << endl;
	cout << "~ There's lots to do in Amul Ghul. Two rooms over, you can enjoy the company of a" << endl;
	cout << "~ fire-breathing dragon. He's actually quite nice, just don't say anything to upset him." << endl;
	cout << "~ There's also a lonely old man just 4 rooms over. To be honest, we don't know what he's" << endl;
	cout << "~ ever talking about, but if you manage to survive, I imagine you'll be just like him in" << endl;
	cout << "~ about 5,000 years." << endl;
	cout << "~" << endl;
	cout << "~ This room houses a few secrets of its own, just be careful when you open the chest!" << endl;
	cout << "~" << endl;
	cout << "~ All in all, it's not a bad place. We hope you enjoy your stay!" << endl;
	cout << "~" << endl;
	cout << "~ P.S. There are towels in the room with the locked door." << endl;
	cout << "#####################################################################################################" << endl;
}


/****************************************************************************************************
**							opens the chest by setting finalKey to true
**			Performs actions based on items in inventory, including a 50% chance to summon Muk
****************************************************************************************************/
void StoryRoom::openChest(vector<string> inv)
{
	// Looks for aKey and oldBoneKey in inventory
	if (itemSearch(inv, "aKey") == true && itemSearch(inv, "oldBoneKey") == true)
	{
		// If they are true, then finalKey is set
		cout << "You found a key!" << endl;
		setFinalKey();
	}

	// If not, then a random number is chosen and Muk may or may not be summoned
	else
	{
		int chance = rand() % 2 + 1;

		if (chance == 1)
		{
			fightMuk();
			if (goneMuk == true)
			{
				setFinalKey();
			}
		}
		else
		{
			cout << "You found a key!" << endl;
			setFinalKey();
		}
	}
}


/****************************************************************************************************
**				Sets finalKey to true to tell program that the player has the finalKey
****************************************************************************************************/
void StoryRoom::setFinalKey()
{
	finalKey = true;
}


/****************************************************************************************************
**							Return bool value of finalKey
****************************************************************************************************/
bool StoryRoom::hasFinalKey()
{
	return finalKey;
}


/****************************************************************************************************
**					Sets and returns if it's the players first time in the room
****************************************************************************************************/
bool StoryRoom::firstTime()
{
	firstTry = false;
	return firstTry;
}


/****************************************************************************************************
**						Fight Muk. Used battle system from project three
****************************************************************************************************/
void StoryRoom::fightMuk()
{
	Muk muk;

	int playerTurn = rand() % 2 + 1;
	int roundNumber = 1;

	if (playerTurn == 1)
	{
		cout << "Sir Edward Francis III goes first" << endl << endl;
		// Starts do/while loop that ends when one player's strength points goes below 1
		do
		{
			cout << "**********************************************" << endl;
			cout << "Round number: " << roundNumber << endl;
			cout << "**********************************************" << endl << endl;
			cout << "Sir Edward Francis III: " << endl;
			cout << character.getType() << " ";
			// Player 1 attacks and stores in variable
			attack = character.attack();
			cout << muk.getType() << " ";
			// Player 2 defends against attack
			muk.defend(attack);
			// Prints remaining strength points of player 2
			if (muk.getHitPoints() < 0)
			{
				cout << muk.getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << muk.getType() << " has " << muk.getHitPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			// Breaks to the end of the loop if strength is below 1
			if (muk.getHitPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Sir Edward Francis III won" << endl;
				cout << "Sir Edward Francis III drinks a potion and regains his full health" << endl << endl;
				// Sets Muk to dead
				goneMuk = true;
				break;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			cout << "Muk: " << endl;
			cout << muk.getType() << " ";
			// Player 2 attacks and stores in variable
			attack = muk.attack();
			cout << character.getType() << " ";
			// Player 1 defends against attack
			character.defend(attack);
			// Prints remaining strength points of player 1
			if (character.getHitPoints() < 0)
			{
				cout << character.getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << character.getType() << " has " << character.getHitPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			// Breaks to the end of the loop if strength is below 1
			if (character.getHitPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Muk won" << endl << endl;
				// Sets Edward to dead
				goneEdward = true;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			// Increments round number
			roundNumber++;
		} while (character.getHitPoints() > 0 && muk.getHitPoints() > 0);
	}

	// Same as do/while loop above, but in reverse, allowing player 2 to go first
	if (playerTurn == 2)
	{
		cout << "Muk goes first" << endl << endl;
		do
		{
			cout << "**********************************************" << endl;
			cout << "Round number: " << roundNumber << endl;
			cout << "**********************************************" << endl << endl;
			cout << "Muk: " << endl;
			cout << muk.getType() << " ";
			attack = muk.attack();
			cout << character.getType() << " ";
			character.defend(attack);
			if (character.getHitPoints() < 0)
			{
				cout << character.getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << character.getType() << " has " << character.getHitPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			if (character.getHitPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Muk won" << endl << endl;
				goneEdward = true;
				break;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			cout << "Sir Edward Francis III: " << endl;
			cout << character.getType() << " ";
			attack = character.attack();
			cout << muk.getType() << " ";
			muk.defend(attack);
			if (muk.getHitPoints() < 0)
			{
				cout << muk.getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << muk.getType() << " has " << muk.getHitPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			if (muk.getHitPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Sir Edward Francis III won" << endl;
				cout << "Sir Edward Francis III drinks a potion and regains his full health" << endl << endl;
				goneMuk = true;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			roundNumber++;
		} while (character.getHitPoints() > 0 && muk.getHitPoints() > 0);
	}
}


/****************************************************************************************************
**										Returns Muk status
****************************************************************************************************/
bool StoryRoom::mukGone()
{
	return goneMuk;
}


/****************************************************************************************************
**									Returns Edward status
****************************************************************************************************/
bool StoryRoom::edwardGone()
{
	return goneEdward;
}


/****************************************************************************************************
**							Searches passed inventory for passed item
****************************************************************************************************/
bool StoryRoom::itemSearch(vector<string> inv, string a)
{
	for (int i = 0; i < inv.size(); i++)
	{
		if (a == inv[i])
		{
			return true;
		}
	}
	return false;
}
