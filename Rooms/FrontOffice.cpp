#include "FrontOffice.h"


FrontOffice::FrontOffice() : Space("Front Office")
{
	
}


int FrontOffice::menu(vector<string> *i)
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


void FrontOffice::inspectToilet()
{

}


bool FrontOffice::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool FrontOffice::coltGone()
{
	return goneColt;
}


bool FrontOffice::itemSearch(vector<string> inv, string a)
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
