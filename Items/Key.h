#ifndef KEY_H
#define KEY_H

#include "Item.h"

class Key : public Item
{
public:
	Key();
	bool canUnlock();
	void unlock();
	void setLocation(string);
	void useItem();
};

#endif
