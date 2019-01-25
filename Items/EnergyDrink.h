#ifndef ENERGY_DRINK_H
#define ENERGY_DRINK_H

#include "Object.h"

class EnergyDrink : public Object
{
private:
	int level;

public:
	EnergyDrink(int);
	void useItem();
	void setLocation(string);
};

#endif
