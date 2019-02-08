#ifndef PLAYER_INVENTORY_H
#define PLAYER_INVENTORY_H

#include "Inventory.h"

class PlayerInventory : public Inventory
{
private:
    int openSlots;
    int usedSlots;
public:
    PlayerInventory();
    ~PlayerInventory();
    void addItem(Item*);
    void removeItem(Item*, bool);
    int getUsedSlots();
    int getOpenSlots();
    bool isEmpty();
    bool isFull();
    void increaseSize(); // called when backpack is obtained
	void printInventory();
    void printAvailableWeapons();

};

#endif