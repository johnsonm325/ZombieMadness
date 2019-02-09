#include "Literature.h"


Literature::Literature() : Space("Literature")
{
	
}

void Literature::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "To be or not to be, that is the question. 'More like, to get out of here or die!' Maybe that Shakespeare was" << endl;
		cout << "on to something. Perhaps I can find some useful items in here to help me get out of here." << endl;
		cout << endl;
	}

	cout << "Bookshelves line the north and south walls and a chalkboard is mounted on the east wall. The teachers desk" << endl;
	cout << "sits in front of the chalkboard and desks in the middle of the floor face the chalkboard." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int Literature::menu()
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();	
	
	return 0;
}


void Literature::zombiesDead()
{
	deadZombies = true;
}


void Literature::firstTime()
{
	firstTry = false;
}


bool Literature::coltGone()
{
	return goneColt;
}


bool Literature::itemSearch(vector<string> inv, string a)
{
	return false;
}
