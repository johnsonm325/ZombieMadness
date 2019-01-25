#ifndef STEEL_LID_H
#define STEEL_LID_H
#include "Object.h"

class SteelLid : public Object
{
public:
	SteelLid();
	void useItem();
	void setLocation(string);
};

#endif