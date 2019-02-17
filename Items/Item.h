#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Item
{
protected:
	string type;		//Weapon, etc
	string description;	//Object descriptoin
	string name;		//Specific name of object, ex: "Baseball Bat", used in inventory listing
	int attack;
	int defense;
	int healthBoost;
	int size;

public:
	Item();
	virtual ~Item();
	string getType();
	string getDesc();
	string getName();
	int getAttack();
	int getDefense();
	int getHealthBoost();
	int getSize();
	void setDummyItem(string, string);

	// virtual action methods
	virtual void useItem();
	virtual void dropItem();
	virtual void throwItem();
	virtual void pushItem();
	virtual void readItem();
	virtual void wearItem();
	virtual void eatItem();
	virtual void cutItem();
};

#endif
