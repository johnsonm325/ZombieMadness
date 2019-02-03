#ifndef PRINCIPALSOFFICE_H
#define PRINCIPALSOFFICE_H

#include "Space.h"

class PrincipalsOffice : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false,
	     deadZombie = false;

public:
	PrincipalsOffice();
	int menu(vector<string>*);
	bool zombieDead();
	void inspectToilet();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
