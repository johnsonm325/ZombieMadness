#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <vector>
#include "Action.h"
using std::vector;
using std::string;
using std::cout;
using std::endl;

class Item
{
protected:
	string type;		//Weapon, etc
	string description;	//Object descriptoin
	string name;		//Specific name of object, ex: "Baseball Bat", used in inventory listing
	vector<string> actions;
	int attack;
	int defense;
	int healthBoost;
	int size;
	bool isRemovable = true;

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
	void setFeature();
	bool isMovable();

	// virtual action methods
	virtual void useItem();
	virtual void throwItem();
	virtual void pushItem();
	virtual void readItem();
	virtual void wearItem();
	virtual void eatItem();
	virtual void cutItem();
	virtual void attackItem();
	virtual void blockItem();
	virtual void openItem();

	//action setters
	void setAction(string, Action);
};

#endif
