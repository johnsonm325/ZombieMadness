#ifndef FIRE_EXTINGUISHER_H
#define FIRE_EXTINGUISHER_H
#include "Object.h"

class FireExtinguisher : public Object
{
public:
	FireExtinguisher();
	void useItem();
	void setLocation(string);
};

#endif