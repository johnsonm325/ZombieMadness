#include "Infirmary.h"


Infirmary::Infirmary() : Space("Infirmary")
{
	
}


int Infirmary::menu(vector<string> *i)
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


void Infirmary::inspectToilet()
{

}


bool Infirmary::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Infirmary::coltGone()
{
	return goneColt;
}


bool Infirmary::itemSearch(vector<string> inv, string a)
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
