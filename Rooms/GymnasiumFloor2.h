#ifndef GYMNASIUMFLOOR2_H
#define GYMNASIUMFLOOR2_H

#include "Space.h"
#include "GymnasiumFloor1.h"
#include "../Items/Gun.h"
#include "../Items/Ropes.h"

class GymnasiumFloor2 : public Space
{
private:
	string action;		//string action typed in by the user
	GymnasiumFloor1 *gym1;
	Item *lights;

public:
	GymnasiumFloor2();
	~GymnasiumFloor2();
	void printIntro();
	void cutRopes();
};
#endif
