#ifndef MATH_H
#define MATH_H

#include "Space.h"

class Math : public Space
{
private:
	string action;		//string action typed in by the user

public:
	Math();
	~Math();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	
};
#endif
