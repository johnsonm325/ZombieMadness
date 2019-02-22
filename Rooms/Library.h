#ifndef LIBRARY_H
#define LIBRARY_H

#include "Space.h"
#include "FrontLobby.h"
#include "../Items/Item.h"

class Library : public Space
{
private:
	string action;		//string action typed in by the user
	FrontLobby *fl;
	Item *ladder;

public:
	Library();
	~Library();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void useLadder();
};
#endif
