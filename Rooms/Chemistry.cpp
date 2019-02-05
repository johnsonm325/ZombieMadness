#include "Chemistry.h"

Chemistry::Chemistry() : Space("Chemistry")
{
	
}

void Chemistry::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "'Just when I thought chemistry was a useless subject.' You realize that all of your learning may" << endl;
		cout << "finally pay off. You can access some of that 'useless' knowledge to create some useful items now." << endl;
		cout << endl;
	}

	cout << "Beakers, flasks and bunsen burners sit atop tables pushed against the west and east walls and in the" << endl;
	cout << "center of the room. Various ingredients can be found inside of cabinets set against the south wall." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int Chemistry::menu(vector<string> *i)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}

void Chemistry::inspectToilet()
{

}

bool Chemistry::firstTime()
{
	firstTry = false;
	return firstTry;
}

bool Chemistry::coltGone()
{
	return goneColt;
}

bool Chemistry::itemSearch(vector<string> inv, string a)
{
	for (unsigned int i = 0; i < inv.size(); i++)
	{
		if (a == inv[i])
		{
			return true;
		}
	}
	return false;
}
