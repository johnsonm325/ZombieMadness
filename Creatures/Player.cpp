#include "Player.h"
using std::cout;
using std::endl;

Player::Player() : Creature("Player")
{
	//will be defined in sub classes
	this->name = "Colt";
	// this->attack = 4;
	// this->defense = 5;
	this->health = 100;
	this->playerInventory = new PlayerInventory();
}

Player::~Player()
{
	delete this->playerInventory;
}

void Player::setRoom(Inventory* curRoom)
{
	this->roomInventory = curRoom;
}

void Player::useItem(Object* item) {
	item->useItem();
	
	playerInventory->removeObject(item, true);

	roomInventory->removeObject(item);
}

void Player::attackEnemy(string item) 
{
	Object *weapon = this->playerInventory->findItem(item);

	if (!weapon)
	{
		cout << "That weapon could not be found in your inventory, please try a different weapon." << endl;
		return;
	}

	weapon->useItem();
}