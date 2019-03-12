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
	text = "# You take the sandwich, and enjoy it's delicious meaty flavor. Your mouth is covered in leftover sauce. That hit the spot!";
    sloppyJoe->setAction(text, Eat);
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
		cout << KMAG "# You look around a see a few dead zombies littered throughout the large room." << endl;
		cout << "# 'I definitely need to tread lightly in case they aren't dead.' The room is" << endl;
		cout << "# large, so there is plenty of space to move around." << endl;
		cout << "#" << endl;
	}

	cout << KMAG "# Long lunch tables fill the room and lunch trays are littered on the tables" << endl;
	cout << "# and floor. Food debris is thrown about the room." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# The only way out is back out to the hallway." << endl;
		cout << "#" << endl;
	}

	cout << "# The first floor hallway is to the east." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Cafeteria::throwFood()
{
	chem = static_cast<Chemistry*>(findRoom("Chemistry"));
	chem->getZombie()->die();
}

bool Cafeteria::getVendingMachineUsed()
{
    return vendingMachineUsed;
}

void Cafeteria::useVendingMachine()
{
	vendingMachineUsed = true;
	if(snack != NULL){
		roomInventory->removeItem(snack);
		delete snack;
	}

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
	if(snack != NULL)
	{
		roomInventory->removeItem(snack);
		delete snack;
		vendingMachineUsed = false;
	}	
}
