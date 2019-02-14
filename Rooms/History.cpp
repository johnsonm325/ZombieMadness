#include "History.h"


History::History() : Space("History")
{
	georgeWashingtonBust = new Item();
	string description = "# It's a solid stone bust of George Washington. Would be too heavy to carry. Doesn't seem to be anything special about this item.";
	string name = "George Washington bust";
	georgeWashingtonBust->setDummyItem(description, name);

	roomInventory->addItem(georgeWashingtonBust);
}

void History::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# Dusty books and pictures of presidents on the wall, must be in history class. 'I've fallen asleep one too many" << endl;
		cout << "# times in here. If I have to hear about one more amendment ... Wait, there are more important matters.'" << endl;
		cout << "#" << endl;
	}

	cout << "# The north and south walls are lined will bookshelves and desks fill the center of the room. A chalkboard is mounted" << endl;
	cout << "# on the west wall." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

int History::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

	if ((commandVector[0].compare("look") == 0 || commandVector[0].compare("inspect") == 0) && commandVector[1].compare("bust") == 0) {
		inspectBust();
	}

	else {
		cout << "# You can't " << commandVector[0] << " the " << commandVector[1] << "." << endl << "#" << endl;
	}
	
	return 0;
}


void History::inspectBust()
{
	cout << georgeWashingtonBust->getDesc() << endl;;
	lit = static_cast<Literature*>(findRoom("Literature"));
	lit->zombiesDead();
}


void History::firstTime()
{
	firstTry = false;
}


bool History::coltGone()
{
	return goneColt;
}


bool History::itemSearch(vector<string> inv, string a)
{
	return false;
}
