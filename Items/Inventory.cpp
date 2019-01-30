#include "Inventory.h"
using std::remove;

Inventory::Inventory()
{
    // attributes decided in subclasses
}

Inventory::~Inventory()
{
    // undefined
}

vector<Object> Inventory::getObjects()
{
    return objects;
}

string Inventory::getInventoryType()
{
    return type;
}

void Inventory::addObject(Object obj)
{
    objects.push_back(obj);
}

void Inventory::removeObject(Object obj)
{
    objects.erase(remove(objects.begin(), objects.end(), obj), objects.end());
}