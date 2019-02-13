#ifndef INFIRMARY_H
#define INFIRMARY_H

#include "Space.h"
#include "../Items/BiteCure.h"

class Infirmary : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;

public:
	Infirmary();
	void printIntro();
	int menu();
	void inspectToilet();
	void firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
