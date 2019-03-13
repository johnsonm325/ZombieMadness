#include "Infirmary.h"

Infirmary::Infirmary() : Space("Infirmary")
{
	this->roomInventory->addItem(new BiteCure());
	this->lockDoor();

	bed = new Item();
	string description = "# A neatly made bed is lined against the north wall. It looks comfy and\n# warm. 'If I could just take a quick nap... No, I need to keep moving.'";
	string name = "bed";
	bed->setDummyItem(description, name);
	string text = "# You pull back the sheets and slip into the bed. Your eyes close for a minute,\n# and you're suddenly asleep... Five minutes later you jump awake, quickly\n# looking at your watch. 'Oh good, I only slept for a few minutes.'";
	bed->setAction(text, Use);
	roomInventory->addItem(bed);

	nursesHat = new Item();
	description = "# A triangle hat sits on top of the stand beside the bed. It looks like a hat\n# that a nurse would wear.";
	name = "nurses hat";
	nursesHat->setDummyItem(description, name);
	roomInventory->addItem(nursesHat);

	ladder = new Item();
	description = "# A metal ladder is mounted against the wall. It It leads back down.";
	name = "ladder";
	ladder->setDummyItem(description, name);
	text = "# You descend the ladder, step by step.";
	ladder->setAction(text, Use);
	roomInventory->addItem(ladder);
}

Infirmary::~Infirmary(){

}

void Infirmary::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << KMAG "# 'I'll never forget the story Jacob told about when he accidently walked into" << endl;
		cout << "# the glass door of the front lobby. This must be where they bandaged up the" << endl;
		cout << "# cut on his head. He walked around the school for days with that gauze on his" << endl;
		cout << "# forehead.'" << endl;
		cout << "#" << endl;
	}

	cout << KMAG "# Lots of medical supplies are neatly tucked into containers and a bed sits along" << endl;
	cout << "# the north wall. On a side table, a nurses hat rests. 'I might be able to find" << endl;
	cout << "# something useful for myself in here. These salves might serve as a good bite cure.'" << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# There's a door to get out of this room. It must lead to the hallway, since there" << endl;
		cout << "# are no other doors in here." << endl;
		cout << "#" << endl;
	}

	cout << "# The door to the hallway is towards the east, or you can climb back down the ladder" << endl;
	cout << "# on the west wall." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}
