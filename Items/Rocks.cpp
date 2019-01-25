#include "Rocks.h"

Rocks::Rocks() : Object()
{
	this->count = 10;
}

void Rocks::decrementRocks()
{
	this->count--;
}

void Rocks::distract()
{
	//TBD
}

void Rocks::setLocation(string l)
{
	this->location = l;
}