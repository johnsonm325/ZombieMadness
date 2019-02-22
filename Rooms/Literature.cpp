#include "Literature.h"

Literature::Literature() : Space("Literature")
{
	chalkboard = new Item();
	string description = "# The chalkboard looks like it has been freshly cleaned. A few things are written on the board.";
	string name = "chalkboard";
	chalkboard->setDummyItem(description, name);
	string text = "# In a hole in the ground there lived a hobbit. Not a nasty, dirty, wet hole, filled with the ends of worms and an oozy smell, nor yet a dry, bare, sandy hole with nothing in it to sit down on or to eat: it was a hobbit-hole, and that means comfort.";
	chalkboard->setAction(text, Read);
	roomInventory->addItem(chalkboard);

	desk = new Item();
	description = "# The teacher's desk is quite messy with papers strewn about. There seems to be a note written down on a small slip of paper.";
	name = "desk";
	desk->setDummyItem(description, name);
	roomInventory->addItem(desk);
}

void Literature::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# To be or not to be, that is the question. 'More like, to get out of here or die!' Maybe that Shakespeare was" << endl;
		cout << "# on to something. Perhaps I can find some useful items in here to help me get out of here." << endl;
		cout << "#" << endl;
	}

	cout << "# Bookshelves line the north and south walls and a chalkboard is mounted on the east wall. The teachers desk" << endl;
	cout << "# sits in front of the chalkboard and desks in the middle of the floor face the chalkboard." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

int Literature::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	return 0;
}

void Literature::inspectDesk()
{
	noteVisible = true;

	note = new Item();
	string description = "# A small piece of paper sits in the middle of the desk and has a short note written on it.";
	string name = "note";
	note->setDummyItem(description, name);
	string text = "Get the sword in the computer science room.";
	note->setAction(text, Read);
	roomInventory->addItem(note);
}

void Literature::zombiesDead()
{
	deadZombies = true;
}

bool Literature::coltGone()
{
	return goneColt;
}

bool Literature::itemSearch(vector<string> inv, string a)
{
	return false;
}
