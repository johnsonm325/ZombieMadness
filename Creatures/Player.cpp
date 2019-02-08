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

void Player::useItem(Item* item) {

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

	weapon->useItem();
}
// void Player::attackEnemy(Creature* enemy) 
// {

// }

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