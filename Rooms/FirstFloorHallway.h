#ifndef FIRSTFLOORHALLWAY_H
#define FIRSTFLOORHALLWAY_H

#include "Space.h"

class FirstFloorHallway : public Space
{
private:
	string action;		//string action typed in by the user
	Item *vomit;
	Item *bulletinBoard;

public:
	FirstFloorHallway();
	FirstFloorHallway(bool);
	~FirstFloorHallway();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
};
#endif
