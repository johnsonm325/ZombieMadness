#include "SecondFloorHallway1.h"


SecondFloorHallway1::SecondFloorHallway1() : Space("Second Floor Hallway")
{
	
}


int SecondFloorHallway1::menu(vector<string> *i)
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


void SecondFloorHallway1::inspectToilet()
{

}


bool SecondFloorHallway1::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool SecondFloorHallway1::coltGone()
{
	return goneColt;
}


bool SecondFloorHallway1::itemSearch(vector<string> inv, string a)
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
