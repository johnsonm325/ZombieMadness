#ifndef LITERATURE_H
#define LITERATURE_H

#include "Space.h"

class Literature : public Space
{
private:
	string action;		//string action typed in by the user
	bool goneColt = false,
	     deadZombies = false,
	     noteVisible = false;
	Item *chalkboard;
	Item *desk;
	Item *note;

public:
	Literature();
	void printIntro();
	int menu(vector<string>);
	void inspectDesk();
	void zombiesDead();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
