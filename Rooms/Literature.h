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
	Item *note = NULL;

public:
	Literature();
	~Literature();
	void printIntro();
	void inspectDesk();
	bool getNoteVisible();
	void setNoteVisible(bool visible);
};
#endif
