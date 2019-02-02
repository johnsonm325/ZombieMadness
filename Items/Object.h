#ifndef OBJECT_H
#define OBJECT_H

#include "../Creatures/Creature.h"
#include <string>
using std::string;

class Object
{
protected:
	string type;		//Weapon, etc
	string description;	//Object descriptoin
	string location;	
	string name;		//Specific name of object, ex: "Baseball Bat", used in inventory listing
	int attack;
	int defense;
	int healthBoost;
public:
	Object();
	virtual ~Object();
	string getType();
	string getDesc();
	string getLocation();
	string getName();
	//virtual void setLocation(string);
	int getAttack();
	int getDefense();
	int getHealthBoost();
	virtual void useItem();
	virtual void damageZombie(Creature*);
	void setDummyItem(string, string);
};

#endif