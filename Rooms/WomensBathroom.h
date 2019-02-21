#ifndef WOMENSBATHROOM_H
#define WOMENSBATHROOM_H

#include "Space.h"
#include "../Items/PlayerInventory.h"

class WomensBathroom : public Space
{
private:
	string action;		//string action typed in by the user
	bool goneColt = false;
	     
	PlayerInventory *bag;
	Item *couch;
	Item *lock;
	Item *magazine;

public:
	WomensBathroom(PlayerInventory*);
	void printIntro();
	int menu(vector<string>);
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
	void increaseBagSize();
};
#endif
