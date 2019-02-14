#include "Rocks.h"

Rocks::Rocks() : Item()
{
	this->count = 10;
	this->name = "Rocks";
	this->description = "Everyone needs a distraction! Throw these Rocks to distract a zombie to buy you some time.";
	this->type = "Room Object";
	this->size = 2;
}

void Rocks::decrementRocks()
{
	this->count--;
}

void Rocks::distract()
{
	//TBD
}

void Rocks::useItem()
{
	// undefined
}