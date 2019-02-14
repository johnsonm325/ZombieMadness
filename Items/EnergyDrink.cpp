#include "EnergyDrink.h"
using std::to_string;

EnergyDrink::EnergyDrink(int level) : Item()
{
	this->level = level;
	setName(level);
	string desc = "Time to hype up with this energy drink! ";
	this->type = "Supply";
	
	if (level == 1) {
		this->description = desc + "You found a level 1 drink, meaning your health will increase by 50% when used.";
		// this->healthBoost = half of remaining health
		this->size = 1;
	} else {
		this->description = desc + "You found a level 2 drink, meaning your health will increase by 75% when used.";
		// this->healthBoost = 3/4 of remaining health
		this->size = 2;
	}
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