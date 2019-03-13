#include "SteelLid.h"

SteelLid::SteelLid() : Item()
{
	this->description = "# Throwing it back to the olden days. Use this steel trashcan lid as a blocking mechanism.";
	this->type = "Defense";
	this->name = "Steel Lid";
	this->attack = 0;
	this->defense = 4;
	this->size = 2;
}

void SteelLid::blockItem()
{
	cout << KGRN "# Ah, a nice sturdy, smelly steel lid to block with! You now have some\n# defense points to reduce damage taken." RESET << endl;
}
