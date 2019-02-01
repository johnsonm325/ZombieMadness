#include "Cafeteria.h"


Cafeteria::Cafeteria() : Space("Cafeteria")
{
	
}


int Cafeteria::menu(vector<string> *i)
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


void Cafeteria::inspectToilet()
{

}


bool Cafeteria::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Cafeteria::coltGone()
{
	return goneColt;
}


bool Cafeteria::itemSearch(vector<string> inv, string a)
{
	return false;
}
