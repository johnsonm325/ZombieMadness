#ifndef GYMNASIUMFLOOR2_H
#define GYMNASIUMFLOOR2_H

#include "Space.h"
#include "GymnasiumFloor1.h"
#include "../Items/Item.h"
#include "../Items/Gun.h"

class GymnasiumFloor2 : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;
	GymnasiumFloor1 *gym1;
	Item *ropes;

public:
	GymnasiumFloor2();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void cutRopes();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
