#include "Jersey.h"

Jersey::Jersey() : Item()
{
	this->description = "Ever imagine you'd be an All-Start athlete?  Well now you can with this Jersey!  Your defense increases while wearing this.";
	this->type = "Weapon";
	this->name = "Jersey";
	this->attack = 0;
	this->defense = 6;
}

void Jersey::useItem()
{
	//to be determined
}

void Jersey::setLocation(string l)
{
	this->location = l;
}