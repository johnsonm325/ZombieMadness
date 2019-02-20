#include "WomensBathroom.h"


WomensBathroom::WomensBathroom(PlayerInventory *bag) : Space("Women's Bathroom")
{
	this->lockDoor();
	this->bag = bag;

	couch = new Item();
	string description = "# A couch with pink upholstry sits in the corner of the bathroom, inviting you to sit. It's flower pattern cushions look so comfortable, that you take a moment to sit down and relax. The dangers seem to melt away while you rest here.";
	string name = "couch";
	couch->setDummyItem(description, name);
	roomInventory->addItem(couch);

	lock = new Item();
	description = "# It looks like someone tampered with the locks and forced it so it couldn't be unlocked from the outside. I should be able to unlock it from the inside though.";
	name = "lock";
	lock->setDummyItem(description, name);
	roomInventory->addItem(lock);

	magazine = new Item();
	description = "At the top of the stack of magazines you see one called 'Cosmopolitan'. You're pretty sure you've seen your older sister with this one. On the front it reads, '24 ways to make your ...' 'WOAH!'";
	name = "magazine";
	magazine->setDummyItem(description, name);
	string text = "'Want to make your man beg for ... ' 'Ehh, maybe I don't want to read this.'";
	magazine->setAction(text, Read);
	roomInventory->addItem(magazine);
}

void WomensBathroom::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# Well, you've never been in here before. The forbidden zone. 'The guys will love to hear this story.'" << endl;
		cout << "# The air smells fresh in here; not like the urine stench you're accustomed to. 'They have A COUCH?!'" << endl;
		cout << "# You see magazines, a hair dryer, and other various pampering items lined up across the sink counter." << endl;
		cout << "# 'This place is unbelievable. We've been missing out on so much.' You take a moment to breath in the" << endl;
		cout << "# air and check out the scene. 'Ok, time to move on.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Sinks stand on the west wall and stalls line the east wall." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

int WomensBathroom::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 0;
	}

	return 0;
}

void WomensBathroom::firstTime()
{
	firstTry = false;
}

bool WomensBathroom::coltGone()
{
	return goneColt;
}

bool WomensBathroom::itemSearch(vector<string> inv, string a)
{
	return false;
}

void WomensBathroom::increaseBagSize()
{
	bag->increaseSize();
}
