#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Space
{
protected:
	Space *north;		// Pointer to space for up
	Space *east;		// Pointer to space for forward
	Space *south;		// Pointer to space for down
	Space *west;		// Pointer to space for back
	string type;

public:
	Space(string);
	~Space();
	void setEast(Space*);
	Space* getEast();
	void setWest(Space*);
	Space* getWest();
	void setNorth(Space*);
	Space* getNorth();
	void setSouth(Space*);
	Space* getSouth();
	virtual int menu(vector<string>*) = 0;	// For abstract class
	virtual bool firstTime() = 0;			// For abstract class
	virtual string getType();

	void addItem(string item);		//Add items to a specific room
	vector<Space*> getExits();
	vector<string> getExitDirections();
};
#endif
