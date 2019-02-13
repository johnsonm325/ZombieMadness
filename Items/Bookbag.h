#ifndef BOOKBAG_H
#define BOOKBAG_H

#include "Item.h"
#include "PlayerInventory.h"

class Bookbag : public Item
{
private:
	PlayerInventory *inventory; // passed in player inventory
public:
	Bookbag(PlayerInventory*);
	void increaseSize();
	void setLocation(string);
	void useItem();
};

#endif