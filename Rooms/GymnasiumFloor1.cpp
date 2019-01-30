#include "GymnasiumFloor1.h"


GymnasiumFloor1::GymnasiumFloor1() : Space("Gymnasium First Floor")
{
	
}


int GymnasiumFloor1::menu(vector<string> *i)
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


void GymnasiumFloor1::inspectToilet()
{

}


bool GymnasiumFloor1::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool GymnasiumFloor1::coltGone()
{
	return goneColt;
}


bool GymnasiumFloor1::itemSearch(vector<string> inv, string a)
{
	return false;
}
