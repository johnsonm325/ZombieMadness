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
	this->playerInventory = NULL;
}

void Player::movetoRoom(Space* room){
	currentRoom = room;
	this->roomInventory = room->getInventory();

	enemy = room->getZombie();

	// if there is a live zombie in the room and the player has an empty bag or no weapon to kill it with
	// the player is dead and the game is over
	if (enemy && enemy->isAlive() && (playerInventory->isEmpty() || !playerInventory->hasWeapon()))
	{
		cout << "# Oh no! There is a zombie in this room and you do not have a weapon to kill it with!" << endl;
		cout << "# Unfortunately, it is too late to run and the zombie got you, you died!  Game over!" << endl;
		exit(0);
	}
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
	
	else if (type == "Weapon")
	{
		if(enemy != NULL)
		{
			enemy->takeDamage(item->getAttack());
		}
	}	
	else
		item->useItem();
			
	//playerInventory->removeItem(item, true);
	//roomInventory->removeItem(item);
}

void Player::attackEnemy() 
{
	string input;
	Item *weapon;

	if (!enemy || !enemy->isAlive())
	{
		cout << "# Calm your horses, there are no zombies in sight, no need to attack." << endl;
		return;
	}
	
	cout << "# Please choose one of the following to attack with" << endl;
	cout << endl;

	playerInventory->printAvailableWeapons();

	cout << "# Enter choice: ";

	getline(cin, input);
	cout << endl;

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	weapon = playerInventory->findItem(input);

	if (!weapon)
	{
		cout << "# That is not an available weapon in your inventory." << endl;
		return;
	}

	weapon->attackItem();

	enemy->takeDamage(weapon->getAttack());

	if (!enemy->isAlive())
		currentRoom->setLeaveAbility(true);

	playerInventory->removeItem(weapon, true);
}

void Player::defend()
{
	string input;
	Item *defenseItem;

	if (playerInventory->isEmpty() || !playerInventory->hasDefense())
	{
		cout << "# You do not have any defense items to use." << endl;
		return;
	}

	cout << "# Please choose one of the following to defend with" << endl;
	cout << endl;

	playerInventory->printAvailableDefenseItems();

	cout << "# Enter choice: ";

	getline(cin, input);
	cout << endl;

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	defenseItem = playerInventory->findItem(input);

	if (!defenseItem)
	{
		cout << "# That defense item is not in your inventory." << endl;
		return;
	}

	defenseItem->blockItem();

	player->setDefense(defenseItem->getDefense());

	playerInventory->removeItem(defenseItem, true);
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
