#ifndef INVENTORY_H
#define INVENTORY_H

#include "Object.h"
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Inventory
{
protected:
    int size;
    vector<Object> objects;
    string type;
public:
    Inventory();
    virtual ~Inventory();
    string getInventoryType();
    vector<Object> getObjects();
    virtual void addObject(Object);
    virtual void removeObject(Object);
};

#endif