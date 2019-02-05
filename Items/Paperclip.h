#ifndef PAPERCLIP_H
#define PAPERCLIP_H

#include "Object.h"

class Paperclip : public Object
{
public:
	Paperclip();
	void useItem();
	bool canPickLock();
	void pickLock();
	void setLocation(string);	
};

#endif
