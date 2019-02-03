#ifndef CREATURE_H
#define CREATURE_H

#include "../Items/Inventory.h"
#include "../Rooms/Space.h"

#include <string>
using std::string;

class Creature
{
protected:
	string type;		//Zombie, player, type of creature
	string description;	//Creature description
	Space* location;	//Which room creature is in
	string name;		//Specific name of creature, if necessary
	int attack;
	int defense;
	int health;
	bool isDead;

public:
	Creature();
	Creature(string type);
	virtual ~Creature();
	string getType();
	string getDesc();
	Space* getLocation();
	string getName();
	void setLocation(Space* location);
	int getAttack();
	int getDefense();
	int getHealth();
	void setHealth(int);
	// virtual void useItem(Object* item) = 0;
	virtual void attackEnemy(Creature* enemy) = 0;
	virtual void takeDamage(int);
};

#endif