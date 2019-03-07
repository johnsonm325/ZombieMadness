#ifndef CREATURE_H
#define CREATURE_H

//#include "../Rooms/Space.h"

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Creature
{
protected:
	string type;		//Zombie, player, type of creature
	string description;	//Creature description
	string name;		//Specific name of creature, if necessary
	int attack;
	int defense = 0;
	int health;
	bool alive = true;

public:
	Creature();
	Creature(string type);
	virtual ~Creature();
	//getters
	string getType();
	string getDesc();
	string getName();
	int getAttack();
	int getDefense();
	int getHealth();
	bool isAlive();
	void setAlive(bool alive);

	//setters
	void setName(string);
	void setHealth(int);
	void gainHealth(int);
	void setDefense(int);
	void takeDamage(int);
	void blockAttack();
	virtual void talkToCreature();
	void die();
	void printStats();
};

#endif