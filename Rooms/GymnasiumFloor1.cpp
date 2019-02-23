#include "GymnasiumFloor1.h"

GymnasiumFloor1::GymnasiumFloor1() : Space("Gymnasium First Floor")
{
	basketball = new Item();
	string description = "# A single basketball is seen in the middle of the gym floor. It looks like it's filled with air.";
	string name = "basketball";
	basketball->setDummyItem(description, name);
	string text = "# You grab the basketball and shoot a few hoops. You don't make a single shoot. 'Good thing no one is here to see that.'";
	basketball->setAction(text, Use);
	roomInventory->addItem(basketball);

	bleachers = new Item();
	description = "# The bleachers are pulled out of the wall and there are some scattered bodies littered on them.";
	name = "bleachers";
	bleachers->setDummyItem(description, name);
	roomInventory->addItem(bleachers);
}

GymnasiumFloor1::~GymnasiumFloor1()
{
	
}

void GymnasiumFloor1::printIntro(){
	// Prints the first time the room is visited	
	if (firstTry == true)
	{
		if(deadZombies == true) {
			cout << "# Dead zombies litter the floor. Great thing you decided to cut those ropes or else you'd have a tough fight" << endl;
			cout << "# on your hands. Basketball doesn't seem like such of an important event when you're having to fight your way" << endl;
			cout << "# out of this place to stay alive." << endl;
			cout << "#" << endl;
		}

		else {
			cout << "# You are surrounded by zombies. Packs of them notice your presence and slowly begin to shuffle their way in" << endl;
			cout << "# your direction." << endl;
			cout << "#" << endl;
		}

		cout << "# Basketball goals are mounted against the west and east walls, and bleachers are pulled out along the south wall." << endl;
		cout << "#" << endl;
		cout << "# What do you do now?" << endl;
		cout << "#" << endl;
	}
}

void GymnasiumFloor1::printExitDesc()
{
	if (firstTry == true)
	{
		if (deadZombies == true)
		{
			cout << "# 'Wow, thank goodness I was able to take out all these zombies at once," << endl;
			cout << "# no way could I take them all on!'" << endl;
		}

		else
		{
			cout << "# There are seriously a ton of these zombies here, how can you ever fight them?" << endl;
			cout << "# ..." << endl;
			cout << "# Or maybe you don't?" << endl;
		}
	}

	cout << "# The cafeteria is super close, you remember that from how many times you went to grab food" << endl;
	cout << "# during gym class.  The football field is easily accessible from here." << endl;
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

void GymnasiumFloor1::ropesCut()
{
	zombiesDead();
}

void GymnasiumFloor1::zombiesDead()
{
	deadZombies = true;
}

