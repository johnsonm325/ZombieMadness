#ifndef FIRE_EXTINGUISHER_H
#define FIRE_EXTINGUISHER_H
#include "Item.h"

class FireExtinguisher : public Item
{
public:
	FireExtinguisher();
	void useItem();
	void setLocation(string);
};

#endif