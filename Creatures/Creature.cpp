#include "Creature.h"
using std::cout;
using std::endl;

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


int Creature::getHealth()
{
	return health;
}

void Creature::setHealth(int newHealth)
{
	this->health =  newHealth;
}

void Creature::takeDamage(int damage)
{
	this->health -= damage;

	if (this->health <= 0)
	{
		this->isDead = true;
		this->health = 0;
		cout << "Zombie killed!" << endl;
	}

	else
	{
		cout << "Zombie's health now at " << this->health << endl;
	}
	
}