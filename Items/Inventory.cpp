#include "Inventory.h"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\x1B[0m"

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
		cout << KRED "Item not found in inventory!" RESET << endl;
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
	cout << KYEL "=== Room Inventory ===" RESET << endl;
	if (isEmpty()) {
		cout << KYEL "None!" RESET << endl;
        return;
	}

    for (unsigned int i = 0; i < items.size(); i++) {
        cout << KYEL << (i + 1) << ": " << items[i]->getName() << endl;
    }

    cout << "#" RESET << endl;
}

void Inventory::clearInventory(){
    items.clear();
}
