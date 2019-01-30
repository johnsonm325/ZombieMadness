#include "Football.h"


Football::Football() : Space("Football Field")
{
	
}


int Football::menu(vector<string> *i)
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


void Football::inspectToilet()
{

}


bool Football::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Football::coltGone()
{
	return goneColt;
}


bool Football::itemSearch(vector<string> inv, string a)
{
	return false;
}
