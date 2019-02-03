#ifndef INVENTORY_H
#define INVENTORY_H

#include "Object.h"
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
using std::remove;

class Inventory
{
protected:
    int size;
    vector<Object*> objects;
    string type;
public:
    Inventory(string);
    virtual ~Inventory();
    string getInventoryType();
    vector<Object*> getObjects();
    Object* findItem(string);
    virtual void addObject(Object*);
    virtual void removeObject(Object*);
	virtual void printInventory();
};

#endif
