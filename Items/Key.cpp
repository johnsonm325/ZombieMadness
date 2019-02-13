#include "Key.h"

Key::Key() : Item()
{
	//undefined
	this->name = "Key";
	this->description = "Time to explore! This key will unlock various rooms, explore to find out which ones!";
	this->type = "Misc";
	this->size = 1;
}

bool Key::canUnlock()
{
	//return true or false if key can unlock
	return true;
}

void Key::unlock()
{
	//TBD
}

void Key::setLocation(string l)
{
	this->location = l;
}
