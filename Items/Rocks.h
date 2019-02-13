#ifndef ROCKS_H
#define ROCKS_H

#include "Item.h"

class Rocks : public Item
{
private:
	int count;

public:
	Rocks();
	void decrementRocks();
	void distract();
	void setLocation(string);
	void useItem();
};

#endif
