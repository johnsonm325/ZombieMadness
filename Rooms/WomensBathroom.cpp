#include "WomensBathroom.h"


WomensBathroom::WomensBathroom() : Space("Women's Bathroom")
{
	
}


int WomensBathroom::menu(vector<string> *i)
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


void WomensBathroom::inspectToilet()
{

}


bool WomensBathroom::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool WomensBathroom::coltGone()
{
	return goneColt;
}


bool WomensBathroom::itemSearch(vector<string> inv, string a)
{
	return false;
}
