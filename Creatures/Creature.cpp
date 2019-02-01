#include "Creature.h"

Creature::Creature()
{
	//will be defined in sub classes
}
Creature::Creature(string type)
{
	this->type = type;
}

Creature::~Creature()
{
	//undefined
}

string Creature::getType()
{
	return type;
}

string Creature::getDesc()
{
	return description;
}

Space* Creature::getLocation()
{
	return location;
}

string Creature::getName()
{
	return name;
}
void Creature::setLocation(Space* loc) {
	this->location = loc;
}

int Creature::getAttack()
{
	return attack;
}

int Creature::getDefense()
{
	return defense;
}


int Creature::getHealthBoost()
{
	return healthBoost;
}

void Creature::pickUpItem(Object* item)	//Pick up item from room
{
	if (item == NULL) { return; }

	//Check if item is removable from room first
	creatureInventory->addObject(item);
	location->dropItem(item);

}
void Creature::dropItem(Object* item) {	//Drop item from creature
	if (item == NULL) { return; }

	location->pickUpItem(item);
	creatureInventory->removeObject(item);
}

Inventory* Creature::getInventory() {
	return creatureInventory;
}