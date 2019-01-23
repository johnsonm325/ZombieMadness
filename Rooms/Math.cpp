#include "Math.h"


Math::Math() : Space("Math")
{
	
}


int Math::menu(vector<string> *i)
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


void Math::inspectToilet()
{

}


bool Math::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Math::coltGone()
{
	return goneColt;
}


bool Math::itemSearch(vector<string> inv, string a)
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
