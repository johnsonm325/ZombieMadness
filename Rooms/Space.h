#ifndef SPACE_H
#define SPACE_H

#include "../Items/Inventory.h"
#include "../Creatures/Creature.h"

#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Space
{
protected:
	bool doorLocked = false,
		 firstTry = true;

	Space *north;		// Pointer to space for up
	Space *east;		// Pointer to space for forward
	Space *south;		// Pointer to space for down
	Space *west;		// Pointer to space for back
	string type;
	Inventory* roomInventory = new Inventory("Space");
	vector<Creature*> creatures;	//list of creatures in room
	vector<Space*> roomsList;

public:
	Space(string);
	virtual ~Space();
	void setEast(Space*);
	Space* getEast();
	void setWest(Space*);
	Space* getWest();
	void setNorth(Space*);
	Space* getNorth();
	void setSouth(Space*);
	Space* getSouth();
	virtual void printIntro() = 0;		// For abstract class
	virtual int menu(vector<string>);	// For abstract class
	virtual void firstTime() = 0;		// For abstract class
	string getType();

	void addRoomsListToSpace(vector<Space*>);	
	Space* findRoom(string);
	Space* findAdjRoom(string);
	string strToLowerCase(string input);

	Inventory* getInventory();			//Return inventory vector

	void addCreature(Creature* creature);	//Add creature to room
	void removeCreature(Creature* creature);	//Remove creature to room
	vector<Creature*> getCreatures();		//Get list of creatures from room, not including player

	vector<Space*> getExits();			//Get available room exits as vector of Space pointers
	vector<string> getExitDirections();
	void printDirection(Space* direction);

	bool getDoorLocked();
	void unlockDoor();
	void lockDoor();
	
	void setFirstTry(bool);
	bool isFirstTry();
	
};

#endif
