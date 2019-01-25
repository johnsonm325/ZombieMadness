#ifndef KEY_H
#define KEY_H

#include "Object.h"

class Key : public Object
{
public:
	Key();
	bool canUnlock();
	void unlock();
	void setLocation(string);
};

#endif
