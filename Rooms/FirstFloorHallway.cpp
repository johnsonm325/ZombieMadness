#include "FirstFloorHallway.h"


FirstFloorHallway::FirstFloorHallway() : Space("First Floor Hallway")
{
	
}

FirstFloorHallway::FirstFloorHallway(bool firstTry) : Space("First Floor Hallway")
{
	this->firstTry = firstTry;
}


void FirstFloorHallway::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# This hallway doesn't look much better than the second floor. Blood is smeared everywhere and there are half-eaten" << endl;
		cout << "# bodies, and some with just holes chewed into their stomachs, just lying along the hallway. You wrench at the sight" << endl;
		cout << "# and throw up on the floor. These are people you went to school with and sat beside everyday. You finally steel your" << endl;
		cout << "# will and determine to move on." << endl;
		cout << "#" << endl;
	}

	cout << "# There are bulletin boards lining the walls and school supplies scattered about the hallway." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void FirstFloorHallway::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# The first floor hallway is really useful in that it is connected to a lot of other rooms." << endl;
		cout << "# Just be watch your step for that vomit you just beautifully spewed out.... gross." << endl;
		cout << "#" << endl;
	}

	cout << "# Keep in mind how many different rooms can be visited from the first floor hallway!" << endl;
	cout << "#" << endl;
}

int FirstFloorHallway::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}


void FirstFloorHallway::inspectToilet()
{

}


void FirstFloorHallway::firstTime()
{
	firstTry = false;
}


bool FirstFloorHallway::coltGone()
{
	return goneColt;
}


bool FirstFloorHallway::itemSearch(vector<string> inv, string a)
{
	return false;
}
