#ifndef SECONDFLOORHALLWAY_H
#define SECONDFLOORHALLWAY_H

#include "Space.h"

class SecondFloorHallway : public Space
{
private:
	string action;		//string action typed in by the user
	Item *deadBody;
	Item *bulletinBoard;

public:
	SecondFloorHallway();
	~SecondFloorHallway();
	void printIntro();
	void disableFirstTries();
};
#endif
