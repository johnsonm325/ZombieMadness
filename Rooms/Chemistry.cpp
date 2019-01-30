#include "Chemistry.h"

Chemistry::Chemistry() : Space("Chemistry")
{
	
}


int Chemistry::menu(vector<string> *i)
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


void Chemistry::inspectToilet()
{

}


bool Chemistry::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Chemistry::coltGone()
{
	return goneColt;
}


bool Chemistry::itemSearch(vector<string> inv, string a)
{
	for (unsigned int i = 0; i < inv.size(); i++)
	{
		if (a == inv[i])
		{
			return true;
		}
	}
	return false;
}
