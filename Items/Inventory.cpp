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
bool Inventory::isEmpty(){
    return objects.size() == 0;
}

Object* Inventory::findObject(string name)
{
    for (unsigned int index = 0; index < this->objects.size(); index++)
    {
        string nameLC = strToLowerCase(this->objects[index]->getName());
        if ((this->objects[index]->getName() == name) || (nameLC == name)){
            return this->objects[index];
        }
    }

    return NULL;
}

Object* Inventory::selectObject(string item){

	Object* selectedItem = findObject(item);
	if(selectedItem == NULL){
		cout << "Item not found in inventory!" << endl;
		return 0;
	}
	else{
		return selectedItem;
	}
}

string Inventory::strToLowerCase(string input){
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
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
	cout << "=== Room Inventory ===" << endl;
	if (isEmpty()) {
		cout << "EMPTY" << endl;
        return;
	}

    for (unsigned int i = 0; i < objects.size(); i++) {
        cout << (i + 1) << ": " << objects[i]->getName() << endl;
    }
}

void Inventory::clearInventory(){
    objects.clear();
}
