#ifndef PAPERCLIP_H
#define PAPERCLIP_H

#include "Object.h"

class Paperclip : public Object
{
public:
	Paperclip();
	bool canPickLock();
	void pickLock();
	void setLocation(string);
};

#endif
