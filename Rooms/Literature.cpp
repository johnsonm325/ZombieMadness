#include "Literature.h"

Literature::Literature() : Space("Literature")
{
	chalkboard = new Item();
	string description = "# The chalkboard looks like it has been freshly cleaned. A few\n# things are written on the board.";
	string name = "chalkboard";
	chalkboard->setDummyItem(description, name);
	string text = "# In a hole in the ground there lived a hobbit. Not a nasty, dirty, wet\n# hole, filled with the ends of worms and an oozy smell, nor yet a dry, bare, sandy\n# hole with nothing in it to sit down on or to eat: it was a hobbit-hole, and that means\n# comfort.";
	chalkboard->setAction(text, Read);
	roomInventory->addItem(chalkboard);

	desk = new Item();
	description = "# The teacher's desk is quite messy with papers strewn about. There\n# seems to be a note written down on a small slip of paper.";
	name = "desk";
	desk->setDummyItem(description, name);
	roomInventory->addItem(desk);

	this->zombie = new Zombie(false);
	this->canLeave = false;
}

Literature::~Literature(){

}

void Literature::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		if (deadZombies == false) {
			cout << "# You look across the room and see two zombie that simultaneously look up" << endl;
			cout << "# to notice you. They begin to make a direct move towards you, paying no" << endl;
			cout << "# regard for the desks between you and them." << endl; 
		}
		cout << "# To be or not to be, that is the question. 'More like, to get out of" << endl;
		cout << "# here or die!' Maybe that Shakespeare was on to something. Perhaps" << endl;
		cout << "# I can find some useful items in here to help me get out of here." << endl;
		cout << "#" << endl;
	}

	cout << "# Bookshelves line the north and south walls and a chalkboard is mounted" << endl;
	cout << "# on the east wall. The teachers desk sits in front of the chalkboard" << endl;
	cout << "# and desks in the middle of the floor face the chalkboard." << endl;

	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Literature::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'I'm gonna be able to write the world's best book after surviving this." << endl;
		cout << "# I'll show Van Gogh who is really the best author!... Wait... was Van" << endl;
		cout << "# Gogh an author or artist? ... Man, I should have tried harder." << endl;
		cout << "#" << endl;
		cout << "# There are two doors here that can get me out of the room." << endl;
	}

	cout << "# You remember being able to access the locker room from here as sometimes" << endl;
	cout << "# the sports teams would randomly come in being all obnoxious from there." << endl;
	cout << "# The 2nd floor hallway is right outside too." << endl;
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
	string description = "# A small piece of paper sits in the middle of the desk and has a\n# short note written on it.";
	string name = "note";
	note->setDummyItem(description, name);
	string text = "# Get the sword in the computer science room.";
	note->setAction(text, Read);
	roomInventory->addItem(note);
}

void Literature::zombiesDead()
{
	deadZombies = true;
}

