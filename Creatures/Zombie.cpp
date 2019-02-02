#include "Zombie.h"

Zombie::Zombie(int level) : Creature("Zombie")
{
	setLevel(level);
	
}

Zombie::~Zombie()
{
	
}

void Zombie::setLevel(int level) {
	this->level = level;

	switch (level) {
		case 1:
			this->attack = 3;
			this->defense = 4;
			this->health = 8;
			this->name = "Medium Zombie";
			break;
		case 2:
			this->attack = 6;
			this->defense = 8;
			this->health = 10;
			this->name = "Medium Zombie";
			break;
		case 3:
			this->attack = 12;
			this->defense = 11;
			this->health = 12;
			this->name = "High Zombie";
			break;
	}
}

void Zombie::useItem(Object* item) {

}

void Zombie::attackEnemy(Creature* enemy) {

}