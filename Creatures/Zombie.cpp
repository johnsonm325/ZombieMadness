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

	int damage = rand() % 31 + 10;
	int total = damage - enemy->getDefense();

	if (total <= 0)
		total = 0;

	enemy->takeDamage(total);
}

bool Zombie::getBossStatus()
{
	return isBoss;
}