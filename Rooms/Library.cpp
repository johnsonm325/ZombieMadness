#include "Library.h"


Library::Library() : Space("Library")
{
	
}


int Library::menu(vector<string> *i)
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


void Library::inspectToilet()
{

}


bool Library::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Library::coltGone()
{
	return goneColt;
}


bool Library::itemSearch(vector<string> inv, string a)
{
	return false;
}
