#ifndef ENERGY_DRINK_H
#define ENERGY_DRINK_H

#include "Item.h"

class EnergyDrink : public Item
{
private:
	int level;

public:
	EnergyDrink(int);
	void useItem();
	void setLocation(string);
	void setName(int level);
};

#endif
