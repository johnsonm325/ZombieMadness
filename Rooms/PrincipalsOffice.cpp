#include "PrincipalsOffice.h"

PrincipalsOffice::PrincipalsOffice() : Space("Principal's Office")
{
	string description, name, text;
	this->zombie = new Zombie(false);

	key = new Key();
	fireExt = new FireExtinguisher();

	//Setting dummy items
	desk = new Item();
	description = "# A wooden desk in Principal's office, with a couple unlocked drawers. Examine it\n# closer and you may find new clues on your next plan of action!";
	name = "desk";
	text = "# You've opened the desk's drawer...Inside, you can see a shiny brass key.";
	desk->setDummyItem(description, name);
	desk->setAction(text, Open);
	
	roomInventory->addItem(fireExt);
	roomInventory->addItem(key);
	roomInventory->addItem(desk);

	chair = new Item();
	description = "# Behind the desk sits the principal's tall, black leather chair. It looks comfy.";
	name = "chair";
	chair->setDummyItem(description, name);
	text = "# You walk over to the chair and take a seat. You throw your feet up\n# on the desk and interlock your fingers behind your head.\n# 'Who's the boss now?'";
	chair->setAction(text, Use);
	roomInventory->addItem(chair);
}

PrincipalsOffice::~PrincipalsOffice(){

}

void PrincipalsOffice::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		if (zombie->isAlive()) {
			cout << "# As soon as you open the door, you are attacked from the north. You are quick" << endl;
			cout << "# enough to fight off the first push as you grab the zombie by the throat and" << endl;
			cout << "# shove it back. As it falls down, you realize it's already working to" << endl;
			cout << "# get itself back up. You know you don't have much time." << endl;
			cout << "#" << endl;
			cout << "# What do you do?" << endl;
			cout << "#" << endl;
		}
		else {
			cout << "# This small room is where the principal works. All of his meetings and" << endl;
			cout << "# disciplinary conferences go down right here. 'If only I weren't so familiar" << endl;
			cout << "# with them." << endl;
			cout << "#" << endl;
		}
	}

	cout << "# There is a single desk and a large leather chair in the room. Mounted on the wall" << endl;
	cout << "# you see a fire extinguisher." << endl;
	cout << "#" << endl;
	cout << "# What do you do?" << endl;
	cout << "#" << endl;
}

void PrincipalsOffice::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# How cool was that? You got to be in the principal's office all alone with" << endl;
		cout << "# with NO ONE to tell you no! So much fun!!" << endl;
		cout << "# But not really cause you are surrounded by zombies so ..." << endl;
		cout << "#" << endl;
	}

	cout << "# There is only one way out of here so make sure to really check this room before" << endl;
	cout << "# you leave, you don't want to get yourself caught in later!" << endl;
	cout << "#" << endl;
}

int PrincipalsOffice::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	return 0;
}
