#include "Item.h"

Item::Item()
{
	actions = vector<string> (10);
	setAction("You cannot use this item.", Use);
	setAction("You cannot throw this item.", Throw);
	setAction("You cannot push this item.", Push);
	setAction("You cannot read this item.", Read);
	setAction("You cannot wear this item.", Wear);
	setAction("You cannot eat this item.", Eat);
	setAction("You cannot cut with this item.", Cut);
	setAction("You cannot attack with this item.", Attack);
	setAction("You cannot block with this item.", Block);
	setAction("You cannot open anything this item.", Open);

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
void Item::setFeature(){
	isRemovable = false;
}
bool Item::isMovable(){
	return isRemovable;
}

void Item::useItem()
{
	cout << actions[Use] << endl;
}

void Item::throwItem()
{
	cout << actions[Throw] << endl;
}

void Item::pushItem()
{
	cout << actions[Push] << endl;
}

void Item::readItem()
{
	cout << actions[Read] << endl;
}

void Item::wearItem()
{
	cout << actions[Wear] << endl;
}

void Item::eatItem()
{
	cout << actions[Eat] << endl;
}

void Item::cutItem()
{
	cout << actions[Cut] << endl;
}

void Item::attackItem()
{
	cout << actions[Attack] << endl;
}

void Item::blockItem()
{
	cout << actions[Block] << endl;
}

void Item::openItem()
{
	cout << actions[Open] << endl;
}

//Action setter
void Item::setAction(string text, Action type)
{
	this->actions[type] = text;
}