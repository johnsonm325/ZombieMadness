#include "MensBathroom.h"


MensBathroom::MensBathroom() : Space("Men's Bathroom")
{
	
}


int MensBathroom::menu(vector<string> *i)
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


void MensBathroom::inspectToilet()
{

}


bool MensBathroom::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool MensBathroom::coltGone()
{
	return goneColt;
}


bool MensBathroom::itemSearch(vector<string> inv, string a)
{
}
