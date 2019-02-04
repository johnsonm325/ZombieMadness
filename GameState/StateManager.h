#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "GameState.h"

#ifdef _WIN32
	#include <windows.h>
	#include <direct.h>
	#define getcwd _getcwd // stupid MSFT "deprecation" warning
	#define chdir _chdir
#elif
	#include <unistd.h>
	#include <dirent.h>
	#include <sys/types.h>
#endif
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
	bool findExistingSaves();
	vector<string> getSaveFileList();
	void readAllSaves();
	GameState* readSaveFile(string filename);
	void promptToLoadGame();
	void loadState(GameState* state, School* game);

	//Writing game state to file
	GameState* createState(School* game);
	void saveState(School* game);
	void writeSaveFile(GameState* state, string filename);

	//Managing states list
	void addGameState(GameState* state);
	void removeGameState(GameState* state);
	void printStates();
	bool haveSaves();

	void changeWorkingDir();
	void resetWorkingDir();

};

#endif
