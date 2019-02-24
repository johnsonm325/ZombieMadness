#include "PlayerInventory.h"

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
    if (usedSlots == size)
        return true;

    return false;
}
bool PlayerInventory::isEmpty()
{
    if (openSlots == size)
        return true;

    return false;
}

bool PlayerInventory::canAdd(Item *item)
{
    int totalSize = usedSlots + item->getSize();

    if (totalSize > openSlots)
        return false;

    return true;
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
        openSlots--;
        usedSlots++;
        cout << item->getName() << " was successfully added to your inventory." << endl;
    }

    else
        cout << "Your inventory is either full or the item size exceeds available capacity."<< endl;
    
}

// game will pass wasUsed as true if player used the item from their inventory
// wasUsed should otherwise be false
void PlayerInventory::removeItem(Item* item, bool wasUsed)
{
    if (!isEmpty())
    {
        items.erase(remove(items.begin(), items.end(), item), items.end());
        openSlots++;
        usedSlots--;

        if (wasUsed)
            return;
        else
            cout << item->getName() << " was succesfully removed from your inventory." << endl;
        
    }

    else
        cout << "Your inventory has nothing in it!" << endl;
    
}

void printInventoryHelper(vector<Item*> items, string type, bool isEmpty)
{
    string newLine = "#\n";
    
    if (isEmpty)
    {
        cout << "None!" << endl;
        cout << newLine;
    }

    else if (!type.empty())
    {
        for (unsigned int i = 0; i < items.size(); i++)
        {
            if (items[i]->getType() == type)
                cout << items[i]->getName() << endl;
        }

        cout << newLine;
    }

    else
    {
        for (unsigned int i = 0; i < items.size(); i++)
            cout << (i + 1) << ": " << items[i]->getName() << endl;

        cout << newLine;
    }

}

void PlayerInventory::printInventory() {
	cout << "=== Player's Inventory ===" << endl;
	printInventoryHelper(items, "", isEmpty());
}

void PlayerInventory::printAvailableWeapons()
{
    cout << "   Available Weapons" << endl;
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
    cout << "   Available Supplies" << endl;

    printInventoryHelper(items, "Supply", isEmpty());
}

void PlayerInventory::printAvailableRoomObjects()
{
    cout << "   Available Room Objects" << endl;

    printInventoryHelper(items, "Room Object", isEmpty());
}

void PlayerInventory::printAvailableMiscItems()
{
    cout << "Available Misc Items" << endl;

    printInventoryHelper(items, "Misc", isEmpty());
}
