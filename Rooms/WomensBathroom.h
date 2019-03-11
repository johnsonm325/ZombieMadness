#ifndef WOMENSBATHROOM_H
#define WOMENSBATHROOM_H

#include "Space.h"
#include "../Items/PlayerInventory.h"
#include "../Items/Bookbag.h"

class WomensBathroom : public Space
{
private:
	string action;		//string action typed in by the user
	PlayerInventory *bag;
	Item *couch;
	Item *magazine;

public:
	WomensBathroom(PlayerInventory*);
	~WomensBathroom();
	void printIntro();
	void increaseBagSize();
};
#endif
