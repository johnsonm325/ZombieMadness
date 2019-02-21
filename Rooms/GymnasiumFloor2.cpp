#include "GymnasiumFloor2.h"

GymnasiumFloor2::GymnasiumFloor2() : Space("Gymnasium Second Floor")
{
	ropes = new Item();
	string description = "# Ropes appear to be strung across the rafters, holding up many of the spotlights and scoreboards.";
	string name = "ropes";
	ropes->setDummyItem(description, name);
	roomInventory->addItem(ropes);
	roomInventory->addItem(new Gun());
}

void GymnasiumFloor2::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# You've never been up here! It looks like the rafters of the gym. 'This door is always locked so I'm surprised it's" << endl;
		cout << "# open now.'" << endl;
		cout << "#" << endl;
	}
	
	cout << "# Rafters circle the room. There are lots of lights and ropes secured under the rafters." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
	
}

int GymnasiumFloor2::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 0;
	}

	if (commandVector[0].compare("cut") == 0 && commandVector[1].compare("ropes") == 0) {
		cutRopes();
	}

	else {
		cout << "# You can't " << commandVector[0] << " the " << commandVector[1] << "." << endl << "#" << endl;
	}
	
	return 0;
}

void GymnasiumFloor2::cutRopes()
{
	cout << "# As you cut the ropes, the tension is released and all of the lights and scoreboards go crashing to the lower level of the gym." << endl << "#" << endl;
	gym1 = static_cast<GymnasiumFloor1*>(findRoom("Gymnasium First Floor"));
	gym1->ropesCut();
}

bool GymnasiumFloor2::coltGone()
{
	return goneColt;
}

bool GymnasiumFloor2::itemSearch(vector<string> inv, string a)
{
	return false;
}
