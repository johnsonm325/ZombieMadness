#ifndef BIOLOGY_H
#define BIOLOGY_H

#include "Space.h"
#include "../Items/Rocks.h"

class Biology : public Space
{
private:
	string action;		//string action typed in by the user

public:
	Biology();
	~Biology();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);

};
#endif
