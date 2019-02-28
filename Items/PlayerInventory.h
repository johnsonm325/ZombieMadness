#ifndef PLAYER_INVENTORY_H
#define PLAYER_INVENTORY_H

#include "Inventory.h"

class PlayerInventory : public Inventory
{
private:
    int openSlots;
    int usedSlots;
    int size;

public:
    PlayerInventory();
    ~PlayerInventory();
    void addItem(Item*);
    void removeItem(Item*, bool);

    //Getters
    int getUsedSlots();
    int getOpenSlots();
    int getSize();
    bool isEmpty();
    bool isFull();

    //Setters
    void increaseSize(); // called when backpack is obtained
	void printInventory();
    void printAvailableWeapons();
    void printAvailableSupplies();
    void printAvailableRoomObjects();
    void printAvailableMiscItems();
    bool canAdd(Item*);

};

#endif