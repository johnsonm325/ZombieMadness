#include "GymnasiumFloor1.h"

GymnasiumFloor1::GymnasiumFloor1() : Space("Gymnasium First Floor")
{
	this->zombie = new Zombie(false);
	this->roomInventory->addItem(new Jersey());
	
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
	
}

void GymnasiumFloor1::printIntro(){
	// Prints the first time the room is visited	
	if (firstTry == true)
	{
		if(!zombie->isAlive()) {
			cout << KMAG "# Dead zombies litter the floor. Great thing you decided to cut those ropes or" << endl;
			cout << "# else you'd have a tough fight on your hands. Basketball doesn't seem like such" << endl;
			cout << "# of an important event when you're having to fight your way out of this place" << endl;
			cout << "# to stay alive." << endl;
			cout << "#" << endl;
		}

		else {
			cout << KMAG "# You spot a zombie in the room. This one saw you climbing down and is on his" << endl;
			cout << "# way towards you." << endl;
			cout << "#" << endl;
		}
	}

	cout << KMAG "# Basketball goals are mounted against the west and east walls, and bleachers" << endl;
	cout << "# are pulled out along the south wall. There is a basketball on the floor." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# There are three ways out. One to the football field, one to the first floor" << endl;
		cout << "# hallway, and another to the rafters." << endl;
		cout << "#" << endl;
	}

	cout << "# Head west to get to the hallway, east to get up to the rafters and south to head" << endl;
	cout << "# out to the football field." RESET << endl;
	cout << "#" << endl;

	if (didDieOnEnter)
	{
		cout << KRED "# Oh no! There is a zombie in here and you do not have any weapons to fight it with." << endl;
		cout << "# It is too late to run and the zombie feasted on you, game over!" RESET << endl;
		return;
	}

        if (zombie->isAlive()) {
                cout << KRED "# Oh no! There is a zombie in here!" RESET << endl;
		cout << "#" << endl;
        }


	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}
