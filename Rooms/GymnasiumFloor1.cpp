#include "GymnasiumFloor1.h"

GymnasiumFloor1::GymnasiumFloor1() : Space("Gymnasium First Floor")
{
	this->zombie = new Zombie(false);
	
	basketball = new Item();
	string description = "# A single basketball is seen in the middle of the gym floor. It\n# looks like it's filled with air.";
	string name = "basketball";
	basketball->setDummyItem(description, name);
	string text = "# You grab the basketball and shoot a few hoops. You don't make a single\n# shot. 'Good thing no one is here to see that.'";
	basketball->setAction(text, Use);
	roomInventory->addItem(basketball);

	bleachers = new Item();
	description = "# The bleachers are pulled out of the wall and there are some scattered\n# bodies littered on them.";
	name = "bleachers";
	bleachers->setDummyItem(description, name);
	roomInventory->addItem(bleachers);
}

GymnasiumFloor1::~GymnasiumFloor1()
{
	//delete zombie;
	//delete basketball;
	//delete bleachers;
}

void GymnasiumFloor1::printIntro(){
	// Prints the first time the room is visited	
	if (firstTry == true)
	{
		if(!zombie->isAlive()) {
			cout << "# Dead zombies litter the floor. Great thing you decided to cut those ropes or" << endl;
			cout << "# else you'd have a tough fight on your hands. Basketball doesn't seem like such" << endl;
			cout << "# of an important event when you're having to fight your way out of this place" << endl;
			cout << "# to stay alive." << endl;
			cout << "#" << endl;
		}

		else {
			cout << "# You are surrounded by zombies. Packs of them notice your presence and slowly" << endl;
			cout << "# begin to shuffle their way in your direction." << endl;
			cout << "#" << endl;
		}
	}

	cout << "# Basketball goals are mounted against the west and east walls, and bleachers" << endl;
	cout << "# are pulled out along the south wall. There is a basketball on the floor." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void GymnasiumFloor1::printExitDesc()
{
	if (firstTry == true)
	{
		cout << "# 'Wow, thank goodness I was able to take out all these zombies at once," << endl;
		cout << "# no way could I take them all on!'" << endl;
		cout << "#" << endl;
		cout << "# There are three ways out of the Gym. I can either head up to the second" << endl;
		cout << "# floor or head out one of two doors." << endl;
	}

	cout << "# The cafeteria is super close, you remember that from how many times you" << endl;
	cout << "# went to grab food during gym class.  The football field is easily accessible" << endl;
	cout << "# from here." << endl;
	cout << "#" << endl;
}

int GymnasiumFloor1::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	return 0;
}
