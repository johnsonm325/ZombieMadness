#include "FirstFloorHallway.h"


FirstFloorHallway::FirstFloorHallway() : Space("First Floor Hallway")
{
	
}


int FirstFloorHallway::menu(vector<string> *i)
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


void FirstFloorHallway::inspectToilet()
{

}


bool FirstFloorHallway::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool FirstFloorHallway::coltGone()
{
	return goneColt;
}


bool FirstFloorHallway::itemSearch(vector<string> inv, string a)
{
	return false;
}
