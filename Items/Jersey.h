#ifndef JERSEY_H
#define JERSEY_H
#include "Object.h"

class Jersey : public Object
{
public:
	Jersey();
	void useItem();
	void setLocation(string);
};

#endif