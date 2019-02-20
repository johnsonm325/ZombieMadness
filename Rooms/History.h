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
	bool goneColt = false;
	Literature *lit;
	Item *georgeWashingtonBust;
	Item *billOfRights;

public:
	History();
	void printIntro();
	int menu(vector<string>);
	void inspectBust();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
