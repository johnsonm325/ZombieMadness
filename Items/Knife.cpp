#include "Knife.h"

Knife::Knife()
{
	this->description = "Probably the weakest weapon you can find, but hey, better than trying to fist fight a zombie huh?";
	this->type = "Weapon";
	this->attack = 4;
	this->defense = 0;
}

void Knife::useItem()
{
	//to be determined
}

void Knife::setLocation(string l)
{
	this->location = l;
}
