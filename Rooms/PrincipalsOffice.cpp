#include "PrincipalsOffice.h"


PrincipalsOffice::PrincipalsOffice() : Space("Principal's Office")
{
	
}


int PrincipalsOffice::menu(vector<string> *i)
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


void PrincipalsOffice::inspectToilet()
{

}


bool PrincipalsOffice::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool PrincipalsOffice::coltGone()
{
	return goneColt;
}


bool PrincipalsOffice::itemSearch(vector<string> inv, string a)
{
	return false;
}
