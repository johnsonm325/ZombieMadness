#ifndef LITERATURE_H
#define LITERATURE_H

#include "Space.h"

class Literature : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;

public:
	Literature();
	void printIntro();
	int menu();
	void inspectToilet();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
