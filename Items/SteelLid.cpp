#include "SteelLid.h"

SteelLid::SteelLid() : Object()
{
	this->description = "Throwing it back to the olden days.  Use this steel trashcan lid as a blocking mechanism.";
	this->type = "Weapon";
	this->attack = 0;
	this->defense = 4;
}

void SteelLid::useItem()
{
	//to be determined
}

void SteelLid::setLocation(string l)
{
	this->location = l;
}