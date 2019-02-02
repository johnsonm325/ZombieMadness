#include "BiteCure.h"

BiteCure::BiteCure() : Object()
{
	this->name = "Bite Cure";
	this->healthBoost = 100; // whatever full health is determined to be
	this->description = "You're won't be a zombie's buffet with this item! The bit cure restores your health fully, use it wisely!";
	this->type = "Supply";
}

void BiteCure::fullHealth()
{
	// set players health to full health
}

void BiteCure::setLocation(string l)
{
	this->location = l;
}
