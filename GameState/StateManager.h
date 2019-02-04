#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "GameState.h"
#include "../School.h"
#include <fstream>

#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

//#include <string>
//#include <iostream>

class StateManager
{
private:
	vector<GameState*> states;
	int maxStates = 3;

public:
	StateManager();
	~StateManager();
	//Loading game state from file
	bool foundExistingSaves();
	vector<string> getSaveFileList();
	void readAllSaves();
	GameState* readSaveFile(string filename);	
	GameState* processFileData(vector<string> lines);
	void loadState(GameState* state, School* game);
	void promptToLoadGame(School* game);

	//Writing game state to file
	GameState* createState(School* game);
	void saveState(School* game);
	void writeSaveFile(GameState* state, string filename);
	void promptToSaveGame(School* game);

	//Managing states list
	void addGameState(GameState* state);
	void removeGameState(GameState* state);
	void printStates();
	bool haveSaves();

	void changeWorkingDir();
	void resetWorkingDir();

};

#endif
