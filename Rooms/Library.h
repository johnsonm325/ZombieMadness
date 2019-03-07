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
	Item *book;

public:
	Library();
	~Library();
	void printIntro();
	void useLadder();
};
#endif
