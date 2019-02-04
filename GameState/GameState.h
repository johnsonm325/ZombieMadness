#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../Rooms/Space.h"
#include <ctime>

class GameState 
{
public:
	Space *currentRoom;
	//string choice;
	int steps; 
	string timeStamp;
	vector<Space*> rooms;

	GameState();
	~GameState();
	string getTime();
	void setTime();
	void setTime(string time);
	void addRoomList(vector<Space*> rooms);

};

#endif
