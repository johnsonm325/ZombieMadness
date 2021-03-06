#ifndef PRINCIPALSOFFICE_H
#define PRINCIPALSOFFICE_H

#include "Space.h"
#include "../Items/FireExtinguisher.h"
#include "../Items/Key.h"

class PrincipalsOffice : public Space
{
private:
	string action;		//string action typed in by the user
	Item *desk, *key, *fireExt, *chair;

public:
	PrincipalsOffice();
	~PrincipalsOffice();
	void printIntro();
	void inspectDesk();
};
#endif
