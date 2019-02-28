#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Creature.h"

#include <string>
using std::string;

class Zombie: public Creature
{
private:
	bool isBoss;
public:
	Zombie(bool);
	~Zombie();
	void attackEnemy(Creature* enemy);
	bool getBossStatus();
};

#endif
