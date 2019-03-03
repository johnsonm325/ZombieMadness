#ifndef SPACE_H
#define SPACE_H

#include "../Items/Inventory.h"
#include "../Creatures/Zombie.h"

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
		 firstTry = true,
		 goneColt = false;

	Space *north;		// Pointer to space for up
	Space *east;		// Pointer to space for forward
	Space *south;		// Pointer to space for down
	Space *west;		// Pointer to space for back
	string type;
	Inventory* roomInventory = new Inventory("Space");
	Zombie *zombie = NULL;
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

	string getType();
	virtual void printIntro() = 0;		// For abstract class
	virtual void printExitDesc() = 0;	// For abstract class
	virtual int menu(vector<string>);	
	virtual void firstTime();		
	void setFirstTry(bool);
	bool getFirstTry();	
	bool coltGone();
	void setColtGone(bool gone);

	void addRoomsListToSpace(vector<Space*>);	
	Space* findRoom(string);
	Space* findAdjRoom(string);
	string strToLowerCase(string input);

	Inventory* getInventory();			//Return inventory vector
	void removeZombie();	//Remove creature to room
	Zombie* getZombie();		//Get list of creatures from room, not including player

	vector<Space*> getExits();			//Get available room exits as vector of Space pointers
	vector<string> getExitDirections();
	void printDirection(Space* direction);
	void printDirections();

	bool getDoorLocked();
	void unlockDoor();
	void lockDoor();
};

#endif
