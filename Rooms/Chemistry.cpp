#include "Chemistry.h"

Chemistry::Chemistry() : Space("Chemistry")
{
	
}

Chemistry::~Chemistry(){

}

void Chemistry::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# 'Just when I thought chemistry was a useless subject.' You realize that all of your learning may" << endl;
		cout << "# finally pay off. You can access some of that 'useless' knowledge to create some useful items now." << endl;
		cout << "#" << endl;
	}

	cout << "# Beakers, flasks and bunsen burners sit atop tables pushed against the west and east walls and in the" << endl;
	cout << "# center of the room. Various ingredients can be found inside of cabinets set against the south wall." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Chemistry::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Wow, the fact that I managed NOT to blow myself up in there is amazing' you think to yourself." << endl;
		cout << "# You also remember the chemistry room is where you asked out Sophie to prom..." << endl;
		cout << "# Where she said no.........." << endl;
		cout << "# 'I HATE CHEMISTRY!' you declare." << endl;
		cout << "#" << endl;
	}

	cout << "# The hallway that is accessible from the chemistry room is pretty long, rooms like" << endl;
	cout << "# the math room, com sci room, and front lobby are all reachable from here!" << endl;
	cout << "#" << endl;
}

int Chemistry::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}

void Chemistry::zombiesDead()
{
	deadZombies = true;
}

