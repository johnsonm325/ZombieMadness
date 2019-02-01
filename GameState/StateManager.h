#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "GameState.h"

class StateManager
{
private:
	vector<GameState*> states;

public:
	StateManager();
	~StateManager();
	//Loading game state from file
	GameState* readSaveFile(string filename);
	void loadState(GameState* state, School* game);

	//Writing game state to file
	GameState* saveState(School* game);
	void writeSaveFile(GameState* state, string filename);

	//Managing states list
	void addGameState(GameState* state);
	void removeGameState(GameState* state);
	void printStates();
};

#endif
