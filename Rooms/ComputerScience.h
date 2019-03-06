#ifndef COMPUTERSCIENCE_H
#define COMPUTERSCIENCE_H

#include "Space.h"
#include "../Items/Sword.h"

class ComputerScience : public Space
{
private:
	string action;		//string action typed in by the user
	Item *computer;
	Item * whiteboard;

public:
	ComputerScience();
	~ComputerScience();
	void printIntro();
};
#endif
