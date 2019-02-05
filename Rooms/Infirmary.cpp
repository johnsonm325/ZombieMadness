#include "Infirmary.h"


Infirmary::Infirmary() : Space("Infirmary")
{
	
}

void Infirmary::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "'I'll never forget the story Jacob told about when he accidently walked into the glass door of the front lobby." << endl;
		cout << "This must be where they bandaged up the cut on his head. He walked around the school for days with that gauze" << endl;
		cout << "on his forehead.'" << endl;
		cout << endl;
	}

	cout << "Lots of medical supplies are neatly tucked into containers and a bed sits along the north wall. 'I might be able to" << endl;
	cout << "find something useful for myself in here.'" << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int Infirmary::menu(vector<string> *i)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	printIntro();
	
	return 0;
}


void Infirmary::inspectToilet()
{

}


bool Infirmary::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Infirmary::coltGone()
{
	return goneColt;
}


bool Infirmary::itemSearch(vector<string> inv, string a)
{
	return false;
}
