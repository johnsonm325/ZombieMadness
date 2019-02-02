#include "Player.h"
using std::cout;
using std::endl;

Player::Player(Inventory *rooms) : Creature("Player")
{
	//will be defined in sub classes
	this->name = "Colt";
	// this->attack = 4;
	// this->defense = 5;
	this->health = 100;
	this->playerInventory = new PlayerInventory();
	this->roomInventory = rooms;
}

Player::~Player()
{
	delete this->playerInventory;
}

void Player::useItem(Object* item) {
	item->useItem();
	
	playerInventory->removeObject(item, true);

	roomInventory->removeObject(item);
}

void Player::attackEnemy(string item) 
{
	vector<Object*> objs = this->playerInventory->getObjects();
	Object *weapon;

	for (int index = 0; index < objs.size(); index++)
	{
		if (objs[index]->getName() == item)
		{
			weapon = objs[index];
			break;
		}
	}

	if (!weapon)
	{
		cout << "That weapon could not be found in your inventory, please try a different weapon." << endl;
		return;
	}

	weapon->useItem();
}