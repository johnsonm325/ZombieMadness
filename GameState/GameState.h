#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../Rooms/Space.h"
#include "..Creatures/Player.h"
#include "../Creatures/Zombie.h"
#include <ctime>

class GameState 
{
private:
	Space *currentRoom;
	int roomIdx = 0;
	int steps; 
	string timeStamp;
	vector<Space*> rooms;
public:
	GameState();
	~GameState();
	string getTime();
	void updateTime();
	void setTime(string time);
	Space* getCurrentRoom();
	void setCurrentRoom(Space* room);
	void setCurrentRoom(int idx);

	void setRoomIdx(int idx);
	int getRoomIdx();
	int findRoomByIdx(Space* room);

	void setSteps(int steps);
	int getSteps();

	void setRooms(vector<Space*> rooms);
	vector<Space*> getRooms();

};

#endif
