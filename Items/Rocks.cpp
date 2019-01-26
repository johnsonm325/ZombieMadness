#include "Rocks.h"

Rocks::Rocks() : Object()
{
	this->count = 10;
	this->name = "Rocks";
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