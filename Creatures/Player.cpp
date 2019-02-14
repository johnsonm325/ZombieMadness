#include "Player.h"
using std::cout;
using std::endl;

Player::Player() 
{
	player = new Creature();
	player->setName("Colt");
	player->setHealth(100);
	this->playerInventory = new PlayerInventory();
}

Player::~Player()
{
	delete this->playerInventory;
}

void Player::movetoRoom(Space* room){
	currentRoom = room;
	this->roomInventory = room->getInventory();
}

PlayerInventory* Player::getInventory(){
	return playerInventory;
}
Inventory* Player::getRoomInventory(){
	return roomInventory;
}

void Player::clearInventory(){
	playerInventory->clearInventory();
}

void Player::useItem(Item* item) {

	string type = item->getType();

	if (type == "Supply")
		player->setHealth(item->getHealthBoost());

	else if (type == "Weapon")
		enemy->takeDamage(item->getAttack());

	else
		item->useItem();
			
	playerInventory->removeItem(item, true);
	roomInventory->removeItem(item);
}

void Player::attackEnemy(string item) 
{
	Item *weapon = this->playerInventory->findItem(item);

	if (!weapon)
	{
		cout << "That weapon could not be found in your inventory, please try a different weapon." << endl;
		return;
	}

	enemy->takeDamage(weapon->getAttack());
	playerInventory->removeItem(weapon, true);
}

void Player::takeItem(Item* item){

	playerInventory->addItem(item);
	roomInventory->removeItem(item);
}

void Player::dropItem(Item* item){
	
	playerInventory->removeItem(item, false);
	roomInventory->addItem(item);
}

void Player::lookAtItems(string item){
	Item* roomItem =  roomInventory->findItem(item);
	Item* playerItem = playerInventory->findItem(item);
	
	if(roomItem != NULL){
		cout << roomItem->getDesc() << endl;
	}
	else if(playerItem != NULL){
		cout << playerItem->getDesc() << endl;
	}
}

void Player::takeDamage(int damage)
{
	int healthLeft = player->getHealth() - damage;

	if (healthLeft <= 0)
	{
		player->setHealth(0);
		cout << "Game over, you were a zombie's gourmet meal!" << endl;
		return;
	}

	else
		cout << "Your health is now at " << player->getHealth() << endl;
	
}

void Player::heal(int newHealth)
{
	this->player->setHealth(newHealth);
}