#ifndef BASEBALL_BAT_H
#define BASEBALL_BAT_H
#include "Object.h"

class BaseballBat : public Object
{
public:
	BaseballBat();
	void useItem();
	void setLocation(string);
};

#endif