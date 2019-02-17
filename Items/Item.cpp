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

void Item::setDummyItem(string desc, string name)
{
	this->description = desc;
	this->name = name;
	this->type = "Dummy";
	this->attack= 0;
	this->defense = 0;
	this->healthBoost = 0;
}

void Item::useItem()
{
	//undefined
}

void Item::dropItem()
{
	cout << "You cannot drop this item." << endl;
}

void Item::throwItem()
{
	cout << "You cannot throw this item." << endl;
}

void Item::pushItem()
{
	cout << "You cannot push this item." << endl;
}

void Item::readItem()
{
	cout << "You cannot read this item." << endl;
}

void Item::wearItem()
{
	cout << "You cannot wear this item." << endl;
}

void Item::eatItem()
{
	cout << "You cannot eat this item." << endl;
}

void Item::cutItem()
{
	cout << "You cannot cut this item." << endl;
}
