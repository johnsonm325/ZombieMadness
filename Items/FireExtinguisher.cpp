#include "FireExtinguisher.h"

FireExtinguisher::FireExtinguisher() : Item()
{
	this->description = "Don't use this to put out a flaming zombie, let that thing burn! Use this mid-leveled weapon to throw at a zombie.";
	this->type = "Weapon";
	this->name = "Fire Extinguisher";
	this->attack = 35;
	this->defense = 0;
	this->size = 2;
}

void FireExtinguisher::attackItem()
{
	cout << KGRN "# Time to bash some skulls and put some fires out, attacking with the fire extinguisher!" RESET << endl;
}