#include "Key.h"

Key::Key() : Object()
{
	//undefined
	this->name = "Key";
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
