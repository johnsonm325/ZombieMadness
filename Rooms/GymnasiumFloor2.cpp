#include "GymnasiumFloor2.h"

GymnasiumFloor2::GymnasiumFloor2() : Space("Gymnasium Second Floor")
{
	string description, text, name;
	roomInventory->addItem(new Ropes());

	lights = new Item();
	description = "# There are a lot of lights hanging in the ceiling, and there is a switch\n# close by. 'Maybe that turns them on.'";
	name = "lights";
	lights->setDummyItem(description, name);
	text = "# You turn on the lights, which shine down below to show a zombie wandering around.";
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
		cout << KMAG "# You've never been up here! It looks like the rafters of the gym. 'This door" << endl;
		cout << "# is always locked so I'm surprised it's open now.'" << endl;
		cout << "#" << endl;
	}
	
	cout << KMAG "# Rafters circle the room. There are lots of lights and ropes secured under" << endl;
	cout << "# the rafters. You also see a gun tucked away in the corner on the walkway." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# You can head through the locker room to continue exploring this floor," << endl;
		cout << "# or you can climb down this ladder to get down to the first floor." << endl;
		cout << "#" << endl;
	}

	cout << "# The ladder is on the west wall and the locker room is to the north." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
	
}

void GymnasiumFloor2::cutRopes()
{
	roomInventory->removeItem(roomInventory->findItem("Ropes"));

	gym1 = static_cast<GymnasiumFloor1*>(findRoom("Gymnasium First Floor"));
	gym1->getZombie()->die();
}
