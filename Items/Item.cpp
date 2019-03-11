#include "Item.h"

Item::Item()
{
	actions = vector<string> (10);
	setAction("# You cannot use this item.", Use);
	setAction("# You cannot throw this item.", Throw);
	setAction("# You cannot push this item.", Push);
	setAction("# You cannot read this item.", Read);
	setAction("# You cannot wear this item.", Wear);
	setAction("# You cannot eat this item.", Eat);
	setAction("# You cannot cut with this item.", Cut);
	setAction("# You cannot attack with this item.", Attack);
	setAction("# You cannot block with this item.", Block);
	setAction("# You cannot open with this item.", Open);

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
	this->removable = false;
}

bool Item::isMovable(){
	return removable;
}

void Item::useItem()
{
	cout << KRED << actions[Use] << RESET << endl;
}

void Item::throwItem()
{
	cout << KRED << actions[Throw] << RESET << endl;
}

void Item::pushItem()
{
	cout << KRED << actions[Push] << RESET << endl;
}

void Item::readItem()
{
	cout << KRED << actions[Read] << RESET << endl;
}

void Item::wearItem()
{
	cout << KRED << actions[Wear] << RESET << endl;
}

void Item::eatItem()
{
	cout << KRED << actions[Eat] << RESET << endl;
}

void Item::cutItem()
{
	cout << KRED << actions[Cut] << RESET << endl;
}

void Item::attackItem()
{
	cout << KRED << actions[Attack] << RESET << endl;
}

void Item::blockItem()
{
	cout << KRED << actions[Block] << RESET << endl;
}

void Item::openItem()
{
	cout << KRED << actions[Open] << RESET << endl;
}

//Action setter
void Item::setAction(string text, Action type)
{
	this->actions[type] = text;
}
