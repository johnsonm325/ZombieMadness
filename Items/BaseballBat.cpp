#include "BaseballBat.h"

BaseballBat::BaseballBat() : Item()
{
	this->description = "Swing away Colt.  Use this mid-leveled weapon to bash some zombies!";
	this->type = "Weapon";
	this->name = "Baseball Bat";
	this->attack = 6;
	this->defense = 0;
	this->size = 2;
}

void BaseballBat::useItem(){

}

// void BaseballBat::damageZombie(Creature *enemy)
// {
// 	enemy->takeDamage(this->attack);
// }

void BaseballBat::setLocation(string l)
{
	this->location = l;
}