#include "Knife.h"

Knife::Knife() : Item()
{
	this->description = "Probably the weakest weapon you can find, but hey, better than trying to fist fight a zombie huh?";
	this->type = "Weapon";
	this->name = "Knife";
	this->attack = 30;
	this->defense = 0;
	this->size = 1;
}

void Knife::attackItem()
{
	cout << KGRN "# Shank em' and run, attacking with the knife!" RESET << endl;
}