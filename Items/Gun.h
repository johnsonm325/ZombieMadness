#ifndef GUN_H
#define GUN_H

#include "Object.h"

class Gun : public Object
{
public:
	Gun();
	void useItem();
	void setLocation(string);
};
#endif