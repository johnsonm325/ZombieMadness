#include "PrincipalsOffice.h"


PrincipalsOffice::PrincipalsOffice() : Space("Principal's Office")
{
	this->roomInventory->addItem(new FireExtinguisher());
}

void PrincipalsOffice::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "As soon as you open the door, you are attacked from the north. You are quick enough to fight off the first push" << endl;
		cout << "as you grab the zombie by the throat and shove it back. As it falls down, you realize it's already working to" << endl;
		cout << "get itself back up. You know you don't have much time." << endl;
		cout << endl;
		cout << "What do you do?" << endl;
		cout << endl;
	}

	if (deadZombies == true)
	{
		cout << "There is a single desk in the room." << endl;
		cout << endl;
		cout << "What do you do?" << endl;
		cout << endl;
	}
}

int PrincipalsOffice::menu()
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}

void PrincipalsOffice::zombiesDead()
{
	deadZombies = true;
}


void PrincipalsOffice::firstTime()
{
	firstTry = false;
}


bool PrincipalsOffice::coltGone()
{
	return goneColt;
}


bool PrincipalsOffice::itemSearch(vector<string> inv, string a)
{
	return false;
}
