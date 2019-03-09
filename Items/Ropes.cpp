#include "Ropes.h"

Ropes::Ropes() : Item()
{
	string description = "# Ropes appear to be strung across the rafters, holding up many\n# of the spotlights and scoreboards.";
	string name = "Ropes";
	setDummyItem(description, name);
	string text = "# As you cut the ropes, the tension is released and all of the lights and\n# scoreboards go crashing to the lower level of the gym.";
	setAction(text, Cut);	
	this->removable = true;
}

