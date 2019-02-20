#include "History.h"


History::History() : Space("History")
{
	georgeWashingtonBust = new Item();
	string description = "# It's a solid stone bust of George Washington. Would be too heavy to carry. Doesn't seem to be anything special about this item.";
	string name = "George Washington bust";
	georgeWashingtonBust->setDummyItem(description, name);
	roomInventory->addItem(georgeWashingtonBust);

	billOfRights = new Item();
	description = "# This is the bill of rights, the original 10 amendments to the Constitution of the United States of America.";
	name = "Bill of Rights";
	billOfRights->setDummyItem(description, name);

	string text = "Congress of the United States begun and held at the City of New-York, on Wednesday the fourth of March, one thousand seven hundred and eighty nine.\n\n# THE Conventions of a number of the States, having at the time of their adopting the Constitution, expressed a desire, in order to prevent misconstruction or abuse of its powers, that further declaratory and restrictive clauses should be added: And as extending the ground of public confidence in the Government, will best ensure the beneficent ends of its institution.\n\n# RESOLVED by the Senate and House of Representatives of the United States of America, in Congress assembled, two thirds of both Houses concurring, that the following Articles be proposed to the Legislatures of the several States, as amendments to the Constitution of the United States, all, or any of which Articles, when ratified by three fourths of the said Legislatures, to be valid to all intents and purposes, as part of the said Constitution; viz.\n\n# ARTICLES in addition to, and Amendment of the Constitution of the United States of America, proposed by Congress, and ratified by the Legislatures of the several States, pursuant to the fifth Article of the original Constitution.\n\n# Article the first... After the first enumeration required by the first article of the Constitution, there shall be one Representative for every thirty thousand, until the number shall amount to one hundred, after which the proportion shall be so regulated by Congress, that there shall be not less than one hundred Representatives, nor less than one Representative for every forty thousand persons, until the number of Representatives shall amount to two hundred; after which the proportion shall be so regulated by Congress, that there shall not be less than two hundred Representatives, nor more than one Representative for every fifty thousand persons.\n\n# Article the second... No law, varying the compensation for the services of the Senators and Representatives, shall take effect, until an election of Representatives shall have intervened.\n\n# Article the third... Congress shall make no law respecting an establishment of religion, or prohibiting the free exercise thereof; or abridging the freedom of speech, or of the press; or the right of the people peaceably to assemble, and to petition the Government for a redress of grievances.\n\n# Article the fourth... A well regulated Militia, being necessary to the security of a free State, the right of the people to keep and bear Arms, shall not be infringed.\n\n# Article the fifth... No Soldier shall, in time of peace be quartered in any house, without the consent of the Owner, nor in time of war, but in a manner to be prescribed by law.\n...\n...";

	billOfRights->setAction(text, Read);
	roomInventory->addItem(billOfRights);
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
