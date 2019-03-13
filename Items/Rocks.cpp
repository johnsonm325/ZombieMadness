#include "Rocks.h"

Rocks::Rocks() : Item()
{
	this->name = "Rocks";
	this->description = "# Everyone needs a distraction! Throw these Rocks to distract a zombie to buy you some time.";
	this->type = "Weapon";
	this->size = 3;
	this->attack = 20;
}

void Rocks::throwItem()
{
	cout << KGRN "# Just like when you were a kid, throwing rocks!" RESET << endl;
}
