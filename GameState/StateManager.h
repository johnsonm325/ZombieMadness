#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

// #define STATE_DEBUG 0

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

	//Finding saves
	void init();
	bool foundSaveFiles();
	bool haveSaves();
	void getSaveFileList();

	//Reading saves
	GameState* startLoadingGame();
	void readAllSaves();
	GameState* readSaveFile(string filename);	
	GameState* processFileData(vector<string> lines);
	string readStrValue(vector<string>::iterator& line, string key);
	int readInt(vector<string>::iterator& line, string key);
	void readEndSection(vector<string>::iterator& line, string token);
	bool readRoomBools(vector<string>::iterator& line, Space* room, string roomName);
	bool readRoom(vector<string>::iterator& line, Space* room);
	Item* readItem(vector<string>::iterator& line);
	bool readInventory(vector<string>::iterator& line, Inventory* inv);
	bool readCreature(vector<string>::iterator& line, Creature* creature);
	bool readPlayer(vector<string>::iterator& line, Player* player);

	//Writing game state to file
	bool startSavingGame(GameState* state);
	void saveState(GameState* state);
	void writeSaveFile(GameState* state, string filename);
	void writeRoom(FILE* saveFile, Space* room);
	void writeItem(FILE* saveFile, Item* item, int count);
	void writeCreature(FILE* saveFile, Creature* creature);
	void writePlayer(FILE* saveFile, Player* player);

	//Removing saves and save files
	void removeSaveFiles();
	void removeSaves();

	//Managing states list
	void addGameState(GameState* state);
	void removeGameState(GameState* state);
	void clearStates();
	void printStates();

	void changeWorkingDir();
	void resetWorkingDir();
};

#endif