#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#define STATE_DEBUG 0

#include "GameState.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
// #include <sys/stat.h>

using namespace std;

class StateManager
{
private:
	vector<Space*> rooms;
	vector<GameState*> states;
	vector<string> fileList;
	unsigned int maxStates = 3;

public:
	StateManager();
	~StateManager();
	void init();
	//Loading game state from file
	bool foundSaves();
	vector<string> getSaveFileList();
	void readAllSaves();
	GameState* readSaveFile(string filename);	
	GameState* processFileData(vector<string> lines);
	GameState* startLoadingGame();

	//Writing game state to file
	void saveState(GameState* state);
	void writeSaveFile(GameState* state, string filename);
	bool startSavingGame(GameState* state);
	void writeRoomToFile(FILE* saveFile, Space* room);
	void writeItemToFile(FILE* saveFile, Item* item, int count);
	void writeCreatureToFile(FILE* saveFile, Creature* creature, int count);
	void writePlayerToFile(FILE* saveFile, Player* player);

	//Managing states list
	void addGameState(GameState* state);
	void removeGameState(GameState* state);
	void clearStates();
	void printStates();
	bool haveSaves();

	void addRoomList(vector<Space*> rooms);
	void changeWorkingDir();
	void resetWorkingDir();
};

#endif
