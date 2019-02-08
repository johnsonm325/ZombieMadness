#ifndef GYMNASIUMFLOOR2_H
#define GYMNASIUMFLOOR2_H

#include "Space.h"

class GymnasiumFloor2 : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;
	Space *gym1;

public:
	GymnasiumFloor2();
	void printIntro();
	int menu();
	void cutRopes();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
