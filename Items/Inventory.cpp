#include "Inventory.h"

Inventory::Inventory(string t)
{
    // attributes decided in subclasses
    type = t;
}

Inventory::~Inventory()
{
    for(unsigned int i = 0; i < items.size(); i++)
    {
        delete items[i];
        items[i] = nullptr;
    }
}

vector<Item*> Inventory::getItems()
{
    return items;
}
bool Inventory::isEmpty(){
    return items.size() == 0;
}

Item* Inventory::findItem(string name)
{
    for (unsigned int index = 0; index < this->items.size(); index++)
    {
        string nameLowerCase = strToLowerCase(this->items[index]->getName());
        string inputLowerCase = strToLowerCase(name);
        if (nameLowerCase == inputLowerCase){
            return this->items[index];
        }
    }

    return NULL;
}

Item* Inventory::selectItem(string item){

	Item* selectedItem = findItem(item);
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

void Inventory::addItem(Item* item)
{
    items.push_back(item);
}

void Inventory::removeItem(Item* item)
{
    items.erase(remove(items.begin(), items.end(), item), items.end());
}

void Inventory::printInventory() {
	cout << "=== Room Inventory ===" << endl;
	if (isEmpty()) {
		cout << "EMPTY" << endl;
        return;
	}

    for (unsigned int i = 0; i < items.size(); i++) {
        cout << (i + 1) << ": " << items[i]->getName() << endl;
    }
}

void Inventory::clearInventory(){
    items.clear();
}
