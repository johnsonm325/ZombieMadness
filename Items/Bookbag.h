#ifndef BOOKBAG_H
#define BOOKBAG_H

#include "Object.h"

class Bookbag : public Object
{
public:
	Bookbag();
	void increaseSize();
	void setLocation(string);
};

#endif