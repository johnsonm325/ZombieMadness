#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "../School.h"

class GameState 
{
private:
	//Space* currentRoom;
	string choice;
	int steps; 
	string time;
public:
	GameState();
	~GameState();
	string getTime();
	void setTime();
};

#endif
