#ifndef GYMNASIUMFLOOR2_H
#define GYMNASIUMFLOOR2_H

#include "Space.h"
#include "GymnasiumFloor1.h"
#include "../Items/Item.h"
#include "../Items/Gun.h"

class GymnasiumFloor2 : public Space
{
private:
	string action;		//string action typed in by the user
	GymnasiumFloor1 *gym1;
	Item *ropes;
	Item *lights;

public:
	GymnasiumFloor2();
	~GymnasiumFloor2();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void cutRopes();

};
#endif
