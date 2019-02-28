#include "Chemistry.h"

Chemistry::Chemistry() : Space("Chemistry")
{
	this->zombie = new Zombie(false);
	this->deadZombies = false;

	beakers = new Item();
	string description = "# A collection of beakers are on the table. Some are knocked\n# over and broken, but they all appear clean";
	string name = "beakers";
	beakers->setDummyItem(description, name);
	roomInventory->addItem(beakers);

	cabinet = new Item();
	description = "# A tall cabinet is pushed up against the south wall. It is filled\n# with chemicals and mixing agents.";
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
		cout << "# 'Just when I thought I was done walking into this chemistry classroom.'" << endl;
		cout << "# You remember the hours spent memorizing the periodic table and" << endl;
		cout << "# identifying formulas and you let out a shudder." << endl;
		cout << "#" << endl;
	}

	cout << "# Beakers sit atop tables pushed against the west and east walls and in the" << endl;
	cout << "# center of the room. Various items can be found inside of cabinets set" << endl;
	cout << "# against the south wall." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Chemistry::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Wow, the fact that I managed NOT to blow myself up in there is amazing'" << endl;
		cout << "# you think to yourself. You also remember the chemistry room is where you" << endl;
		cout << "# asked out Sophie to prom... Where she said no..." << endl;
		cout << "# 'I HATE CHEMISTRY!' you declare." << endl;
		cout << "#" << endl;
	}

	cout << "# The hallway that is accessible from the chemistry room is pretty long," << endl;
	cout << "# rooms like the math room, com sci room, and front lobby are all" << endl;
	cout << "# reachable from here!" << endl;
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
	string text = "# You walk to the side of the cabinet, setting your shoulder against the wood,\n# and begin pushing. The cabinet slowly slides across the floor with a loud\n# screeching sound. You take a step back and notice a ladder mounted\n# to the wall that leads up into another room.";
	cabinet->setAction(text, Push);
}

void Chemistry::moveCabinet()
{
	holeVisible = true;
	if(ladder != NULL){
		delete ladder;
		ladder = NULL;
	}
	
	ladder = new Item();
	description = "# A metal ladder is mounted against the wall. It seems sturdy enough to climb.";
	name = "ladder";
	ladder->setDummyItem(description, name);
	string text = "# You ascend the ladder, step by step, inching closer to the hole in the ceiling.";
	ladder->setAction(text, Use);
	roomInventory->addItem(ladder);
}

bool Chemistry::getHoleVisible()
{
	return holeVisible;
}
