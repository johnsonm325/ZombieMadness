#ifndef GYMNASIUMFLOOR1_H
#define GYMNASIUMFLOOR1_H

#include "Space.h"
#include "../Items/Jersey.h"

class GymnasiumFloor1 : public Space
{
private:
	string action;		//string action typed in by the user
	Item *basketball;
	Item *bleachers;

public:
	GymnasiumFloor1();
	~GymnasiumFloor1();
	void printIntro();
};
#endif
