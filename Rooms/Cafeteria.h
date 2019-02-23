#ifndef CAFETERIA_H
#define CAFETERIA_H

#include "Space.h"
#include "Chemistry.h"
#include "../Items/Item.h"

class Cafeteria : public Space
{
private:
	string action;		//string action typed in by the user
	Chemistry *chem;
	Item *food;

public:
	Cafeteria();
	~Cafeteria();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void throwFood();
	
};
#endif
