#ifndef PLAYER_H
#define PLAYER_H

#include "../Rooms/Space.h"
#include "Zombie.h"
#include "../Items/PlayerInventory.h"
#include "../Items/Inventory.h"

#include <string>
#include <stdlib.h>
using std::string;
using std::cin;
using std::getline;
using std::transform;

class Player
{
private:
	PlayerInventory *playerInventory;
	Inventory *roomInventory; // room's inventory class is passed in here
	Zombie *enemy = NULL; 	// passed in enemy
	Creature *player = NULL;	//Actual player's data
	Space* currentRoom = NULL;
public:
	Player();
	~Player();
	void movetoRoom(Space*);
	PlayerInventory* getInventory();
	Inventory* getRoomInventory();
	void clearInventory();
	void useItem(Item* item);
	void attackEnemy();
	void defend();
	void takeItem(Item*);
	void dropItem(Item*);
	void lookAtItems(string item);
	Item* selectItem(string item);
	Creature* getPlayer();
	void printStats();
};

#endif