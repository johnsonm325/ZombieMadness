#ifndef FIRST_AID_H
#define FIRST_AID_H

#include "Object.h"

class FirstAid : public Object
{
public:
	FirstAid();
	void useItem();
	void setLocation(string);
};

#endif
