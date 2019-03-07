#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "Color.h"

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
    vector<Item*> items;
    string type;
public:
    Inventory(string);
    virtual ~Inventory();
    string getInventoryType();
    vector<Item*> getItems();
    virtual bool isEmpty();
    Item* findItem(string);
    Item* selectItem(string);
    string strToLowerCase(string input);
    virtual void addItem(Item*);
    virtual void removeItem(Item*);
	virtual void printInventory();
    void clearInventory();
};

#endif
