#include "FrontLobby.h"


FrontLobby::FrontLobby() : Space("Front Lobby")
{
	
}


int FrontLobby::menu(vector<string> *i)
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


void FrontLobby::inspectToilet()
{

}


bool FrontLobby::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool FrontLobby::coltGone()
{
	return goneColt;
}


bool FrontLobby::itemSearch(vector<string> inv, string a)
{
	return false;
}
