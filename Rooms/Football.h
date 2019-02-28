#ifndef FOOTBALL_H
#define FOOTBALL_H

#include "Space.h"

class Football : public Space
{
private:
	string action;		//string action typed in by the user
	Item *football;
	Item *pompom;

public:
	Football();
	~Football();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
};
#endif
