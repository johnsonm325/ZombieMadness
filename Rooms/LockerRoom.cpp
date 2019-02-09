#include "LockerRoom.h"


LockerRoom::LockerRoom() : Space("Locker Room")
{
	
}
void LockerRoom::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "'Lots of memories in here getting hyped up for football and basketball games.' You can smell the sweaty jockstraps" << endl;
		cout << "stored in lockers. Which is actually a plesant smell compared to the decaying and rotting flesh smell that is" << endl;
		cout << "filling the hallways. 'I might be able to find a few items in here to help me take out these zombies.'" << endl;
		cout << endl;
	}

	cout << "Lockers fill the room, lined against all walls and a few rows in the middle of the room. Sporting equipment also" << endl;
	cout << "is propped up against the walls and lockers." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int LockerRoom::menu()
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	
	return 0;
}


void LockerRoom::inspectToilet()
{

}


void LockerRoom::firstTime()
{
	firstTry = false;
}


bool LockerRoom::coltGone()
{
	return goneColt;
}


bool LockerRoom::itemSearch(vector<string> inv, string a)
{
	return false;
}
