#ifndef JERSEY_H
#define JERSEY_H
#include "Item.h"

class Jersey : public Item
{
public:
	Jersey();
	void useItem();
	void setLocation(string);
};

#endif