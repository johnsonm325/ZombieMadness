#ifndef GYMNASIUMFLOOR1_H
#define GYMNASIUMFLOOR1_H

#include "Space.h"

class GymnasiumFloor1 : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false,
	     zombiesDead = false;

public:
	GymnasiumFloor1();
	int menu(vector<string>*);
	bool ropesCut();
	bool zombiesDead();
	void inspectToilet();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
