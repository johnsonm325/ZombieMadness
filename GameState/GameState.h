#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "../School.h"

class GameState 
{
public:
	GameState();
	~GameState();
	//Loading game state from file
	GameState* readSaveFile(string filename);
	void loadState(GameState* state, School* game);

	//Writing game state to file
	GameState* saveState(School* game);
	void writeSaveFile(GameState* state, string filename);

};

#endif
