#ifndef LOCKERROOM_H
#define LOCKERROOM_H

#include "Space.h"
#include "../Items/BaseballBat.h"
#include "../Items/SteelLid.h"

class LockerRoom : public Space
{
private:
	string action;		//string action typed in by the user

public:
	LockerRoom();
	~LockerRoom();
	void printIntro();
	void printExitDesc();
	int menu(vector<string>);
	
};
#endif
