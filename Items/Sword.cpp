#include "Sword.h"

Sword::Sword() : Item()
{
	this->description = "Time to slice and dice!!  Use this high-powered weapon to really cut those zombies down to size.";
	this->type = "Weapon";
	this->name = "Sword";
	this->attack = 10;
	this->defense = 0;
	this->size = 3;
}

void Sword::useItem()
{
	//to be determined
}

void Sword::setLocation(string l)
{
	this->location = l;
}