#include "BaseballBat.h"

BaseballBat::BaseballBat() : Object()
{
	this->description = "Swing away Colt.  Use this mid-leveled weapon to bash some zombies!";
	this->type = "Weapon";
	this->attack = 6;
	this->defense = 0;
}

void BaseballBat::useItem()
{
	//to be determined
}

void BaseballBat::setLocation(string l)
{
	this->location = l;
}