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
