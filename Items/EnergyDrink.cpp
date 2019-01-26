#include "EnergyDrink.h"

EnergyDrink::EnergyDrink(int level) : Object()
{
	this->level = level;
	setName(level);
}

void EnergyDrink::useItem()
{
	//to be determined
}

void EnergyDrink::setName(int level) {
	char lvStr[8];
	snprintf(lvStr, sizeof(lvStr), "%d", level);
	this->name = "Energy Drink LV";
	this->name += lvStr;
}

void EnergyDrink::setLocation(string l)
{
	this->location = l;
}
