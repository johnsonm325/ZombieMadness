#include "Gun.h"

Gun::Gun() : Item()
{
	this->description = "Now this is some serious power.  This high-leveled weapon will cause some serious damage.";
	this->type = "Weapon";
	this->name = "Gun";
	this->attack = 35;
	this->defense = 0;
	this->size = 4;
}

void Gun::attackItem()
{
	cout << "# That's some serious fiyah powah, attacking with the gun!" << endl;
}