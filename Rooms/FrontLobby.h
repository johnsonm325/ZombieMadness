#ifndef FRONTLOBBY_H
#define FRONTLOBBY_H

#include "Space.h"

class FrontLobby : public Space
{
private:
	string action;		//string action typed in by the user
	bool deadZombies = false;
	Item *bench;
	Item *displayCase;

public:
	FrontLobby();
	~FrontLobby();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void zombiesDead();
};
#endif
