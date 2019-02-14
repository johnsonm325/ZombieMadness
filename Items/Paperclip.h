#ifndef PAPERCLIP_H
#define PAPERCLIP_H

#include "Item.h"

class Paperclip : public Item
{
public:
	Paperclip();
	void useItem();
	bool canPickLock();
	void pickLock();
};

#endif
