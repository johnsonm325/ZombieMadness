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

Object* Inventory::findItem(string name)
{
    for (int index = 0; index < this->objects.size(); index++)
    {
        if (this->objects[index]->getName() == name)
            return this->objects[index];
    }

    return NULL;
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
