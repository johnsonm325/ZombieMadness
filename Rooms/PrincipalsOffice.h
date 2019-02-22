#ifndef PRINCIPALSOFFICE_H
#define PRINCIPALSOFFICE_H

#include "Space.h"
#include "../Items/FireExtinguisher.h"
#include "../Items/Key.h"

class PrincipalsOffice : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false,
	     deadZombies = false;
	Item *desk, *key, *PAsystem, *fireExt;

public:
	PrincipalsOffice();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void zombiesDead();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
