#ifndef BITE_CURE_H
#define BITE_CURE_H

#include "Item.h"

class BiteCure : public Item
{
public:
	BiteCure();
	void fullHealth(Creature*);
	void setLocation(string);
	void useItem();
};

#endif
