#include "Space.h"

Space::Space(string t)
{
	type = t;
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

Space::~Space()
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

void Space::setEast(Space *e)
{
	east = e;
}

Space * Space::getEast()
{
	return east;
}

void Space::setWest(Space *w)
{
	west = w;
}

Space * Space::getWest()
{
	return west;
}

void Space::setNorth(Space *n)
{
	north = n;
}

Space * Space::getNorth()
{
	return north;
}

void Space::setSouth(Space *s)
{
	south = s;
}

Space * Space::getSouth()
{
	return south;
}

int Space::menu()
{
	return 0;
}

string Space::getType()
{
	return type;
}

void Space::addRoomsListToSpace(vector<Space*> roomsVector)
{
	for(unsigned int i = 0; i < roomsVector.size(); i++)
	{
		roomsList.push_back(roomsVector[i]);
	}
}

Space* Space::findRoom(string roomName)
{
	for(unsigned int i = 0; i < roomsList.size(); i++)
	{
		if(roomsList[i]->getType() == roomName)
		{
			return roomsList[i];
		}
	}
	cout << "Could not find room" << endl;
	return 0;
}

Space* Space::findAdjRoom(string roomName){
	vector<Space*> adjacentRooms = getExits();
	for(unsigned int i = 0; i < adjacentRooms.size(); i++){
		string roomNameLower = strToLowerCase(adjacentRooms[i]->getType());
		if((roomName == adjacentRooms[i]->getType()) || (roomName == roomNameLower) ){
			return adjacentRooms[i];
		} 
	}
	return NULL;
}

string Space::strToLowerCase(string input){
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

Inventory* Space::getInventory() {
	return roomInventory;
}

// Return a vector of available room pointers that
// player can move to from current room 
vector<Space*> Space::getExits() {
	vector<Space*> exitList;
	Space* exit;
	 
	if ((exit = this->getNorth()) != 0) {
		exitList.push_back(exit);
	}
	if ((exit = this->getSouth()) != 0) {
		exitList.push_back(exit);
	}
	if ((exit = this->getEast()) != 0) {
		exitList.push_back(exit);
	}
	if ((exit = this->getWest()) != 0) {
		exitList.push_back(exit);
	}
	return exitList;
}

// Return a vector of available room direction strings(north, south, etc)
// that player can move to from current room
vector<string> Space::getExitDirections() {
	vector<string> exitList;
	Space* exit;

	if ((exit = this->getNorth()) != 0) {
		exitList.push_back("north");
	}
	if ((exit = this->getSouth()) != 0) {
		exitList.push_back("south");
	}
	if ((exit = this->getEast()) != 0) {
		exitList.push_back("east");
	}
	if ((exit = this->getWest()) != 0) {
		exitList.push_back("west");
	}
	return exitList;
}

void Space::printDirection(Space* direction) {
	if (direction == NULL) {
		cout << "Nothing is in that direction" << endl;
	}
	else{
		cout << direction->getType() << endl;
	}
}

//Add creature to room
void Space::addCreature(Creature* creature) {
	creatures.push_back(creature);
}

//Add creature to room
void Space::removeCreature(Creature* creature) {
	creatures.erase(remove(creatures.begin(), creatures.end(), creature), creatures.end());
}

//Get list of creatures from room, including player
vector<Creature*> Space::getCreatures() {
	return creatures;
}
