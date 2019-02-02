#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "../Items/PlayerInventory.h"
#include "../Items/Inventory.h";

#include <string>
using std::string;

class Player: public Creature
{
private:
	PlayerInventory *playerInventory;
	Inventory *roomInventory; // room's inventory class is passed in here
	Creature *enemy; // passed in enemy
public:
	Player(Inventory*);
	~Player();
	void useItem(Object* item);
	void attackEnemy(string);
};

#endif