#include "GymnasiumFloor2.h"

GymnasiumFloor2::GymnasiumFloor2() : Space("Gymnasium Second Floor")
{
	ropes = new Item();
	string description = "# Ropes appear to be strung across the rafters, holding up many\n# of the spotlights and scoreboards.";
	string name = "ropes";
	ropes->setDummyItem(description, name);
	string text = "As you cut the ropes, the tension is released and all of the lights and\n# scoreboards go crashing to the lower level of the gym.";
	ropes->setAction(text, Cut);	
	roomInventory->addItem(ropes);

	lights = new Item();
	description = "# There are a lot of lights hanging in the ceiling, and there is a switch\n# close by. 'Maybe that turns them on.'";
	name = "lights";
	lights->setDummyItem(description, name);
	text = "# You turn on the lights, which shine down below to show a room full of zombies.";
	lights->setAction(text, Use);
	roomInventory->addItem(lights);

	roomInventory->addItem(new Gun());
}

GymnasiumFloor2::~GymnasiumFloor2()
{

}

void GymnasiumFloor2::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# You've never been up here! It looks like the rafters of the gym. 'This door" << endl;
		cout << "# is always locked so I'm surprised it's open now.'" << endl;
		cout << "#" << endl;
	}
	
	cout << "# Rafters circle the room. There are lots of lights and ropes secured under" << endl;
	cout << "# the rafters." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
	
}

void GymnasiumFloor2::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# As you look down on all the zombies below, you start to have" << endl;
		cout << "# some serious doubts if you will survive or not. Not gonna help to" << endl;
		cout << "# mope about it though, onwards we go!" << endl;
		cout << "#" << endl;
		cout << "# Only two ways out, either back the way I came to go downstairs" << endl;
		cout << "# or I need to head down from here" << endl;
		cout << "#" << endl;
	}

	cout << "# With access to the first floor of the gym and the locker room, you feel" << endl;
	cout << "# like there can be some good stuff waiting for you soon." << endl;
	cout << "#" << endl;
}

int GymnasiumFloor2::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 0;
	}

	return 0;
}

void GymnasiumFloor2::cutRopes()
{
	gym1 = static_cast<GymnasiumFloor1*>(findRoom("Gymnasium First Floor"));
	gym1->ropesCut();
}


