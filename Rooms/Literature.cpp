#include "Literature.h"

Literature::Literature() : Space("Literature")
{
	string description, name, text;
	chalkboard = new Item();
	description = "# The chalkboard looks like it has been freshly cleaned. A few\n# things are written on the board.";
	name = "chalkboard";
	chalkboard->setDummyItem(description, name);
	text = "# In a hole in the ground there lived a hobbit. Not a nasty, dirty, wet\n# hole, filled with the ends of worms and an oozy smell, nor yet a dry, bare, sandy\n# hole with nothing in it to sit down on or to eat: it was a hobbit-hole, and that means\n# comfort.";
	chalkboard->setAction(text, Read);
	roomInventory->addItem(chalkboard);

	desk = new Item();
	description = "# The teacher's desk is quite messy with papers strewn about. There\n# seems to be a note written down on a small slip of paper.";
	name = "desk";
	desk->setDummyItem(description, name);
	roomInventory->addItem(desk);

	this->zombie = new Zombie(false);
}

Literature::~Literature(){

}

void Literature::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		if (zombie->isAlive()) {
			cout << KMAG "# You look across the room and see two zombies that simultaneously look up" << endl;
			cout << "# to notice you. They begin to make a direct move towards you, paying no" << endl;
			cout << "# regard for the desks between you and them." << endl; 
		}
		else {
			cout << KMAG "# To be or not to be, that is the question. 'More like, to get out of" << endl;
			cout << "# here or die!' Maybe that Shakespeare was on to something. Perhaps" << endl;
			cout << "# I can find some useful items in here to help me get out of here." << endl;
			cout << "#" << endl;
		}
	}

	cout << KMAG "# Bookshelves line the north and south walls and a chalkboard is mounted" << endl;
	cout << "# on the east wall. The teachers desk sits in front of the chalkboard" << endl;
	cout << "# and desks in the middle of the floor face the chalkboard." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# Here is a classroom that connects to another room. Some rooms do." << endl;
		cout << "#" << endl;
	}

	cout << "# You can exit to the hallway towards the west, or head south to another room." RESET << endl;
	cout << "#" << endl;

	if (didDieOnEnter)
	{
		cout << KRED "# Oh no! There is a zombie in here and you do not have any weapons to fight it with." << endl;
		cout << "# It is too late to run and the zombie feasted on you, game over!" RESET << endl << endl;
		return;
	}

	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Literature::inspectDesk()
{
	noteVisible = true;

	note = new Item();
	string description = "# A small piece of paper sits in the middle of the desk and has a\n# short note written on it.";
	string name = "note";
	note->setDummyItem(description, name);
	string text = "# Get the sword in the computer science room.";
	note->setAction(text, Read);
	roomInventory->addItem(note);
}

bool Literature::getNoteVisible()
{
	return noteVisible;
}
