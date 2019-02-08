#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::remove;
using std::cout;
using std::endl;

class Inventory
{
protected:
    int size;
    vector<Item*> objects;
    string type;
public:
    Inventory(string);
    virtual ~Inventory();
    string getInventoryType();
    vector<Item*> getObjects();
    virtual bool isEmpty();
    Item* findObject(string);
    Item* selectObject(string);
    string strToLowerCase(string input);
    virtual void addObject(Item*);
    virtual void removeObject(Item*);
	virtual void printInventory();
    void clearInventory();
};

#endif
