#include "PrincipalsOffice.h"


PrincipalsOffice::PrincipalsOffice() : Space("Principal's Office")
{
	string description, name, text;

	key = new Key();
	fireExt = new FireExtinguisher();

	//Setting dummy items
    desk = new Item();
	description = "# A wooden desk in Principal's office, with a couple unlocked drawers. Examine it closer and you may find new clues on your next plan of action!";
	name = "desk";
	text = "# You've opened the desk's drawer...Inside, you can see a shiny brass key.";
	desk->setDummyItem(description, name);
	desk->setAction(text, Open);
	desk->setFeature();
	
	roomInventory->addItem(fireExt);
	roomInventory->addItem(key);
	roomInventory->addItem(desk);
}

void PrincipalsOffice::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# As soon as you open the door, you are attacked from the north. You are quick enough to fight off the first push" << endl;
		cout << "# as you grab the zombie by the throat and shove it back. As it falls down, you realize it's already working to" << endl;
		cout << "# get itself back up. You know you don't have much time." << endl;
		cout << "#" << endl;
		cout << "# What do you do?" << endl;
		cout << "#" << endl;
	}

	if (deadZombies == true)
	{
		cout << "# There is a single desk in the room." << endl;
		cout << "#" << endl;
		cout << "# What do you do?" << endl;
		cout << "#" << endl;
	}
}

int PrincipalsOffice::menu(vector<string> commandVector)
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
