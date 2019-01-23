#include "Object.h"

Object::Object()
{
	//will be defined in sub classes
}

Object::~Object()
{
	//undefined
}

string Object::getDesc()
{
	return description;
}

string Object::getType()
{
	return type;
}

int Object::getAttack()
{
	return attack;
}

int Object::getDefense()
{
	return defense;
}

string Object::getLocation()
{
	return location;
}