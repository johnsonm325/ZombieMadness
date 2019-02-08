#ifndef LIBRARY_H
#define LIBRARY_H

#include "Space.h"

class Library : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;

public:
	Library();
	void printIntro();
	int menu();
	void inspectToilet();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
