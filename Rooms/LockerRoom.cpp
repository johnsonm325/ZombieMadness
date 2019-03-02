#include "LockerRoom.h"

LockerRoom::LockerRoom() : Space("Locker Room")
{
	this->roomInventory->addItem(new BaseballBat());
	this->roomInventory->addItem(new SteelLid());

	jockstrap = new Item();
	string description = "# A worn out and stained jockstrap is hanging on the edge of the bench.";
	string name = "jockstrap";
	jockstrap->setDummyItem(description, name);
	string text = "# You grab the sweaty jockstrap, moist in your hand, and slip it over your pants.\n# The stench rises up to meet your nose. 'I can't wear this. I need to get this\n# thing off.'";
	jockstrap->setAction(text, Wear);
	roomInventory->addItem(jockstrap);

	locker = new Item();
	description = "# A metal locker stands against the wall, doors closed, full of items from one of\n# your fellow students.";
	name = "locker";
	locker->setDummyItem(description, name);
	roomInventory->addItem(locker);
}

LockerRoom::~LockerRoom(){

}

void LockerRoom::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# 'Lots of memories in here getting hyped up for football and basketball games.' You can" << endl;
		cout << "# smell the sweaty jockstraps stored in lockers. Which is actually a plesant smell compared" << endl;
		cout << "# to the decaying and rotting flesh smell that is filling the hallways. 'I might be able" << endl;
		cout << "# to find a few items in here to help me take out these zombies.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Lockers fill the room, lined against all walls and a few rows in the middle of the room. There's a" << endl;
	cout << "# sweaty jockstrap on the bench. A baseball bat is propped against the east wall" << endl;
	cout << "# and a steel lid from a trash can is turned upside down on the floor." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void LockerRoom::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Why did Frank feel it was neccessary to always walk around fully naked in here?" << endl;
		cout << "# There are three ways in and out of this room. One way leads out to the hallway." << endl;
		cout << "#" << endl;
	}

	cout << "# Oddly enough, the literature room is directly accessible from here.  You can also" << endl;
	cout << "# access the 2nd floor of the gym from here, could be useful." << endl;
	cout << "#" << endl;
}

int LockerRoom::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	return 0;
}
