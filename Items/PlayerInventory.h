#ifndef PLAYER_INVENTORY_H
#define PLAYER_INVENTORY_H

#include "Inventory.h"
using std::remove;
using std::cout;
using std::endl;

class PlayerInventory : public Inventory
{
private:
    int openSlots;
    int usedSlots;
public:
    PlayerInventory();
    void addObject(Object*);
    void removeObject(Object*, bool);
    int getUsedSlots();
    int getOpenSlots();
    bool isFull();
    bool isEmpty();
    void increaseSize(); // called when backpack is obtained
	void printInventory();
    void printAvailableWeapons();
};

#endif