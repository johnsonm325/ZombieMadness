#include "FrontOffice.h"


FrontOffice::FrontOffice() : Space("Front Office")
{
	
}


int FrontOffice::menu(vector<string> *i)
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
		cout << "As you step in, you hear a sound closeby, you're not sure if it's in the room you are in, or if it's in another." << endl;
		cout << "The stench is strong here though, and it gives you a very uneasy feeling in your stomach." << endl;
		cout << endl;
	}

	cout << "Two desks sit at the north wall, each with a computer." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
	
	return 0;
}


void FrontOffice::inspectToilet()
{

}


bool FrontOffice::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool FrontOffice::coltGone()
{
	return goneColt;
}


bool FrontOffice::itemSearch(vector<string> inv, string a)
{
	return false;
}
