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
	return 0;
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
	return false;
}
