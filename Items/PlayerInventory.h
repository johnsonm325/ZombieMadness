#ifndef PLAYER_INVENTORY_H
#define PLAYER_INVENTORY_H

#include "Inventory.h"

class PlayerInventory : public Inventory
{
private:
    int openSlots;
    int usedSlots;
    int size;
    bool silent = false;

public:
    PlayerInventory();
    ~PlayerInventory();
    void addItem(Item*);
    void removeItem(Item*, bool);
    int getUsedSlots();
    int getOpenSlots();
    int getSize();
    bool isEmpty();
    bool isFull();
    void increaseSize(); // called when backpack is obtained
    bool hasWeapon();
    bool hasDefense();
	void printInventory();
    void printAvailableWeapons();
    void printAvailableSupplies();
    void printAvailableRoomObjects();
    void printAvailableMiscItems();
    void printAvailableDefenseItems();
    bool canAdd(Item*);
    void printInventoryUsage();
    void setLogLevel(bool);
};

#endif