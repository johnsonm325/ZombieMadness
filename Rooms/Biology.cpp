#include "Biology.h"
#define KMAG  "\x1B[35m"
#define RESET "\x1B[0m"

Biology::Biology() : Space("Biology")
{
	this->roomInventory->addItem(new Rocks());

	dissectedAnimal = new Item();
	string description = "# A pig is laying on its back on the table, with it's stomach split open.\n# You can see all of it's organs. The organs have blank labels, as if this was set up for\n# some kind of test.";
	string name = "dissected animal";
	dissectedAnimal->setDummyItem(description, name);
	roomInventory->addItem(dissectedAnimal);

	plants = new Item();
	description = "# There is a large collection of herbs and plants scattered across the room. You\n# remember that some of these will give you and added boost of health when you eat them,\n# and some can harm you, but can you remember which ones?";
	name = "plants";
	plants->setDummyItem(description, name);
	string text = "# You carefully pick the plant you think is the right one, close your eyes,\n# and take a bite.";
	plants->setAction(text, Eat);
	roomInventory->addItem(plants);
}

Biology::~Biology(){

}

void Biology::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << KMAG "# 'This was never my favorite subject, but I did enjoy cutting open frogs to see" << endl;
		cout << "# what was inside of them." << endl;
		cout << "#" << endl;
	}

	cout << KMAG "# The room has a mixture of desks and tables and there are a good deal of dissected" << endl;
	cout << "# animals in cases, plants and rocks scattered in the room." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# The library and chemistry room are connected to this room. You can leave from there," << endl;
		cout << "# or head out to the hallway." << endl;
		cout << "#" << endl;
	}

	cout << "# The hallway is to your east, the chemistry room is to the south and the library is" << endl;
	cout << "# north of your location." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

bool Biology::getPlantsEaten()
{
	return plantsEaten;
}

void Biology::setPlantsEaten()
{
	plantsEaten = true;
}
