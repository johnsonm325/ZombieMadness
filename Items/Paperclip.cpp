#include "Paperclip.h"

Paperclip::Paperclip() : Item()
{
	//undefined
	this->name = "Paperclip";
	this->description = "Not all locked doors need a key! Use a Paperclip to pick locks, but be warned... you may fail and end up breaking your Paperclip!";
	this->type = "Room Object";
	this->size = 1;
}

void Paperclip::useItem(){
	
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

