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


bool StoryRoom::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool StoryRoom::coltGone()
{
	return goneColt;
}


bool StoryRoom::itemSearch(vector<string> inv, string a)
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
