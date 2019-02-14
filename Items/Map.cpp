#include "Map.h"

Map::Map() : Item()
{
	//TBD
	this->name = "Map";
	this->description = "It's always good to know where you are! This Map gives you a good view of what the school layout looks like.";
	this->type = "Misc";
	this->size = 1;
}

void Map::useItem()
{
	//TBD
}