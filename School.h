#ifndef SCHOOL_H
#define SCHOOL_H

#include "Rooms/Space.h"
#include "Rooms/Biology.h"
#include "Rooms/Cafeteria.h"
#include "Rooms/Chemistry.h"
#include "Rooms/ComputerScience.h"
#include "Rooms/FirstFloorHallway.h"
#include "Rooms/Football.h"
#include "Rooms/FrontLobby.h"
#include "Rooms/FrontOffice.h"
#include "Rooms/GymnasiumFloor1.h"
#include "Rooms/GymnasiumFloor2.h"
#include "Rooms/History.h"
#include "Rooms/Infirmary.h"
#include "Rooms/Library.h"
#include "Rooms/Literature.h"
#include "Rooms/LockerRoom.h"
#include "Rooms/Math.h"
#include "Rooms/MensBathroom.h"
#include "Rooms/PrincipalsOffice.h"
#include "Rooms/SecondFloorHallway.h"
#include "Rooms/WomensBathroom.h"

#include <string>	
#include <vector>
#include <iostream>
using namespace std;

class School
{
private:
	Space *east;	// Used to point to east nodes
	Space *west;	// and west nodes
	Space *north;   // and north nodes
	Space *south;   // and south nodes
	//Space *newRoom; // Temporary new room object
	Space *currentRoom;
	int steps = 0,
		choice;
	char input;
	vector<string> inventory;

	//Rooms
	Space *mb, *wb, *cafe, *libr;
	Space *sfh1, *sfh2, *sfh3, *sfh4;
	Space *hist, *lit, *chem, *cs, *bio, *math;
	Space *infr, *lr;
	Space *gym2, *gym1, *fb;
	Space *ffh1, *ffh2, *ffh3, *ffh4;
	Space *fl, *fo, *prin;

public:
	School();
	~School();
	void beginGame();
	int playGame();
	void addRoom(char, Space*, Space*);
	void connectRooms();
	Space* getCurrentRoom();
	Space* moveEast();
	Space* moveWest();
	Space* moveNorth();
	Space* moveSouth();
	void addSteps(int);
	void addItem(string item);
	void removeItem(string item);
	bool itemSearch(string item);
};
#endif
