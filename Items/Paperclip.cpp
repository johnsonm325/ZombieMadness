#include "Paperclip.h"

Paperclip::Paperclip() : Object()
{
	//undefined
	this->name = "Paperclip";
	this->description = "Not all locked doors need a key! Use a Paperclip to pick locks, but be warned... you may fail and end up breaking your Paperclip!";
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


