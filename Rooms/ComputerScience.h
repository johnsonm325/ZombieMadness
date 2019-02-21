#ifndef COMPUTERSCIENCE_H
#define COMPUTERSCIENCE_H

#include "Space.h"
#include "../Items/Sword.h"

class ComputerScience : public Space
{
private:
	string action;		//string action typed in by the user
	bool goneColt = false;

public:
	ComputerScience();
	void printIntro();
	int menu(vector<string>);
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
