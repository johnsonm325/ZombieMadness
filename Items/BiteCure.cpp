#include "BiteCure.h"

BiteCure::BiteCure() : Item()
{
	this->name = "Bite Cure";
	this->healthBoost = 40; // whatever full health is determined to be
	this->description = "You won't be a zombie's buffet with this item! The bite cure gives you a big health increase!";
	this->type = "Supply";
	this->size = 3;
}