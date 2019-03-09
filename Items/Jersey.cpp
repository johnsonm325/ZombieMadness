#include "Jersey.h"

Jersey::Jersey() : Item()
{
	this->description = "Ever imagine you'd be an All-Start athlete?  Well now you can with this Jersey!  Your defense increases while wearing this.";
	this->type = "Defense";
	this->name = "Jersey";
	this->attack = 0;
	this->defense = 6;
	this->size = 2;
}

void Jersey::wearItem()
{
	cout << KGRN "# Hey, looking pretty snazy with that jersey! You now have some defense points to reduce damage taken." RESET << endl;
}