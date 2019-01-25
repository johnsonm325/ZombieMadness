#include "BiteCure.h"

BiteCure::BiteCure() : Object()
{
	this->healthBoost = 100; // whatever full health is determined to be
}

void BiteCure::fullHealth()
{
	// set players health to full health
}

void BiteCure::setLocation(string l)
{
	this->location = l;
}
