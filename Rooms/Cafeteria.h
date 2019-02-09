#ifndef CAFETERIA_H
#define CAFETERIA_H

#include "Space.h"
#include "Chemistry.h"
#include "../Items/Item.h"

class Cafeteria : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;
	Chemistry *chem;
	Item *food;

public:
	Cafeteria();
	void printIntro();
	int menu();
	void throwFood();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
