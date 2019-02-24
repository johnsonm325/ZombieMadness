#include "Chemistry.h"

Chemistry::Chemistry() : Space("Chemistry")
{
	this->zombie = new Zombie(false);
	
	beakers = new Item();
	string description = "# A collection of beakers are on the table. Some are knocked over and broken, but they all appear clean";
	string name = "beakers";
	beakers->setDummyItem(description, name);
	roomInventory->addItem(beakers);

	cabinet = new Item();
	description = "# A tall cabinet is pushed up against the south wall. It is filled with chemicals and mixing agents.";
	name = "cabinet";
	cabinet->setDummyItem(description, name);
	roomInventory->addItem(cabinet);
}

Chemistry::~Chemistry()
{

}

void Chemistry::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# 'Just when I thought chemistry was a useless subject.' You realize that all of your learning may" << endl;
		cout << "# finally pay off. You can access some of that 'useless' knowledge to create some useful items now." << endl;
		cout << "#" << endl;
	}

	cout << "# Beakers, flasks and bunsen burners sit atop tables pushed against the west and east walls and in the" << endl;
	cout << "# center of the room. Various ingredients can be found inside of cabinets set against the south wall." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Chemistry::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Wow, the fact that I managed NOT to blow myself up in there is amazing' you think to yourself." << endl;
		cout << "# You also remember the chemistry room is where you asked out Sophie to prom..." << endl;
		cout << "# Where she said no.........." << endl;
		cout << "# 'I HATE CHEMISTRY!' you declare." << endl;
		cout << "#" << endl;
	}

	cout << "# The hallway that is accessible from the chemistry room is pretty long, rooms like" << endl;
	cout << "# the math room, com sci room, and front lobby are all reachable from here!" << endl;

	if (zombie != NULL)
		cout << "# Oh no, a zombie is in here!" << endl;

	cout << "#" << endl;
}

int Chemistry::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

	return 0;
}

void Chemistry::inspectCabinet()
{
	string text = "# You walk to the side of the cabinet, setting your shoulder against the wood, and begin pushing.\n# The cabinet slowly slides across the floor with a loud screeching sound. You take a step back and notice a ladder\n# mounted to the wall that leads up into another room.";
	cabinet->setAction(text, Push);
}

void Chemistry::moveCabinet()
{
	holeVisible = true;
	ladder = new Item();
	string description = "# A metal ladder is mounted against the wall. It seems sturdy enough to climb.";
	string name = "ladder";
	ladder->setDummyItem(description, name);
	roomInventory->addItem(ladder);
	string text = "# You ascend the ladder, step by step, inching closer to the hole in the ceiling.";
	ladder->setAction(text, Use);
}

bool Chemistry::getHoleVisible()
{
	return holeVisible;
}

void Chemistry::zombiesDead()
{
	deadZombies = true;
}

