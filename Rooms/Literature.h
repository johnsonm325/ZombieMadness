#ifndef LITERATURE_H
#define LITERATURE_H

#include "Space.h"

class Literature : public Space
{
private:
	string action;		//string action typed in by the user
	bool noteVisible = false;
	Item *chalkboard;
	Item *desk;
	Item *note;

public:
	Literature();
	~Literature();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void inspectDesk();
	bool getNoteVisible();

};
#endif
