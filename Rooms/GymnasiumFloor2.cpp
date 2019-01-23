#include "GymnasiumFloor2.h"


GymnasiumFloor2::GymnasiumFloor2() : Space("Gymnasium Second Floor")
{
	
}


int GymnasiumFloor2::menu(vector<string> *i)
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


void GymnasiumFloor2::inspectToilet()
{

}


bool GymnasiumFloor2::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool GymnasiumFloor2::coltGone()
{
	return goneColt;
}


bool GymnasiumFloor2::itemSearch(vector<string> inv, string a)
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
