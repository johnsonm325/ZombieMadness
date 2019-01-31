#include "PlayerInventory.h"
using std::remove;
using std::cout;
using std::endl;

PlayerInventory::PlayerInventory() : Inventory("Player")
{
    this->type = "Player";
    this->size = 6; // TBD how many opening slots player should have
    this->openSlots = 6;
    this->usedSlots = 0;
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

void PlayerInventory::increaseSize()
{
    size += 6; // TBD the size we will increase it to
}

void PlayerInventory::addObject(Object* obj)
{
    if (!isFull())
    {
        objects.push_back(obj);
        openSlots--;
        usedSlots++;
        cout << obj->getName() << " was successfully added to your inventory." << endl;
    }

    else
        cout << "Your inventory is full! Consider removing an item to add this one." << endl;
    
}

// game will pass wasUsed as true if player used the item from their inventory
// wasUsed should otherwise be false
void PlayerInventory::removeObject(Object* obj, bool wasUsed)
{
    if (!isEmpty())
    {
        objects.erase(remove(objects.begin(), objects.end(), obj), objects.end());
        openSlots++;
        usedSlots--;

        if (wasUsed)
            return;
        else
            cout << obj->getName() << " was succesfully removed from your inventory." << endl;
        
    }

    else
        cout << "Your inventory has nothing in it!" << endl;
    
}

void PlayerInventory::printInventory() {
	cout << "=== Player's Inventory" << endl;
	if (isEmpty()) {
		cout << "EMPTY" << endl;
	}
	else {
		for (unsigned int i = 0; i < objects.size(); i++) {
			cout << (i + 1) << ": " << objects[i]->getName() << endl;
		}
	}
}
