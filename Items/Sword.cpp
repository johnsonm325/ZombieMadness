#include "Sword.h"

Sword::Sword() : Object()
{
	this->description = "Time to slice and dice!!  Use this high-powered weapon to really cut those zombies down to size.";
	this->type = "Weapon";
	this->attack = 10;
	this->defense = 0;
}

void Sword::useItem()
{
	//to be determined
}

void Sword::setLocation(string l)
{
	this->location = l;
}