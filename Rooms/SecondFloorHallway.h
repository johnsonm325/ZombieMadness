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
	SecondFloorHallway(bool);
	void printIntro();
	int menu(vector<string>);
	void inspectToilet();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
