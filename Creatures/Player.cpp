#include "Player.h"

Player::Player() 
{
	player = new Creature("Player");
	player->setName("Colt");
	player->setHealth(50);
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
		room->killOnEnter();
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

	//if bookbag is used and there are no items
	//in the inventory currently
	if (!playerInventory->isEmpty())
		playerInventory->removeItem(item, true);	
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
	
	cout << KYEL "# Please choose one of the following to attack with," << endl;
	cout << "# or type 'health' to use a health item, or 'block' to equip a defense item" << endl << endl;
	cout << KRED "# PLEASE NOTE: If you choose to use a health item or a defense item during a fight," << endl;
	cout << "# that will count as your turn!" RESET << endl << endl;

	playerInventory->printAvailableWeapons();

	cout << "# Enter choice: ";
	getline(cin, input);
	cout << endl;

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	if (input == "health")
	{
		if (player->getHealth() >= 100)
			cout << KGRN "# No need to use a health item, you are at full health!" RESET << endl;

		else
			healthDuringAttack();

		return;
	}

	else if (input == "block")
	{
		if (player->getDefense() >= 10)
			cout << KGRN << "# No need to block, you are have full defense points!" RESET << endl;

		else
			defend();
		
		return;
	}

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

void Player::healthDuringAttack()
{
	string input;
	Item* healthItem;

	if (!playerInventory->hasHealth())
	{
		cout << KRED "# You have no health items!" RESET << endl;
		return;
	}

	cout << KYEL "# Please select a health item to use" RESET << endl << endl;

	playerInventory->printAvailableSupplies();

	cout << "Enter choice: ";
	getline(cin, input);
	cout << endl;

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	healthItem = playerInventory->findItem(input);

	if (!healthItem)
	{
		cout << KRED "# That is not an availabe item" RESET << endl;
		return;
	}

	player->gainHealth(healthItem->getHealthBoost());

	cout << KGRN << "# Your health now at " << player->getHealth() << RESET << endl;

	playerInventory->removeItem(healthItem, true);
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

