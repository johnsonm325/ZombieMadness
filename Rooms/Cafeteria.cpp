#include "Cafeteria.h"


Cafeteria::Cafeteria() : Space("Cafeteria")
{
	
}


int Cafeteria::menu(vector<string> *i)
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
		cout << "You look around a see a few stray zombies littered throughout the large room. There is a lot of" << endl;
		cout << "space in between them, so taking them out shouldn't be too hard. 'If I'm smart, I may be able to" << endl;
		cout << "avoid them altogether.'" << endl;
		cout << endl;
	}

	cout << "Long lunch tables fill the room and lunch trays are littered on the tables and floor. Food debris is" << endl;
	cout << "thrown about the room." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	
	return 0;
}


void Cafeteria::inspectToilet()
{

}


bool Cafeteria::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Cafeteria::coltGone()
{
	return goneColt;
}


bool Cafeteria::itemSearch(vector<string> inv, string a)
{
	return false;
}
