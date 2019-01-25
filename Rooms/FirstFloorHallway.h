#ifndef FIRSTFLOORHALLWAY1_H
#define FIRSTFLOORHALLWAY1_H

#include "GymnasiumFloor1.h"

class FirstFloorHallway1 : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;

public:
	FirstFloorHallway1();
	int menu(vector<string>*);
	void inspectToilet();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
