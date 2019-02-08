#ifndef GUN_H
#define GUN_H

#include "Item.h"

class Gun : public Item
{
public:
	Gun();
	void useItem();
	void setLocation(string);
};
#endif