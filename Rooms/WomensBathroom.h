#ifndef WOMENSBATHROOM_H
#define WOMENSBATHROOM_H

#include "Space.h"
#include "../Items/PlayerInventory.h"

class WomensBathroom : public Space
{
private:
	string action;		//string action typed in by the user
	PlayerInventory *bag;
	Item *couch;
	Item *lock;
	Item *magazine;

public:
	WomensBathroom(PlayerInventory*);
	~WomensBathroom();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void increaseBagSize();
	
};
#endif
