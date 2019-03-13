#include "BaseballBat.h"

BaseballBat::BaseballBat() : Item()
{
	this->description = "# Swing away Colt.  Use this mid-leveled weapon to bash some zombies!";
	this->type = "Weapon";
	this->name = "Baseball Bat";
	this->attack = 40;
	this->defense = 0;
	this->size = 2;
}

void BaseballBat::attackItem()
{
	cout << KGRN "# Attacking creature with the baseball bat, smash their brains in!" RESET << endl;
}
