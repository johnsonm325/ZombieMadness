#include "LockerRoom.h"

LockerRoom::LockerRoom() : Space("Locker Room")
{
	this->roomInventory->addItem(new BaseballBat());
	this->roomInventory->addItem(new SteelLid());

	jockstrap = new Item();
	string description = "# A worn out and stained jockstrap is hanging on the edge of the bench.";
	string name = "jockstrap";
	jockstrap->setDummyItem(description, name);
	string text = "# You grab the sweaty jockstrap, moist in your hand, and slip it over your pants. The stench rises up to meet your nose. 'I can't wear this. I need to get this thing off.'";
	jockstrap->setAction(text, Wear);
	roomInventory->addItem(jockstrap);

	locker = new Item();
	description = "# A metal locker stands against the wall, doors closed, full of items from one of your fellow students.";
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
		cout << "# 'Lots of memories in here getting hyped up for football and basketball games.' You can smell the sweaty jockstraps" << endl;
		cout << "# stored in lockers. Which is actually a plesant smell compared to the decaying and rotting flesh smell that is" << endl;
		cout << "# filling the hallways. 'I might be able to find a few items in here to help me take out these zombies.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Lockers fill the room, lined against all walls and a few rows in the middle of the room. Sporting equipment also" << endl;
	cout << "# is propped up against the walls and lockers." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void LockerRoom::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# Not sure which smell is worse, this one or the Biology room.   My lord," << endl;
		cout << "# it smells like rotting skin that was dipped in super old eggs." << endl;
		cout << "# 'Why did Frank feel it was neccessary to always walk around fully naked in here? C'mon now Frank." << endl;
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
