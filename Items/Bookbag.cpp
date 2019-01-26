#include "Bookbag.h"

Bookbag::Bookbag() : Object()
{
	//undefined
	this->name = "Bookbag";
}

void Bookbag::increaseSize()
{
	//increase player inventory size by number TBD
}

void Bookbag::setLocation(string l)
{
	this->location = l;
}
