#ifndef BIOLOGY_H
#define BIOLOGY_H

#include "Space.h"
#include "../Items/Rocks.h"

class Biology : public Space
{
private:
	string action;		//string action typed in by the user
	bool plantsEaten = false;
	Item *dissectedAnimal;
	Item *plants;

public:
	Biology();
	~Biology();
	void printIntro();
	bool getPlantsEaten();
	void setPlantsEaten(bool);
};
#endif
