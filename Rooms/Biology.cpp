#include "Biology.h"

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
		cout << "# The room has a lot of plants and cases with dissected animals. 'This was never my favorite subject, but I did enjoy" << endl;
		cout << "# cutting open frogs to see what was inside of them." << endl;
		cout << "#" << endl;
	}

	cout << "# The room has a mixture of desks and tables. There are a good deal of items and tools for gardening." << endl;
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

void Biology::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Peace out frogs!  I can't wait to get away from that smell, horrid..." << endl;
		cout << "# Yet, this entire place could not smell any worse thanks to my lovely dead classmates" << endl;
		cout << "# and teachers!'" << endl;
		cout << "#" << endl;
	}

	cout << "# 'I remember the library being really close to the Biology room, the Math room and Chemistry room" << endl;
	cout << "# were close by here too.'" << endl;
	cout << "#" << endl;
}

int Biology::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}

