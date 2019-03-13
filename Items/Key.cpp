#include "Key.h"

Key::Key() : Item()
{
	//undefined
	this->name = "Key";
	this->description = "# Time to explore! This key will unlock various rooms, explore to find out which ones!";
	this->type = "Misc";
	this->size = 1;
}

void Key::useItem()
{
	// undefined
}
