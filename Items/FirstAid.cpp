#include "FirstAid.h"

FirstAid::FirstAid() : Object()
{
	this->healthBoost = 10;
}

void FirstAid::useItem()
{
	// to be determined
}

void FirstAid::setLocation(string l)
{
	this->location = l;
}
