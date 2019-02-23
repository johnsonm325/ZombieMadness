#ifndef INFIRMARY_H
#define INFIRMARY_H

#include "Space.h"
#include "../Items/BiteCure.h"

class Infirmary : public Space
{
private:
	string action;		//string action typed in by the user
	Item *bed;
	Item *nursesHat;

public:
	Infirmary();
	~Infirmary();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
};
#endif
