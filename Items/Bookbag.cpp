#include "Bookbag.h"

Bookbag::Bookbag(PlayerInventory *bag) : Object()
{
	//undefined
	this->name = "Bookbag";
	this->description = "More items for you! This bookbag increases your inventory size, allowing you to hold more items.";
	this->inventory = bag;
}

void Bookbag::increaseSize()
{
	this->inventory->increaseSize();
}

void Bookbag::setLocation(string l)
{
	this->location = l;
}
