#include "PlayerInventory.h"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\x1B[0m"

PlayerInventory::PlayerInventory() : Inventory("Player")
{
    this->type = "Player";
    this->size = 6; // TBD how many opening slots player should have
    this->openSlots = 6;
    this->usedSlots = 0;
}

PlayerInventory::~PlayerInventory(){
    
}

bool PlayerInventory::isFull()
{
    return usedSlots == size;
}

bool PlayerInventory::isEmpty()
{
    return openSlots == size;
}

bool PlayerInventory::canAdd(Item *item)
{
    return item->getSize() + usedSlots <= size;
}

void PlayerInventory::increaseSize()
{
    size += 6; // TBD the size we will increase it to
}

void PlayerInventory::addItem(Item* item)
{
    if (!isFull() && canAdd(item))
    {
        items.push_back(item);
        openSlots -= item->getSize();
        usedSlots += item->getSize();
        cout << KGRN << item->getName() << " was successfully added to your inventory." RESET << endl;
    }

    else
        cout << KRED "Your inventory is either full or the item size exceeds available capacity." RESET << endl;
    
}

// game will pass wasUsed as true if player used the item from their inventory
// wasUsed should otherwise be false
void PlayerInventory::removeItem(Item* item, bool wasUsed)
{
    if (!isEmpty())
    {
        items.erase(remove(items.begin(), items.end(), item), items.end());
        openSlots += item->getSize();
        usedSlots -= item->getSize();

        if (wasUsed)
        {
            delete item;
            item = NULL;
            return;
        }

        else
            cout << KGRN << item->getName() << " was succesfully removed from your inventory." RESET << endl;
        
    }

    else
        cout << KRED "Your inventory has nothing in it!" RESET << endl;
    
}

bool typeChecker(vector<Item*> items, string type)
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i]->getType() == type)
            return true;
    }

    return false;
}

bool PlayerInventory::hasWeapon()
{
    return typeChecker(items, "Weapon");
}

bool PlayerInventory::hasDefense()
{
    return typeChecker(items, "Defense");
}

void printInventoryHelper(vector<Item*> items, string type, bool isEmpty)
{   
    if (isEmpty)
    {
        cout << KYEL "None!" RESET << endl;
        cout << endl;
    }

    else if (!type.empty())
    {
        for (unsigned int i = 0; i < items.size(); i++)
        {
            if (items[i]->getType() == type)
                cout << KYEL << items[i]->getName() << endl;
        }

        cout << RESET << endl;
    }

    else
    {
        for (unsigned int i = 0; i < items.size(); i++)
            cout << KYEL << (i + 1) << ": " << items[i]->getName() << endl;

        cout << RESET << endl;
    }

}

void PlayerInventory::printInventory() {
	cout << KYEL "=== Player's Inventory ===" RESET << endl;
	printInventoryHelper(items, "", isEmpty());
}

void PlayerInventory::printAvailableWeapons()
{
    cout << KYEL "=== Available Weapons ===" RESET << endl;
    printInventoryHelper(items, "Weapon", isEmpty());
}

int PlayerInventory::getOpenSlots()
{
    return openSlots;
}

int PlayerInventory::getUsedSlots()
{
    return usedSlots;
}

void PlayerInventory::printAvailableSupplies()
{
    cout << KYEL "===vAvailable Supplies ===" RESET << endl;

    printInventoryHelper(items, "Supply", isEmpty());
}

void PlayerInventory::printAvailableRoomObjects()
{
    cout << KYEL "=== Available Room Objects ===" RESET << endl;

    printInventoryHelper(items, "Room Object", isEmpty());
}

void PlayerInventory::printAvailableMiscItems()
{
    cout << KYEL "=== Available Misc Items ===" RESET << endl;

    printInventoryHelper(items, "Misc", isEmpty());
}

void PlayerInventory::printAvailableDefenseItems()
{
    cout << KYEL "=== Available Defense Items ===" RESET << endl;

    printInventoryHelper(items, "Defense", isEmpty());
}

int PlayerInventory::getSize(){
    return size;
}
