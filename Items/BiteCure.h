#ifndef BITE_CURE_H
#define BITE_CURE_H

#include "Object.h"

class BiteCure : public Object
{
public:
	BiteCure();
	void fullHealth(Creature*);
	void setLocation(string);
};

#endif
