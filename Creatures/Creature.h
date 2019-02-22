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
	//Space* location;	//Which room creature is in
	string name;		//Specific name of creature, if necessary
	int attack;
	int defense;
	int health;
	bool isDead;

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
	void creatureDead();

	//setters
	void setName(string);
	void setHealth(int);
	// virtual void useItem(Object* item) = 0;
	void attackEnemy(string item);	//Version that Player uses
	//virtual void attackEnemy(Creature*); = 0;	//original
	void takeDamage(int);
	void blockAttack();
	virtual void talkToCreature();
};

#endif