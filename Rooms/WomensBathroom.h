#ifndef WOMENSBATHROOM_H
#define WOMENSBATHROOM_H

#include "Space.h"
#include "../Items/PlayerInventory.h"

class WomensBathroom : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;
	PlayerInventory *bag;

public:
	WomensBathroom(PlayerInventory*);
	void printIntro();
	int menu();
	void inspectToilet();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
	void increaseBagSize();
};
#endif
