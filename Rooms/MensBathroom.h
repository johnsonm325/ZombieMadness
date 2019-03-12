#ifndef MENSBATHROOM_H
#define MENSBATHROOM_H

#include "Space.h"

class MensBathroom : public Space
{
private:
	string action;		//string action typed in by the user
	bool holeVisible = false;
	Item *toilet,
	     *hole = NULL;

public:
	MensBathroom();
	~MensBathroom();
	void printIntro();
	void inspectToilet();
	bool getHoleVisible();
	void setHoleVisible(bool);
};
#endif
