#include "Knife.h"

Knife::Knife() : Item()
{
	this->description = "Probably the weakest weapon you can find, but hey, better than trying to fist fight a zombie huh?";
	this->type = "Weapon";
	this->name = "Knife";
	this->attack = 4;
	this->defense = 0;
	this->size = 1;
}

void Knife::useItem()
{
	//to be determined
}