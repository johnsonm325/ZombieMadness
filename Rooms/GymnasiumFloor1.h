#ifndef GYMNASIUMFLOOR1_H
#define GYMNASIUMFLOOR1_H

#include "Space.h"

class GymnasiumFloor1 : public Space
{
private:
	string action;		//string action typed in by the user
	bool goneColt = false,
	     deadZombies = false;

public:
	GymnasiumFloor1();
	void printIntro();
	int menu(vector<string>);
	void ropesCut();
	void zombiesDead();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
