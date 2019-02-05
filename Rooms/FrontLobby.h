#ifndef FRONTLOBBY_H
#define FRONTLOBBY_H

#include "Space.h"

class FrontLobby : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;

public:
	FrontLobby();
	void printIntro();
	int menu(vector<string>*);
	void inspectToilet();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
