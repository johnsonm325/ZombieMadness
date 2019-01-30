#include "Paperclip.h"

Paperclip::Paperclip() : Object()
{
	//undefined
	this->name = "Paperclip";
}

bool Paperclip::canPickLock()
{
	//return true or false depending on different params
	return true;
}

void Paperclip::pickLock()
{
	//TBD
}

void Paperclip::setLocation(string l)
{
	this->location = l;
}


