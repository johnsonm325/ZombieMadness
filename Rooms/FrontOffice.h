#ifndef FRONTOFFICE_H
#define FRONTOFFICE_H

#include "Space.h"
#include "PrincipalsOffice.h"
#include "../Items/Item.h"

class FrontOffice : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;
	PrincipalsOffice *prin;
	Item *paSystem;

public:
	FrontOffice();
	void printIntro();
	int menu();
	void usePA();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
