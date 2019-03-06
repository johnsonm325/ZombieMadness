#ifndef MATH_H
#define MATH_H

#include "Space.h"
#include "../Items/FirstAid.h"

class Math : public Space
{
private:
	string action;		//string action typed in by the user
	bool appleEaten = false;
	Item *calculator;
	Item *apple;

public:
	Math();
	~Math();
	void printIntro();
	void eatApple();
	bool getAppleEaten();
};
#endif
