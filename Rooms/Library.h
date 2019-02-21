#ifndef LIBRARY_H
#define LIBRARY_H

#include "Space.h"
#include "FrontLobby.h"
#include "../Items/Item.h"

class Library : public Space
{
private:
	string action;		//string action typed in by the user
	bool goneColt = false;
	FrontLobby *fl;
	Item *ladder;

public:
	Library();
	void printIntro();
	int menu(vector<string>);
	void useLadder();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
