#ifndef MAP_H
#define MAP_H

#include "Object.h"

class Map : public Object
{
public:
	Map();
	void useItem();
	void setLocation(string);
};

#endif
