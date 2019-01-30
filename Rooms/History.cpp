#include "History.h"


History::History() : Space("History")
{
	
}


int History::menu(vector<string> *i)
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


void History::inspectToilet()
{

}


bool History::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool History::coltGone()
{
	return goneColt;
}


bool History::itemSearch(vector<string> inv, string a)
{
	return false;
}
