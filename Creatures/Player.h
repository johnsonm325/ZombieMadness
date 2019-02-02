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
	Inventory *roomInventory;
public:
	Player(PlayerInventory*, Inventory*);
	~Player();
	void useItem(Object* item);
	void attackEnemy(Creature* enemy);

};

#endif