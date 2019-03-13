#include "Chemistry.h"

Chemistry::Chemistry() : Space("Chemistry")
{
	this->zombie = new Zombie(false);
	
	beakers = new Item();
	string description = "# A collection of beakers are on the table. Some are knocked\n# over and broken, but they all appear clean";
	string name = "beakers";
	beakers->setDummyItem(description, name);
	roomInventory->addItem(beakers);

	cabinet = new Item();
	description = "# A tall cabinet is pushed up against the south wall. It is filled\n# with chemicals and mixing agents.";
	name = "cabinet";
	cabinet->setDummyItem(description, name);
	string text = "# You walk to the side of the cabinet, setting your shoulder against the wood,\n# and begin pushing. The cabinet slowly slides across the floor with a loud\n# screeching sound. You take a step back and notice a ladder mounted\n# to the wall that leads up into another room.";
	cabinet->setAction(text, Push);
	roomInventory->addItem(cabinet);
}

Chemistry::~Chemistry()
{

}

void Chemistry::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		if (zombie->isAlive() == true) {
			cout << KMAG "# You step into the room and a zombie saunters around from behind the" << endl;
			cout << "# door, surprising you. You jump back and step away quickly, putting" << endl;
			cout << "# some distance between you and the zombie." << endl;
			cout << "#" << endl;
			cout << "# The zombie's lips have been torn away and you can see all of his" << endl;
			cout << "# teeth and gums. He looks hungry." << endl;
			cout << "#" << endl;
		}
		else {
			cout << KMAG  "# 'Just when I thought I was done walking into this chemistry classroom.'" << endl;
			cout << "# You remember the hours spent memorizing the periodic table and" << endl;
			cout << "# identifying formulas and you let out a shudder." << endl;
			cout << "#" << endl;
		}
	}

	cout << KMAG "# Beakers sit atop tables pushed against the west and east walls and in the" << endl;
	cout << "# center of the room. Various items can be found inside of cabinets set" << endl;
	cout << "# against the south wall." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# You can get to the Biology room from here, but if you're not ready to" << endl;
		cout << "# head out that way then you can go to the hallway." << endl;
		cout << "#" << endl;
	}

	cout << "# The biology room is to the north and the hallway is out to the east." RESET << endl;
	cout << "#" << endl;

	if (didDieOnEnter)
	{
		cout << KRED "# Oh no! There is a zombie in here and you do not have any weapons to fight it with." << endl;
		cout << "# It is too late to run and the zombie feasted on you, game over!" RESET << endl << endl;
		return;
	}

        if (zombie->isAlive()) {
                cout << KRED "# Oh no! There is a zombie in here!" RESET << endl;
                cout << "#" << endl;
        }

	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Chemistry::moveCabinet()
{
	setHoleVisible(true);
}

bool Chemistry::getHoleVisible()
{
	return holeVisible;
}

void Chemistry::setHoleVisible(bool visible){
	holeVisible = visible;

	if(ladder != NULL){
		ladder = roomInventory->findItem("ladder");
		roomInventory->removeItem(ladder);
		delete ladder;
		ladder = NULL;
	}

	if(holeVisible){
		ladder = new Item();
		string description = "# A metal ladder is mounted against the wall. It seems sturdy enough to climb.";
		string name = "ladder";
		ladder->setDummyItem(description, name);
		string text = "# You ascend the ladder, step by step, inching closer to the hole in the ceiling.";
		ladder->setAction(text, Use);
		roomInventory->addItem(ladder);
	}
}
