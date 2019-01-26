#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using std::string;

class Object
{
protected:
	string type;
	string description;
	string location;
	int attack;
	int defense;
	int healthBoost;
public:
	Object();
	virtual ~Object();
	string getDesc();
	string getType();
	string getLocation();
	virtual void setLocation(string) = 0;
	int getAttack();
	int getDefense();
	int getHealthBoost();
	virtual void useItem() = 0;
};

#endif