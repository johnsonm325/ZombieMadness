#ifndef SPACE_H
#define SPACE_H

//#include "Dragon.h" 
#include "Globals.h"

class Space
{
protected:
	//InputValid inputVal1;
	Space *north = NULL;		// Pointer to space for up
	Space *east;			// Pointer to space for forward
	Space *south = NULL;		// Pointer to space for down
	Space *west;			// Pointer to space for back
	//Character character;
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
};
#endif
