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
    void addObject(Object);
    void removeObject(Object, bool);
    bool isFull();
    bool isEmpty();
    void increaseSize(); // called when backpack is obtained
};

#endif