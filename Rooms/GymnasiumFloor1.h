#ifndef GYMNASIUMFLOOR1_H
#define GYMNASIUMFLOOR1_H

#include "Space.h"

class GymnasiumFloor1 : public Space
{
private:
	string action;		//string action typed in by the user
	bool deadZombies = false;
	Item *basketball;
	Item *bleachers;

public:
	GymnasiumFloor1();
	~GymnasiumFloor1();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	void ropesCut();
	void zombiesDead();

};
#endif
