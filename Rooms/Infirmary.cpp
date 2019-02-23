#include "Infirmary.h"

Infirmary::Infirmary() : Space("Infirmary")
{
	this->roomInventory->addItem(new BiteCure());
	this->lockDoor();

	bed = new Item();
	string description = "# A neatly made bed is lined against the north wall. It looks comfy and warm. 'If I could just take a quick nap... No, I need to keep moving.'";
	string name = "bed";
	bed->setDummyItem(description, name);
	string text = "# You pull back the sheets and slip into the bed. Your eyes close for a minute, and you're suddenly asleep... Five minutes later you jump awake, quickly looking at your watch. 'Oh good, I only slept for a few minutes.'";
	bed->setAction(text, Use);
	roomInventory->addItem(bed);

	nursesHat = new Item();
	description = "# A triangle hat sits on top of the stand beside the bed. It looks like a hat that a nurse would wear.";
	name = "nurses hat";
	nursesHat->setDummyItem(description, name);
	roomInventory->addItem(nursesHat);
}

Infirmary::~Infirmary(){

}

void Infirmary::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# 'I'll never forget the story Jacob told about when he accidently walked into the glass door of the front lobby." << endl;
		cout << "# This must be where they bandaged up the cut on his head. He walked around the school for days with that gauze" << endl;
		cout << "# on his forehead.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Lots of medical supplies are neatly tucked into containers and a bed sits along the north wall. 'I might be able to" << endl;
	cout << "# find something useful for myself in here.'" << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Infirmary::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# If there is ever a room that could save you from this nightmare, it'd be this room." << endl;
		cout << "# Nurse Peters was always so sweet, a shame that she is just roaming around here..." << endl;
		cout << "# All dead and what not, probably missing an arm or 2......... ugh, I want my mommy." << endl;
		cout << "#" << endl;
	}

	cout << "# Make sure you really give this room a good look, you can find some sweet items!" << endl;
	cout << "# You have access to the 2nd floor hallway here, lots of connections.  Don't forget" << endl;
	cout << "# about the chemistry room!" << endl;
	cout << "#" << endl;
}

int Infirmary::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	printIntro();
	
	return 0;
}
