#ifndef PRINCIPALSOFFICE_H
#define PRINCIPALSOFFICE_H

#include "Space.h"
#include "../Items/FireExtinguisher.h"
#include "../Items/Key.h"

class PrincipalsOffice : public Space
{
private:
	string action;		//string action typed in by the user
	bool deadZombies = false;
	Item *desk, *key, *PAsystem, *fireExt;

public:
	PrincipalsOffice();
	~PrincipalsOffice();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void zombiesDead();
	
};
#endif
