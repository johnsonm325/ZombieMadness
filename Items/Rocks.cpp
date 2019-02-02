#include "Rocks.h"

Rocks::Rocks() : Object()
{
	this->count = 10;
	this->name = "Rocks";
	this->description = "Everyone needs a distraction! Throw these Rocks to distract a zombie to buy you some time.";
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