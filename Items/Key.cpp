#include "Key.h"

Key::Key() : Object()
{
	//undefined
}

bool Key::canUnlock()
{
	//return true or false if key can unlock
}

void Key::unlock()
{
	//TBD
}

void Key::setLocation(string l)
{
	this->location = l;
}
