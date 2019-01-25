#ifndef SCHOOL_H
#define SCHOOL_H

#include "Football.h"

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
	void addItem(string);
	void removeItem(string);
	bool itemSearch(string);
};
#endif
