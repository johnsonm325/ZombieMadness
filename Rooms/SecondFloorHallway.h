#ifndef SECONDFLOORHALLWAY_H
#define SECONDFLOORHALLWAY_H

#include "Space.h"

class SecondFloorHallway : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;

public:
	SecondFloorHallway();
	void printIntro();
	int menu();
	void inspectToilet();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
