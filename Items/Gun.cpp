#include "Gun.h"

Gun::Gun() : Item()
{
	this->description = "# Now this is some serious power. This high-leveled weapon will cause\n# some serious damage.";
	this->type = "Weapon";
	this->name = "Gun";
	this->attack = 60;
	this->defense = 0;
	this->size = 4;
}

void Gun::attackItem()
{
	cout << KGRN "# That's some serious fiyah powah, attacking with the gun!" RESET << endl;
}
