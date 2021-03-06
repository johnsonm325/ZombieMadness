#ifndef SCHOOL_H
#define SCHOOL_H

//Room includes
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

//CommandParser
#include "CommandParser/CmdParser.h"

//Creatures
#include "Creatures/Creature.h"
#include "Creatures/Player.h"
#include "Creatures/Zombie.h"

//Items
#include "Items/Item.h"

//Game state
#include "GameState/StateManager.h"

#include <string>	
#include <vector>
#include <iostream>
using namespace std;

class School
{
private:
	Space *currentRoom;
	int steps = 0;
	string choice;
	bool isGameWon = false;
	bool triedLockedRoom = false;

	//Rooms
	Space *mb, *wb, *cafe, *libr;
	Space *sfh1, *sfh2, *sfh3, *sfh4;
	Space *hist, *lit, *chem, *cs, *bio, *math;
	Space *infr, *lr;
	Space *gym2, *gym1, *fb;
	Space *ffh1, *ffh2, *ffh3, *ffh4;
	Space *fl, *fo, *prin;
	vector<Space*> rooms;

	CmdParser* parser = new CmdParser();
	Player* player = new Player();
	StateManager* stateManager = new StateManager();

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
	bool moveRooms(vector<string> cmdArray, string cmd);
	void addSteps(int);
	
	//Object/Item related
	void processCommand(CmdParser* parser, string cmd);
	void doItemAction(string cmdType, vector<string> cmdVector);

	//Room list
	void addRoomToList(Space* room);
	void copyRoomsListToSpace();
	void createRoomsList();
	vector<Space*> getRoomsList();
	int getRoomIdx(Space*);

	//State methods
	GameState* createState();
	void loadState(GameState* loadState, bool printIntro);

	void startFinalFight();
	void printFinalGameState();

};
#endif
