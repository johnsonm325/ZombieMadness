#include "Item.h"

Item::Item()
{
	//will be defined in sub classes
}

Item::~Item()
{
	//undefined
}

string Item::getType()
{
	return type;
}

string Item::getDesc()
{
	return description;
}


string Item::getName()
{
	return name;
}

int Item::getAttack()
{
	return attack;
}

int Item::getDefense()
{
	return defense;
}


int Item::getHealthBoost()
{
	return healthBoost;
}

int Item::getSize()
{
	return size;
}

void Item::useItem()
{
	//undefined
}

void Item::setDummyItem(string desc, string name)
{
	this->description = desc;
	this->name = name;
	this->attack= 0;
	this->defense = 0;
	this->healthBoost = 0;
}
