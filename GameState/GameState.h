#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../Creatures/Player.h"

//Room includes
#include "../Rooms/Biology.h"
#include "../Rooms/Cafeteria.h"
#include "../Rooms/Chemistry.h"
#include "../Rooms/ComputerScience.h"
#include "../Rooms/FirstFloorHallway.h"
#include "../Rooms/Football.h"
#include "../Rooms/FrontLobby.h"
#include "../Rooms/FrontOffice.h"
#include "../Rooms/GymnasiumFloor1.h"
#include "../Rooms/GymnasiumFloor2.h"
#include "../Rooms/History.h"
#include "../Rooms/Infirmary.h"
#include "../Rooms/Library.h"
#include "../Rooms/Literature.h"
#include "../Rooms/LockerRoom.h"
#include "../Rooms/Math.h"
#include "../Rooms/MensBathroom.h"
#include "../Rooms/PrincipalsOffice.h"
#include "../Rooms/SecondFloorHallway.h"
#include "../Rooms/WomensBathroom.h"

#include <ctime>
// #include <algorithm>

class GameState 
{
private:
	Space *currentRoom;
	int roomIdx = 0;
	int steps; 
	string timeStamp;
	vector<Space*> rooms;
	Player* player;
public:
	GameState();
	~GameState();
	string getTime();
	void updateTime();
	void setTime(string time);

	//Rooms
	void setRooms(vector<Space*> rooms);
	vector<Space*> getRooms();
	Space* getCurrentRoom();
	void setCurrentRoom(Space* room);
	void setCurrentRoom(int idx);
	void setRoomIdx(int idx);
	int getRoomIdx();
	int findRoomByIdx(Space* room);

	void setSteps(int steps);
	int getSteps();

	//Player
	void addPlayer(Player* player);
	Player* getPlayer();

};

#endif
