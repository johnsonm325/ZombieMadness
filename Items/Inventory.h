#ifndef INVENTORY_H
#define INVENTORY_H

#include "Object.h"

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
    vector<Object*> objects;
    string type;
public:
    Inventory(string);
    virtual ~Inventory();
    string getInventoryType();
    vector<Object*> getObjects();
    virtual bool isEmpty();
    Object* findObject(string);
    Object* selectObject(string);
    string strToLowerCase(string input);
    virtual void addObject(Object*);
    virtual void removeObject(Object*);
	virtual void printInventory();
    void clearInventory();
};

#endif
