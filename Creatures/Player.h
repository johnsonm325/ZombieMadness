#ifndef PLAYER_H
#define PLAYER_H

#include "../Rooms/Space.h"
#include "Creature.h"
#include "../Items/PlayerInventory.h"
#include "../Items/Inventory.h"

#include <string>
using std::string;

class Player
{
private:
	PlayerInventory *playerInventory;
	Inventory *roomInventory; // room's inventory class is passed in here
	Creature *enemy;  	// passed in enemy
	Creature *player;	//Actual player's data
	Space* currentRoom;
public:
	Player();
	~Player();
	void movetoRoom(Space*);
	PlayerInventory* getInventory();
	Inventory* getRoomInventory();
	void clearInventory();
	void useItem(Item* item);
	void attackEnemy(string);
	//void attackEnemy(Creature*);

	void takeItem(Item*);
	void dropItem(Item*);
	
};

#endif