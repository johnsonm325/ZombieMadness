#ifndef BITE_CURE_H
#define BITE_CURE_H

#include "Item.h"
#include "../Creatures/Player.h"

class BiteCure : public Item
{
public:
	BiteCure();
	void useItem(Player*);
};

#endif
