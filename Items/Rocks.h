#ifndef ROCKS_H
#define ROCKS_H

#include "Object.h"

class Rocks : public Object
{
private:
	int count;

public:
	Rocks();
	void decrementRocks();
	void distract();
	void setLocation(string);
};

#endif
