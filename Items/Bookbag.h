#ifndef BOOKBAG_H
#define BOOKBAG_H

#include "Object.h"
#include "PlayerInventory.h"

class Bookbag : public Object
{
private:
	PlayerInventory *inventory;
public:
	Bookbag(PlayerInventory*);
	void increaseSize();
	void setLocation(string);
};

#endif