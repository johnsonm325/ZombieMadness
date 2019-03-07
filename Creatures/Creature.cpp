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

string Creature::getName()
{
	return name;
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

bool Creature::isAlive(){
	return alive;
}

void Creature::setAlive(bool alive){
	this->alive = alive;
}

void Creature::setName(string name)
{
	this->name = name;
}

void Creature::setHealth(int newHealth)
{
	this->health = newHealth;
}

void Creature::gainHealth(int boost)
{
	this->health += boost;

	if (this->health > 100)
		this->health = 100;
}

void Creature::takeDamage(int damage)
{
	this->health -= damage;
	string type = this->type;

	if (this->health <= 0)
	{
		this->alive = false;
		this->health = 0;
		
		if (type == "Player")
			cout << "# You were killed!" << endl;

		else
			cout << "# Zombie killed!" << endl;
			
	}

	else
	{
		if (type == "Player")
			cout << "# Your health is now at " << this->health << endl;

		else
			cout << "# Zombie's health is now at " << this->health << endl;
		
	}	
}

void Creature::setDefense(int d)
{
	this->defense += d;

	if (this->defense > 10)	// 10 as the only 2 defense items add up to 10 defense
		this->defense = 10;
}

void Creature::blockAttack()
{
	//TBD
}

void Creature::talkToCreature()
{
	cout << "You cannot talk to this creature." << endl;
}

void Creature::die(){
	alive = false;
}

void Creature::printStats(){
	cout << " === " << this->type << "'s Stats ===" << endl;
	cout << " Health: " << getHealth() << " HP" << endl;
	cout << " Defense: " << getDefense() << " pts" << endl;
	cout << " Attack: " << getAttack() << " pts" << endl;
	cout << " Alive?: " << isAlive() << endl;
}

