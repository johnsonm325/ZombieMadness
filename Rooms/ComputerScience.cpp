#include "ComputerScience.h"

ComputerScience::ComputerScience() : Space("Computer Science")
{
	this->roomInventory->addItem(new Sword());
}

void ComputerScience::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Ahh, the nerd class. But, now that I think about it, maybe they would be able to fare better than" << endl;
		cout << "# me right now. I remember hearing that someone had created some sort of program to hack the school" << endl;
		cout << "# infrastructure and mess with the lighting and locks on some of the doors.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Computers fill the room, some of them turned on, and the whiteboard on the north wall has some weird" << endl;
	cout << "# symbols and characters that you don't understand. Must be code." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

int ComputerScience::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}


void ComputerScience::inspectToilet()
{

}


void ComputerScience::firstTime()
{
	firstTry = false;
}


bool ComputerScience::coltGone()
{
	return goneColt;
}


bool ComputerScience::itemSearch(vector<string> inv, string a)
{
	return false;
}
