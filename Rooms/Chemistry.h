#ifndef CHEMISTRY_H
#define CHEMISTRY_H

#include "Space.h"

class Chemistry : public Space
{
private:
	string action;		//string action typed in by the user
	bool deadZombies = false;

public:
	Chemistry();
	~Chemistry();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void zombiesDead();

};
#endif
