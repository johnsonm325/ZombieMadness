#include "Player.h"
using std::cout;
using std::endl;

Player::Player() 
{
	//will be defined in sub classes
	player = new Creature();
	player->setName("Cold");
	// this->attack = 4;
	// this->defense = 5;
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

void Player::useItem(Object* item) {

	item->useItem();	
	playerInventory->removeObject(item, true);
	roomInventory->removeObject(item);
}

void Player::attackEnemy(string item) 
{
	Object *weapon = this->playerInventory->findObject(item);

	if (!weapon)
	{
		cout << "That weapon could not be found in your inventory, please try a different weapon." << endl;
		return;
	}

	weapon->useItem();
}
// void Player::attackEnemy(Creature* enemy) 
// {

// }

void Player::takeItem(Object* item){

	playerInventory->addObject(item);
	roomInventory->removeObject(item);
}

void Player::dropItem(Object* item){
	
	playerInventory->removeObject(item, false);
	roomInventory->addObject(item);
}