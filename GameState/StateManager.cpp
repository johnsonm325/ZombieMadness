#include "StateManager.h"

//Structure of game state save file
// Name: save.001, save.002, save.003, etc


StateManager::StateManager() {

}

StateManager::~StateManager() {

}

bool StateManager::findExistingSaves() {
	return getSaveFileList().size() > 0;
}

vector<string> StateManager::getSaveFileList() {
	vector<string> fileList;

	changeWorkingDir();

#ifdef _WIN32
	fileList.push_back("save.001");
#elif

	char targetDirPrefix[] = "save.00"; /* Prefix we're looking for */
	DIR* dirToCheck; /* Holds the directory we're starting in */
	struct dirent *fileInDir; /* Holds the current subdir of the starting dir */
	struct stat dirAttributes; /* Holds information we've gained about subdir */
	int j, foundAll = 0;

	dirToCheck = opendir("."); /* Open up the directory this program was run in */

	if (dirToCheck > 0) /* Make sure current directory could be opened */
	{
		j = 0;
		while ((fileInDir = readdir(dirToCheck)) != NULL) /* Check each entry in directory */
		{
			if (strstr(fileInDir->d_name, targetDirPrefix) != NULL) /* If entry has prefix */
			{
				fileList.push_back(std::string(fileInDir->d_name));
			}
		}
		closedir(dirToCheck); /* Close opened directory */
	}
#endif
	resetWorkingDir();

	return fileList;
}

//Reading all save files
void StateManager::readAllSaves() {

}

//Reading save file into GameState object
GameState* StateManager::readSaveFile(string filename) {
	
	return NULL;
}

//Transfer data from GameState to actual game 
void StateManager::promptToLoadGame() {

}

void StateManager::loadState(GameState* state, School* game) {

}

//Writing game state to file
void StateManager::saveState(School* game) {
	char fileCnt[8];

	GameState* newState = createState(game);
	addGameState(newState);

	changeWorkingDir(); //set working directory  to ./GameState

	snprintf(fileCnt, sizeof(fileCnt), "%d", (int)states.size());
	string fileName = "save.00";
	fileName += fileCnt;
	cout << "\nWriting save file: " << fileName << endl;
	writeSaveFile(newState, fileName);

	resetWorkingDir();	//reset directory back to root 
}

GameState* StateManager::createState(School* game) {
	GameState* newState = new GameState();
	newState->setTime();
	newState->rooms = game->getRoomsList();
	newState->currentRoom = game->getCurrentRoom();

	return newState;
}

void StateManager::writeSaveFile(GameState* state, string filename) {
	FILE* saveFile;

	/* Opening file */
	saveFile = fopen(filename.c_str(), "w");

	/* If file was successfully open, write room struct data to file */
	if (saveFile != 0) {
		//fprintf(saveFile, "Number of save files: %d\n", (int) states.size());
		fprintf(saveFile, "Filename: %s\n", filename.c_str());
		fprintf(saveFile, "Time stamp: %s\n", state->timeStamp.c_str());
		fprintf(saveFile, "Current room: %s\n", state->currentRoom->getType().c_str());
		fprintf(saveFile, "Steps: %d\n", state->steps);

		for (unsigned int i = 0; i < state->rooms.size(); i++) {
			fprintf(saveFile, "===\n");
			fprintf(saveFile, "Room: %s\n", state->rooms[i]->getType().c_str());

			int numItems = state->rooms[i]->getInventory()->getObjects().size();
			vector<Object*> items = state->rooms[i]->getInventory()->getObjects();
			fprintf(saveFile, "Inventory\n");
			fprintf(saveFile, "Size: %d\n", numItems);
			for (int j = 0; j < numItems; j++) {
				fprintf(saveFile, "Item %d\n", j + 1);
				fprintf(saveFile, "Name: %s\n", items[j]->getName().c_str());
			}
		}
		fclose(saveFile);
	}
	else {
		printf("Error opening save file %s\n", filename.c_str());
	}
}

//Managing states list
void StateManager::addGameState(GameState* state) {
	if (states.size() < 3) {
		states.push_back(state);
	}
	else {
		states.erase(states.begin());
		states.push_back(state);
	}
}

void StateManager::removeGameState(GameState* state) {
	if (state == NULL) { return;	}
	for (unsigned int i = 0; i < states.size(); i++) {
		if (state->getTime() == states[i]->getTime()){
			states.erase(states.begin()+i);
		}
	}
}

void StateManager::printStates() {
	cout << "=== GAME STATES ===" << endl;
	if (haveSaves()) {
		cout << "State  Date" << endl;
		for (unsigned int i = 0; i < states.size(); i++) {
			cout << (i + 1) << ": " << states[i]->getTime() << endl;
		}
	}
}

bool StateManager::haveSaves() {
	return states.size() > 0;
}

void StateManager::changeWorkingDir() {
#ifdef _WIN32
	chdir("../");
	chdir("./ZombieMadness/GameState/");
#elif
chdir("./GameState/");
#endif
}

void StateManager::resetWorkingDir() {
	chdir("../");
}