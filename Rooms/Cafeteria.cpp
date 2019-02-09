#include "Cafeteria.h"

Cafeteria::Cafeteria() : Space("Cafeteria")
{
	food = new Item();
	string description = "There are chunks of food strewn around the room. Some of it is gloopy, and you don't want to touch that. But some, you can pick up.";
	string name = "food";
	food->setDummyItem(description, name);

	roomInventory->addItem(food);
}

void Cafeteria::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "You look around a see a few stray zombies littered throughout the large room. There is a lot of" << endl;
		cout << "space in between them, so taking them out shouldn't be too hard. 'If I'm smart, I may be able to" << endl;
		cout << "avoid them altogether.'" << endl;
		cout << endl;
	}

	cout << "Long lunch tables fill the room and lunch trays are littered on the tables and floor. Food debris is" << endl;
	cout << "thrown about the room." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
}

int Cafeteria::menu()
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}


void Cafeteria::throwFood()
{
	chem = static_cast<Chemistry*>(findRoom("Chemistry"));
	chem->zombiesDead();
}


void Cafeteria::firstTime()
{
	firstTry = false;
}


bool Cafeteria::coltGone()
{
	return goneColt;
}


bool Cafeteria::itemSearch(vector<string> inv, string a)
{
	return false;
}
