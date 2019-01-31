#include "Inventory.h"

Inventory::Inventory(string t)
{
    // attributes decided in subclasses
    type = t;
}

Inventory::~Inventory()
{
    // undefined
}

vector<Object*> Inventory::getObjects()
{
    return objects;
}

string Inventory::getInventoryType()
{
    return type;
}

void Inventory::addObject(Object* obj)
{
    objects.push_back(obj);
}

void Inventory::removeObject(Object* obj)
{
    objects.erase(remove(objects.begin(), objects.end(), obj), objects.end());
}

void Inventory::printInventory() {

}
