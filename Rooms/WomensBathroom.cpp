#include "WomensBathroom.h"

WomensBathroom::WomensBathroom(PlayerInventory *bag) : Space("Women's Bathroom")
{
	this->lockDoor();
	this->bag = bag;
	string description, text, name;

	couch = new Item();
	description = "# A couch with pink upholstry sits in the corner of the bathroom,\n# inviting you to sit. It's flower pattern cushions look so comfortable,\n# that you take a moment to sit down and relax. The dangers\n# seem to melt away while you rest here.";
	name = "couch";
	couch->setDummyItem(description, name);
	roomInventory->addItem(couch);

	lock = new Item();
	description = "# It looks like someone tampered with the locks and forced it so it\n# couldn't be unlocked from the outside. I should be able to unlock it from\n# the inside though.";
	name = "lock";
	lock->setDummyItem(description, name);
	roomInventory->addItem(lock);

	magazine = new Item();
	description = "# At the top of the stack of magazines you see one called 'Cosmopolitan'.\n# You're pretty sure you've seen your older sister with this one. On\n# the front it reads, '24 ways to make your ...' 'WOAH!'";
	name = "magazine";
	magazine->setDummyItem(description, name);
	text = "# Want to make your man beg for ... ' 'Ehh, maybe I don't want to read this.'";
	magazine->setAction(text, Read);
	roomInventory->addItem(magazine);

	roomInventory->addItem(new Bookbag());
}

WomensBathroom::~WomensBathroom(){

}

void WomensBathroom::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << KMAG "# Well, you've never been in here before. The forbidden zone. 'The guys" << endl;
		cout << "# will love to hear this story.' The air smells fresh in here; not like" << endl;
		cout << "# the urine stench you're accustomed to. 'They have A COUCH?!' You see" << endl;
		cout << "# magazines and various pampering items lined up across the sink counter." << endl;
		cout << "# 'This place is unbelievable. We've been missing out on so much.' You" << endl;
		cout << "# take a moment to breath in the air and check out the scene. 'Ok, time" << endl;
		cout << "# to move on.'" << endl;
		cout << "#" << endl;
	}

	cout << KMAG "# There is a couch along the north wall with a pile of magazines on a table" << endl;
	cout << "# next to it. The door also has a lock on it." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# This front door must lead out to the same hallway. I can go that way" << endl;
		cout << "# or head back through the hole to the men's bathroom." << endl;
		cout << "#" << endl;
	}

	cout << "# Theres a door on the west wall and the hole on the north wall leading back." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void WomensBathroom::increaseBagSize()
{
	roomInventory->removeItem(roomInventory->findItem("Bookbag"));
	bag->increaseSize();
	// delete bookbag;
}
