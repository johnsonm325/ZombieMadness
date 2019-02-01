#include "ComputerScience.h"


ComputerScience::ComputerScience() : Space("Computer Science")
{
	
}


int ComputerScience::menu(vector<string> *i)
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
	}

	return 0;
}


void ComputerScience::inspectToilet()
{

}


bool ComputerScience::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool ComputerScience::coltGone()
{
	return goneColt;
}


bool ComputerScience::itemSearch(vector<string> inv, string a)
{
	return false;
}
