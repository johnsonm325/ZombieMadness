#include "Player.h"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\x1B[0m"
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
	if (enemy && enemy->isAlive() && !playerInventory->hasWeapon())
	{
		cout << KRED "# Oh no! You just entered the " << room->getType() << " room and there is a zombie in here." << endl;
		cout << "# Unfortunately, your bag has no weapons in it at the zombie ate you!  Game over!" RESET << endl << endl;
		player->die();
		return; // we need to somehow jump to a game menu from here to start the game again
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

	if (type == "Supply")
	{
		if (player->getHealth() >= 100)
			cout << KGRN "# No need to use this health item, your health is full!" RESET << endl;

		else
		{
			player->gainHealth(item->getHealthBoost());
			cout << KGRN "# Your health now at " << player->getHealth() << RESET << endl;
		}
	}

	else
		item->useItem();
		

}

void Player::attackEnemy() 
{
	string input;
	Item *weapon;

	if (!enemy || !enemy->isAlive())
	{
		cout << KGRN "# Calm your horses, there are no zombies in sight, no need to attack." RESET << endl;
		return;
	}
	
	cout << KYEL "# Please choose one of the following to attack with" RESET << endl;
	cout << endl;

	playerInventory->printAvailableWeapons();

	cout << "# Enter choice: ";
	getline(cin, input);
	cout << endl;

	transform(input.begin(), input.end(), input.begin(), ::tolower);
	weapon = playerInventory->findItem(input);

	if (!weapon)
	{
		cout << KRED "# That is not an available weapon in your inventory." RESET << endl;
		return;
	}

	weapon->attackItem();
	enemy->takeDamage(weapon->getAttack());
	playerInventory->removeItem(weapon, true);
}

void Player::defend()
{
	string input;
	Item *defenseItem;

	if (playerInventory->isEmpty() || !playerInventory->hasDefense())
	{
		
		cout << KRED "# You do not have any defense items to use." RESET << endl;
		return;
	}

	cout << KYEL "# Please choose one of the following to defend with" RESET << endl;
	cout << endl;

	playerInventory->printAvailableDefenseItems();

	cout << "# Enter choice: ";

	getline(cin, input);
	cout << endl;

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	defenseItem = playerInventory->findItem(input);

	if (!defenseItem)
	{
		cout << KRED "# That defense item is not in your inventory." RESET << endl;
		return;
	}

	if (defenseItem->getName() == "Jersey")
		defenseItem->wearItem();

	else
		defenseItem->blockItem();
	

	player->setDefense(defenseItem->getDefense());
	playerInventory->removeItem(defenseItem, true);
}

void Player::takeItem(Item* item){

	if (item->isMovable())
	{
		playerInventory->addItem(item);

		if (playerInventory->findItem(item->getName()))
			roomInventory->removeItem(item);
	}

	else
		cout << KRED "# You cannot add this item to your inventory." RESET << endl;
	
}

void Player::dropItem(Item* item){
	
	playerInventory->removeItem(item, false);
	
	if (!playerInventory->findItem(item->getName()))
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

	cout << KRED "# Failed to select item!" RESET << endl;
	return NULL;
}

Creature* Player::getPlayer(){
	return player;
}

void Player::printStats(){
	player->printStats();
	playerInventory->printInventoryUsage();
}

Item* Player::getSelectedWeapon(){
	return selectedWeapon;
}