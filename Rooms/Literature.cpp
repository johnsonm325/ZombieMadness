#include "Literature.h"


Literature::Literature() : Space("Literature")
{
	
}


int Literature::menu(vector<string> *i)
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


void Literature::inspectToilet()
{

}


bool Literature::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Literature::coltGone()
{
	return goneColt;
}


bool Literature::itemSearch(vector<string> inv, string a)
{
	return false;
}
