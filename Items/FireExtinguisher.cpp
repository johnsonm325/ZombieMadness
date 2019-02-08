#include "FireExtinguisher.h"

FireExtinguisher::FireExtinguisher() : Item()
{
	this->description = "Don't use this to put out a flaming zombie, let that thing burn! Use this mid-leveled weapon to throw at a zombie.";
	this->type = "Weapon";
	this->name = "Fire Extinguisher";
	this->attack = 8;
	this->defense = 0;
}

void FireExtinguisher::useItem()
{
	//to be determined
}

void FireExtinguisher::setLocation(string l)
{
	this->location = l;
}