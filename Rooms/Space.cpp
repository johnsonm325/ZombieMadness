#include "Space.h"

Space::Space(string t)
{
	type = t;
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
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
	if(east == NULL)
	{
		cout << "Nothing is in that direction" << endl;
	}
	return east;
}

void Space::setWest(Space *w)
{
	west = w;
}

Space * Space::getWest()
{
	if(west == NULL)
	{
		cout << "Nothing is in that direction" << endl;	 
	}
	return west;
}

void Space::setNorth(Space *n)
{
	north = n;
}

Space * Space::getNorth()
{
	if (north == NULL)
	{
		cout << "Nothing is in that direction" << endl;
	}
	return north;
}

void Space::setSouth(Space *s)
{
	south = s;
}

Space * Space::getSouth()
{
	if (south == NULL)
	{
		cout << "Nothing is in that direction" << endl;
	}
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

// Return a vector of available room pointers that
// player can move to from current room = this
vector<Space*> Space::getExits() {
	vector<Space*> exitList;
	Space* exit;
	 
	if ((exit = this->getNorth()) != 0) {
		exitList.push_back(exit);
	}
	if ((exit = this->getSouth()) != 0) {
		exitList.push_back(exit);
	}
	if ((exit = this->getEast()) != 0) {
		exitList.push_back(exit);
	}
	if ((exit = this->getWest()) != 0) {
		exitList.push_back(exit);
	}
	return exitList;
}

// Return a vector of available room direction strings(north, south, etc)
// that player can move to from current room
vector<string> Space::getExitDirections() {
	vector<string> exitList;
	Space* exit;

	if ((exit = this->getNorth()) != 0) {
		exitList.push_back("north");
	}
	if ((exit = this->getSouth()) != 0) {
		exitList.push_back("south");
	}
	if ((exit = this->getEast()) != 0) {
		exitList.push_back("east");
	}
	if ((exit = this->getWest()) != 0) {
		exitList.push_back("west");
	}
	return exitList;
}
