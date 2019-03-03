#include "History.h"

History::History() : Space("History")
{
	roomInventory->addItem(new Knife());

	georgeWashingtonBust = new Item();
	string description = "# It's a solid stone bust of George Washington. Would be too heavy to\n# carry. Doesn't seem to be anything special about this item.";
	string name = "George Washington bust";
	georgeWashingtonBust->setDummyItem(description, name);
	roomInventory->addItem(georgeWashingtonBust);

	billOfRights = new Item();
	description = "# This is the bill of rights, the original 10 amendments to the Constitution\n# of the United States of America.";
	name = "Bill of Rights";
	billOfRights->setDummyItem(description, name);
	string text = "# Congress of the United States begun and held at the City of New-York, on\n# Wednesday the fourth of March, one thousand seven hundred and eighty nine.\n#\n# THE Conventions of a number of the States, having at the time of their adopting the\n# Constitution, expressed a desire, in order to prevent misconstruction or abuse of its\n# powers, that further declaratory and restrictive clauses should be added: And as\n# extending the ground of public confidence in the Government, will best ensure the\n# beneficent ends of its institution.\n#\n# RESOLVED by the Senate and House of Representatives of the United States of America,\n# in Congress assembled, two thirds of both Houses concurring, that the following Articles\n# be proposed to the Legislatures of the several States, as amendments to the Constitution\n# of the United States, all, or any of which Articles, when ratified by three fourths of\n# the said Legislatures, to be valid to all intents and purposes, as part of the said\n# Constitution; viz.\n#\n# ARTICLES in addition to, and Amendment of the Constitution of the United States of\n# America, proposed by Congress, and ratified by the Legislatures of the several States,\n# pursuant to the fifth Article of the original Constitution.\n#\n# Article the first... After the first enumeration required by the first article\n# of the Constitution, there shall be one Representative for every thirty thousand, until\n# the number shall amount to one hundred, after which the proportion shall be so regulated\n# by Congress, that there shall be not less than one hundred Representatives, nor less\n# than one Representative for every forty thousand persons, until the number of\n# Representatives shall amount to two hundred; after which the proportion shall be so\n# regulated by Congress, that there shall not be less than two hundred Representatives, nor\n# more than one Representative for every fifty thousand persons.\n#\n# Article the second... No law, varying the compensation for the services of the Senators\n# and Representatives, shall take effect, until an election of Representatives shall have\n# intervened.\n#\n# Article the third... Congress shall make no law respecting an establishment of religion,\n# or prohibiting the free exercise thereof; or abridging the freedom of speech, or of the\n# press; or the right of the people peaceably to assemble, and to petition the\n# Government for a redress of grievances.\n#\n# Article the fourth... A well regulated Militia, being necessary to the security of a free\n# State, the right of the people to keep and bear Arms, shall not be infringed.\n#\n# Article the fifth... No Soldier shall, in time of peace be quartered in any house,\n# without the consent of the Owner, nor in time of war, but in a manner to be prescribed\n# by law.\n# ...\n# ...";
	billOfRights->setAction(text, Read);
	roomInventory->addItem(billOfRights);

}

History::~History(){

}

void History::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# Dusty books and pictures of presidents on the wall, must be in" << endl;
		cout << "# history class. 'I've fallen asleep one too many times in here." << endl;
		cout << "# If I have to hear about one more amendment... Wait, there are" << endl;
		cout << "# more important matters.'" << endl;
		cout << "#" << endl;
	}

	cout << "# The north and south walls are lined will bookshelves and desks fill the center" << endl;
	cout << "# of the room. There is a bust of George Washington and a copy of the Bill of" << endl;
	cout << "# Rights is mounted on the west wall. There is also a knife on one of the desks" << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void History::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'In reality, I probably should've paid a little more attention here." << endl;
		cout << "# Aren't we doomed to repeat the past if we don't learn about it?' ...." << endl;
		cout << "# The only way out seems to be back through the door I came in." << endl;
		cout << "#" << endl;
	}

	cout << "# This room is connected to the 2nd floor hallway, another area that gives you" << endl;
	cout << "# access to many other rooms, like the locker room, literature room, and infirmary." << endl;
	cout << "#" << endl;
}

int History::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

	return 0;
}

void History::inspectBust()
{
	lit = static_cast<Literature*>(findRoom("Literature"));
	lit->getZombie()->die();
}

