#ifndef SWORD_H
#define SWORD_H
#include "Object.h"

class Sword : public Object
{
public:
	Sword();
	void useItem();
	void setLocation(string);
};

#endif