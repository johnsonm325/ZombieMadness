#ifndef CHEMISTRY_H
#define CHEMISTRY_H

#include "Space.h"

class Chemistry : public Space
{
private:
	string action;		//string action typed in by the user
	bool holeVisible = false;
	Item *beakers;
	Item *cabinet;
	Item *ladder = NULL;

public:
	Chemistry();
	~Chemistry();
	void printIntro();
	void inspectCabinet();
	void moveCabinet();
	bool getHoleVisible();
	void setHoleVisible(bool);
};
#endif
