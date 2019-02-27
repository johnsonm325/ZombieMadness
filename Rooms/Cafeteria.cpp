#include "Cafeteria.h"

Cafeteria::Cafeteria() : Space("Cafeteria")
{
	food = new Item();
	string description = "# There are chunks of food strewn around the room. Some of it is gloopy,\n# and you don't want to touch that. But some, you can pick up.";
	string name = "food";
	food->setDummyItem(description, name);
	string text =  "You hurl the chunks of food across the room. They stick to the wall and satisfyingly\n# slide down to the floor. 'I've always wanted to do that,' you say.";
	food->setAction(text, Throw);
	roomInventory->addItem(food);

	sloppyJoe = new Item();
	description = "# A solitary sloppy joe sandwich sits on the table. It looks so tasty here in\n# lunch lady land.";
	name = "sloppy joe";
	sloppyJoe->setDummyItem(description, name);
	roomInventory->addItem(sloppyJoe);

	vendingMachine = new Item();
        description = "# There is a vending machine against the west wall. It is full of snacks.\n# It appears to be broken; like you can just push buttons for free snacks!";
        name = "vending machine";
        vendingMachine->setDummyItem(description, name);
        text = "# You push a button and a snack drops";
        vendingMachine->setAction(text, Use);
        roomInventory->addItem(vendingMachine);
}

Cafeteria::~Cafeteria(){
	//delete food;
	//delete sloppyJoe;
	//delete vendingMachine;
}

void Cafeteria::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# You look around a see a few dead zombies littered throughout the large room." << endl;
		cout << "# 'I definitely need to tread lightly in case they aren't dead.' The room is" << endl;
		cout << "# large, so there is plenty of space to move around." << endl;
		cout << "#" << endl;
	}

	cout << "# Long lunch tables fill the room and lunch trays are littered on the tables" << endl;
	cout << "# and floor. Food debris is thrown about the room." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
}

void Cafeteria::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# You are sad to leave to Cafeteria actually. It didn't smell half as bad as the other" << endl;
		cout << "# rooms in this school and food! 'I don't want to leave the food room, it has food..." << endl;
		cout << "# Fooooooooooooooooooddddddddddddd'" << endl;
		cout << "#" << endl;
		cout << "# Only one way out of here, and that's back through the hallway." << endl;
	}

	cout << "# You remember looking out the massive windows at the Football field during lunch" << endl;
	cout << "# and remember when you used to grab a quick snack before Gym class in the next room" << endl;
	cout << "#" << endl;
}

int Cafeteria::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

	return 0;
}

void Cafeteria::throwFood()
{
	chem = static_cast<Chemistry*>(findRoom("Chemistry"));
	chem->zombiesDead();
}

bool Cafeteria::getVendingMachineUsed()
{
        return vendingMachineUsed;
}

void Cafeteria::useVendingMachine()
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

void Cafeteria::eatSnack()
{
        roomInventory->removeItem(snack);
        delete snack;
        vendingMachineUsed = false;
}
