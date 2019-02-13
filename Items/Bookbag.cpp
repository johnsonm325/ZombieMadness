#include "Bookbag.h"

Bookbag::Bookbag(PlayerInventory *bag) : Item()
{
	//undefined
	this->name = "Bookbag";
	this->description = "More items for you! This bookbag increases your inventory size, allowing you to hold more items.";
	this->inventory = bag;
	this->type = "Room Object";
}

void Bookbag::increaseSize()
{
	this->inventory->increaseSize();
}

void Bookbag::setLocation(string l)
{
	this->location = l;
}

void Bookbag::useItem()
{
	
}
