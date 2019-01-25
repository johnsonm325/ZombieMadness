#include "Biology.h"


Biology::Biology() : Space("Biology")
{
	
}


int Biology::menu(vector<string> *i)
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


void Biology::inspectToilet()
{

}


bool Biology::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Biology::coltGone()
{
	return goneColt;
}


bool Biology::itemSearch(vector<string> inv, string a)
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