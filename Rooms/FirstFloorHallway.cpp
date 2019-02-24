#include "FirstFloorHallway.h"

FirstFloorHallway::FirstFloorHallway() : Space("First Floor Hallway")
{
	vomit = new Item();
	string description = "# You can see you fresh pile of vomit on the floor. The smell comes up to\n# meet your nose and you almost gag.";
	string name = "vomit";
	vomit->setDummyItem(description, name);
	string text = "# You eat the vomit.\n# You are disgusting! What's wrong with you?!";
	vomit->setAction(text, Eat);
	roomInventory->addItem(vomit);

	vendingMachine = new Item();
	description = "# There is a vending machine against the west wall. It is full of snacks.\n# It appears to be broken; like you can just push buttons for free snacks!";
	name = "vending machine";
	vendingMachine->setDummyItem(description, name);
	text = "# You push a button and a snack drops";
	vendingMachine->setAction(text, Use);
	roomInventory->addItem(vendingMachine);
}

FirstFloorHallway::FirstFloorHallway(bool firstTry) : Space("First Floor Hallway")
{
	this->firstTry = firstTry;
}

FirstFloorHallway::~FirstFloorHallway(){

}

void FirstFloorHallway::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# This hallway doesn't look much better than the second floor. Blood is smeared everywhere and there are half-eaten" << endl;
		cout << "# bodies, and some with just holes chewed into their stomachs, just lying along the hallway. You wrench at the sight" << endl;
		cout << "# and throw up on the floor. These are people you went to school with and sat beside everyday. You finally steel your" << endl;
		cout << "# will and determine to move on." << endl;
		cout << "#" << endl;
	}

	cout << "# There are bulletin boards lining the walls and school supplies scattered about the hallway." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void FirstFloorHallway::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# The first floor hallway is really useful in that it is connected to a lot of other rooms." << endl;
		cout << "# Just be watch your step for that vomit you just beautifully spewed out.... gross." << endl;
		cout << "#" << endl;
	}

	cout << "# Keep in mind how many different rooms can be visited from the first floor hallway!" << endl;
	cout << "#" << endl;
}

int FirstFloorHallway::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}

bool FirstFloorHallway::getVendingMachineUsed()
{
	return vendingMachineUsed;
}

void FirstFloorHallway::useVendingMachine()
{
	vendingMachineUsed = true;
	snack = new Item();
	string description = "# You lift the door and a Snickers bar sits at the bottom of the machine.";
	string name = "snack";
	snack->setDummyItem(description, name);
	string text = "# You grab the snack, open the wrapper and eat the candy bar. Delicious.";
	snack->setAction(text, Eat);
	roomInventory->addItem(snack);
}

void FirstFloorHallway::eatSnack()
{
	roomInventory->removeItem(snack);
	delete snack;
	vendingMachineUsed = false;
}
