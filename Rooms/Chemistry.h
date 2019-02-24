#ifndef CHEMISTRY_H
#define CHEMISTRY_H

#include "Space.h"

class Chemistry : public Space
{
private:
	string action;		//string action typed in by the user
	bool deadZombies = false,
	     holeVisible = false;
	Item *beakers;
	Item *cabinet;
	Item *ladder;

public:
	Chemistry();
	~Chemistry();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void inspectCabinet();
	void moveCabinet();
	bool getHoleVisible();
	void zombiesDead();

};
#endif
