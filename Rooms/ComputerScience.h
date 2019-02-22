#ifndef COMPUTERSCIENCE_H
#define COMPUTERSCIENCE_H

#include "Space.h"
#include "../Items/Sword.h"

class ComputerScience : public Space
{
private:
	string action;		//string action typed in by the user

public:
	ComputerScience();
	~ComputerScience();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);

};
#endif
