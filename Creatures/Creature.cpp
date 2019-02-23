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

//Space* Creature::getLocation()
//{
//	return location;
//}

string Creature::getName()
{
	return name;
}
//void Creature::setLocation(Space* loc) {
//	this->location = loc;
//}

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
	return isDead == false;
}

void Creature::setName(string name)
{
	this->name = name;
}

void Creature::setHealth(int newHealth)
{
	this->health =  newHealth;
}

void Creature::takeDamage(int damage)
{
	this->health -= damage;
	string type = this->type;

	if (this->health <= 0)
	{
		this->isDead = true;
		this->health = 0;
		
		if (type == "Player")
			cout << "You were killed!" << endl;

		else
			cout << "Zombie killed!" << endl;
		
		
	}

	else
	{
		if (type == "Player")
			cout << "Your health is now at " << this->health << endl;

		else
			cout << "Zombie's health is now at " << this->health << endl;
		
	}
	
}

void Creature::attackEnemy(string item){
	
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
	isDead = true;
}