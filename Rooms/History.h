#ifndef HISTORY_H
#define HISTORY_H

#include "Space.h"
#include "Literature.h"
#include "../Items/Item.h"
#include "../Items/Knife.h"

class History : public Space
{
private:
	string action;		//string action typed in by the user
	Literature *lit;
	Item *georgeWashingtonBust;
	Item *billOfRights;

public:
	History();
	~History();	
	void printIntro();
	void inspectBust();
};
#endif
