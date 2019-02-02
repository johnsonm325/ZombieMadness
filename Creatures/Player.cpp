#include "Player.h"

Player::Player(PlayerInventory *bag, Inventory *rooms) : Creature("Player")
{
	//will be defined in sub classes
	this->name = "Colt";
	// this->attack = 4;
	// this->defense = 5;
	this->health = 100;
	this->playerInventory = bag;
	this->roomInventory = rooms;
}

Player::~Player()
{
	//undefined
}

void Player::useItem(Object* item) {
	string type = item->getType();

	if (type == "Weapon")
	{
		// logic to determine how to use weapon
	}
	
	else if (type == "Room Object")
	{
		// logic to determine use
	}

	else if (type == "Supply")
	{
		// logic to determine use
	}

	else
	{
		// logic to determine Misc use
	}
	
	playerInventory->removeObject(item, true);

	roomInventory->removeObject(item);
}

void Player::attackEnemy(Creature* enemy) {

}