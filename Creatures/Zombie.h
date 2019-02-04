#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Creature.h"

#include <string>
using std::string;

class Zombie: public Creature
{
private:
	int level;
public:
	Zombie(int level);
	~Zombie();
	void setLevel(int level);
	//void useItem(Object* item);
	void attackEnemy(Creature* enemy);

};

#endif
