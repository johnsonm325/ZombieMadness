#ifndef KNIFE_H
#define KNIFE_H
#include "Object.h"

class Knife : public Object
{
public:
	Knife();
	void useItem();
	void setLocation(string);
};

#endif
