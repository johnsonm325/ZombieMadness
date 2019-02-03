#include "Zombie.h"

Zombie::Zombie(int level) : Creature("Zombie")
{
	setLevel(level);
	
	if (level == 1)
		this->description = "A level 1 zombie, shouldn't be too bad... it's never good to let your guard down though...";
	else if (level == 2)
		this->description = "A level 2 zombie, you better be careful with this one.  These guys are faster, stronger, and have higher health.";
	else
		this->description = "Oh boy, a level 3 zombie.  Watch out, these zombies are real tough, takes a lot to take them down and their attack damage is very high. Be prepared!";
	
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