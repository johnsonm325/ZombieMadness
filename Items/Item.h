#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

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
	virtual void useItem();
	void setDummyItem(string, string);
};

#endif
