#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

#include <string>
using std::string;

class Player: public Creature
{
public:
	Player();
	~Player();
	void useItem(Object* item);
	void attackEnemy(Creature* enemy);

};

#endif