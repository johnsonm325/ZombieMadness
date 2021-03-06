#ifndef CAFETERIA_H
#define CAFETERIA_H

#include "Space.h"
#include "Chemistry.h"
#include "../Items/Item.h"

class Cafeteria : public Space
{
private:
	string action;		//string action typed in by the user
	bool vendingMachineUsed = false;
	Chemistry *chem;
	Item *food;
	Item *sloppyJoe;
	Item *vendingMachine;
	Item *snack = NULL;

public:
	Cafeteria();
	~Cafeteria();
	void printIntro();
	void throwFood();
	bool getVendingMachineUsed();
	void useVendingMachine();
	void eatSnack();
};
#endif
