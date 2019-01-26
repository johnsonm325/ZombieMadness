#include "SecondFloorHallway.h"


SecondFloorHallway::SecondFloorHallway() : Space("Second Floor Hallway")
{
	
}


int SecondFloorHallway::menu(vector<string> *i)
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


void SecondFloorHallway::inspectToilet()
{

}


bool SecondFloorHallway::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool SecondFloorHallway::coltGone()
{
	return goneColt;
}


bool SecondFloorHallway::itemSearch(vector<string> inv, string a)
{
}
