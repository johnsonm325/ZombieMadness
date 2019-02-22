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
	bool readRoom(vector<string>::iterator& line, Space* room);
	void readItem(vector<string>::iterator& line, Item* item);
	GameState* startLoadingGame();

	//Writing game state to file
	void saveState(GameState* state);
	void writeSaveFile(GameState* state, string filename);
	bool startSavingGame(GameState* state);
	void writeRoom(FILE* saveFile, Space* room);
	void writeItem(FILE* saveFile, Item* item, int count);
	void writeCreature(FILE* saveFile, Creature* creature, int count);
	void writePlayer(FILE* saveFile, Player* player);


	//Managing states list
	void addGameState(GameState* state);
	void removeGameState(GameState* state);
	void clearStates();
	void printStates();
	bool haveSaves();

	void changeWorkingDir();
	void resetWorkingDir();
};

#endif
