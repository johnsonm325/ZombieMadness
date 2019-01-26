#ifndef SCHOOL_H
#define SCHOOL_H

#include "Rooms/Football.h"
#include "Rooms/Space.h"

#include <string>	
#include <vector>
using std::string;
using std::vector;

class School
{
private:
	Space *east;	// Used to point to east nodes
	Space *west;	// and west nodes
	Space *north;   // and north nodes
	Space *south;   // and south nodes
	Space *newRoom; // Temporary new room object
	int steps = 0,
		choice;
	char input;
	vector<string> inventory;

public:
	School();
	~School();
	void beginGame();
	int playGame();
	void addRoom(char, Space*, Space*);
	Space *moveEast();
	Space *moveWest();
	Space *moveNorth();
	Space *moveSouth();
	void addSteps(int);
	void addItem(string item);
	void removeItem(string item);
	bool itemSearch(string item);
};
#endif
