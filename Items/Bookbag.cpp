#include "Bookbag.h"

Bookbag::Bookbag() : Item()
{
	string description = "# It's a bookbag. Should help me to carry a few more items.";
	string name = "Bookbag";
	setDummyItem(description, name);
	string text = "# You put on the bookbag and your carrying capacity is increased by 7.";
	setAction(text, Use);
	this->removable = true;
}

