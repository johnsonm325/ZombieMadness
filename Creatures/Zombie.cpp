#include "Zombie.h"

Zombie::Zombie(bool boss) : Creature("Zombie")
{
	this->isBoss = boss;

	if (!boss)
	{
		this->description = "Your average zombie, but never doubt their capabilities!";
		this->name = "Regular Zombie";
		this->health = 0;
	}
	
	else
	{
		this->description = "THE KING ZOMBIE! You have to fight real smart to beat this guy!";
		this->name = "King Zombie";
		this->attack = 5;
		this->defense = 5;
		this->health = 100;
	}
}

Zombie::~Zombie()
{
	
}

void Zombie::attackEnemy(Creature* enemy) 
{
	if (this->name == "Regular Zombie")
		return;

	enemy->takeDamage(this->attack);
}

bool Zombie::getBossStatus()
{
	return isBoss;
}