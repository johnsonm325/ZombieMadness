#ifndef FIRSTFLOORHALLWAY_H
#define FIRSTFLOORHALLWAY_H

#include "Space.h"

class FirstFloorHallway : public Space
{
private:
	string action;		//string action typed in by the user
	bool vendingMachineUsed = false;
	Item *vomit;
	Item *vendingMachine;
	Item *snack;

public:
	FirstFloorHallway();
	FirstFloorHallway(bool);
	~FirstFloorHallway();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	bool getVendingMachineUsed();
	void useVendingMachine();
	void eatSnack();
};
#endif
