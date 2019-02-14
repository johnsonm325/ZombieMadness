#ifndef FIRSTFLOORHALLWAY_H
#define FIRSTFLOORHALLWAY_H

#include "Space.h"

class FirstFloorHallway : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;

public:
	FirstFloorHallway();
	void printIntro();
	int menu(vector<string>);
	void inspectToilet();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
