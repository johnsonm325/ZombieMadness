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

	else 
	{

	}
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
	for (int i = 0; i < inv.size(); i++)
	{
		if (a == inv[i])
		{
			return true;
		}
	}
	return false;
}
