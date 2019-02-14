#include "BiteCure.h"

BiteCure::BiteCure() : Item()
{
	this->name = "Bite Cure";
	this->healthBoost = 100; // whatever full health is determined to be
	this->description = "You won't be a zombie's buffet with this item! The bit cure restores your health fully, use it wisely!";
	this->type = "Supply";
	this->size = 3;
}

void BiteCure::useItem()
{
	
}