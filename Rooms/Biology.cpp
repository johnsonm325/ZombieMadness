#include "Biology.h"

Biology::Biology() : Space("Biology")
{
	
}

void Biology::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "The room has a lot of plants and cases with dissected animals. 'This was never my favorite subject, but I did enjoy" << endl;
		cout << "cutting open frogs to see what was inside of them." << endl;
		cout << endl;
	}

	cout << "The room has a mixture of desks and tables. There are a good deal of items and tools for gardening." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int Biology::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}


void Biology::inspectToilet()
{

}


void Biology::firstTime()
{
	firstTry = false;
}


bool Biology::coltGone()
{
	return goneColt;
}


bool Biology::itemSearch(vector<string> inv, string a)
{
	return false;
}
