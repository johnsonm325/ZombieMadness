#ifndef MENSBATHROOM_H
#define MENSBATHROOM_H

#include "Space.h"

class MensBathroom : public Space
{
private:
	string action;		//string action typed in by the user
	bool goneColt = false,
	     holeVisible = false;
	Item *toilet, *hole;

public:
	MensBathroom();
	void printIntro();
	int menu(vector<string>);
	void inspectToilet();
	bool getHoleVisible();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
