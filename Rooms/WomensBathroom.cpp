#include "WomensBathroom.h"


WomensBathroom::WomensBathroom(PlayerInventory *bag) : Space("Women's Bathroom")
{
	this->bag = bag;
}

void WomensBathroom::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# Well, you've never been in here before. The forbidden zone. 'The guys will love to hear this story.'" << endl;
		cout << "# The air smells fresh in here; not like the urine stench you're accustomed to. 'They have A COUCH?!'" << endl;
		cout << "# You see magazines, a hair dryer, and other various pampering items lined up across the sink counter." << endl;
		cout << "# 'This place is unbelievable. We've been missing out on so much.' You take a moment to breath in the" << endl;
		cout << "# air and check out the scene. 'Ok, time to move on.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Sinks stand on the west wall and stalls line the east wall." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

int WomensBathroom::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 0;
	}
	printIntro();
	return 0;
}


void WomensBathroom::inspectToilet()
{

}


void WomensBathroom::firstTime()
{
	firstTry = false;
}


bool WomensBathroom::coltGone()
{
	return goneColt;
}


bool WomensBathroom::itemSearch(vector<string> inv, string a)
{
	return false;
}

void WomensBathroom::increaseBagSize()
{
	bag->increaseSize();
}
