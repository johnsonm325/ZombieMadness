#include "FirstFloorHallway1.h"


FirstFloorHallway1::FirstFloorHallway1() : Space("First Floor Hallway")
{
	
}


int FirstFloorHallway1::menu(vector<string> *i)
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


void FirstFloorHallway1::inspectToilet()
{

}


bool FirstFloorHallway1::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool FirstFloorHallway1::coltGone()
{
	return goneColt;
}


bool FirstFloorHallway1::itemSearch(vector<string> inv, string a)
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
