#ifndef BASEBALL_BAT_H
#define BASEBALL_BAT_H
#include "Item.h"

class BaseballBat : public Item
{
public:
	BaseballBat();
	void useItem();
	void damageZombie(Creature*);
	void setLocation(string);
};

#endif