#include "LockerRoom.h"


LockerRoom::LockerRoom() : Space("Locker Room")
{
	
}


int LockerRoom::menu(vector<string> *i)
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


void LockerRoom::inspectToilet()
{

}


bool LockerRoom::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool LockerRoom::coltGone()
{
	return goneColt;
}


bool LockerRoom::itemSearch(vector<string> inv, string a)
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
