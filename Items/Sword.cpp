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

void Sword::attackItem()
{
	cout << "# Slice n' dice baby, attacking with Sword!" << endl;
}
