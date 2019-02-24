#ifndef FRONTOFFICE_H
#define FRONTOFFICE_H

#include "Space.h"
#include "PrincipalsOffice.h"
#include "../Items/Item.h"

class FrontOffice : public Space
{
private:
	string action;		//string action typed in by the user
	bool goneColt = false;
	Item *paSystem;
	Item *detentionList;

public:
	FrontOffice();
	~FrontOffice();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void usePA();
};
#endif
