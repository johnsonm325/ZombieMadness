#include "Map.h"

Map::Map() : Object()
{
	//TBD
	this->name = "Map";
	this->description = "It's always good to know where you are! This Map gives you a good view of what the school layout looks like.";
	this->type = "Misc";
}

void Map::useItem()
{
	//TBD
}

void Map::setLocation(string l)
{
	this->location = l;
}
