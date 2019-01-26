#include "Space.h"

Space::Space(string t)
{
	type = t;
}

Space::~Space()
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

void Space::setEast(Space *e)
{
	east = e;
}

Space * Space::getEast()
{
	return east;
}

void Space::setWest(Space *w)
{
	west = w;
}

Space * Space::getWest()
{
	return west;
}

void Space::setNorth(Space *n)
{
	north = n;
}

Space * Space::getNorth()
{
	return north;
}

void Space::setSouth(Space *s)
{
	south = s;
}

Space * Space::getSouth()
{
	return south;
}

int Space::menu(vector<string> *i)
{
	return 0;
}

string Space::getType()
{
	return type;
}

vector<Space*> Space::getExits() {
	vector<Space*> exitList;
	Space* exit;
	 
	if ((exit = room->getNorth()) != 0) {
			exitList.push_back(exit);
	}
	if ((exit = room->getSouth()) != 0) {
		exitList.push_back(exit);
	}
	if ((exit = room->getEast()) != 0) {
		exitList.push_back(exit);
	}
	if ((exit = room->getWest()) != 0) {
		exitList.push_back(exit);
	}
	return exitList;
}

vector<string> Space::getExitDirections() {
	vector<string> exitList;
	Space* exit;

	if ((exit = room->getNorth()) != 0) {
		exitList.push_back("north");
	}
	if ((exit = room->getSouth()) != 0) {
		exitList.push_back("south");
	}
	if ((exit = room->getEast()) != 0) {
		exitList.push_back("east");
	}
	if ((exit = room->getWest()) != 0) {
		exitList.push_back("west");
	}
	return exitList;
}
