#include "Player.h"

Player::Player() : Creature("Player")
{
	//will be defined in sub classes
	this->name = "Colt";
	this->attack = 4;
	this->defense = 5;
	this->healthBoost = 10;
}

Player::~Player()
{
	//undefined
}
void Player::useItem(Object* item) {

}

void Player::attackEnemy(Creature* enemy) {

}