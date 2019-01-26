#include "Object.h"

Object::Object()
{
	//will be defined in sub classes
}

Object::~Object()
{
	//undefined
}

string Object::getType()
{
	return type;
}

string Object::getDesc()
{
	return description;
}

string Object::getLocation()
{
	return location;
}

string Object::getName()
{
	return name;
}

int Object::getAttack()
{
	return attack;
}

int Object::getDefense()
{
	return defense;
}


int Object::getHealthBoost()
{
	return healthBoost;
}