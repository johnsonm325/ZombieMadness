#include "Player.h"
using std::cout;
using std::endl;

Player::Player() 
{
	player = new Creature("Player");
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

	if (type == "Supply"){
		player->setHealth(item->getHealthBoost());
	}	
	else if (type == "Weapon"){
		if(enemy != NULL){
			enemy->takeDamage(item->getAttack());
		}
	}	
	else
		item->useItem();
			
	//playerInventory->removeItem(item, true);
	//roomInventory->removeItem(item);
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

// Supports look at <itemName> command in game
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

// Find an item in room or player's inventory. If found, return Item ptr,
// otherwise, print error and return NULL
Item* Player::selectItem(string item){
	Item* roomItem =  roomInventory->findItem(item);
	Item* playerItem = playerInventory->findItem(item);
	
	if(roomItem != NULL){
		return roomItem;
	}
	else if(playerItem != NULL){
		return playerItem;
	}

	cout << "Failed to select item!" << endl;
	return NULL;
}

Creature* Player::getPlayer(){
	return player;
}
