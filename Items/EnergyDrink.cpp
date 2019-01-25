#include "EnergyDrink.h"

EnergyDrink::EnergyDrink(int level) : Object()
{
	this->level = level;
}

void EnergyDrink::useItem()
{
	//to be determined
}

void EnergyDrink::setLocation(string l)
{
	this->location = l;
}
