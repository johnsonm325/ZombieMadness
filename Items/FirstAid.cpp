#include "FirstAid.h"

FirstAid::FirstAid() : Item()
{
	this->name = "First Aid";
	this->healthBoost = 10;
	this->description = "# Bandages can go a long way! Use this First Aid item to give yourself a small health boost.";
	this->type = "Supply";
	this->size = 1;
}
