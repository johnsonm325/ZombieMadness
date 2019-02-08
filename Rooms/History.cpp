#include "History.h"


History::History() : Space("History")
{
	
}

void History::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "Dusty books and pictures of presidents on the wall, must be in history class. 'I've fallen asleep one too many" << endl;
		cout << "times in here. If I have to hear about one more amendment ... Wait, there are more important matters.'" << endl;
		cout << endl;
	}

	cout << "The north and south walls are lined will bookshelves and desks fill the center of the room. A chalkboard is mounted" << endl;
	cout << "on the west wall." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int History::menu()
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	printIntro();
	return 0;
}


void History::inspectToilet()
{

}


bool History::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool History::coltGone()
{
	return goneColt;
}


bool History::itemSearch(vector<string> inv, string a)
{
	return false;
}
