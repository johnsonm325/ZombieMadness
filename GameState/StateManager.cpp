#include "StateManager.h"

//Structure of game state save file
// Name: save.001, save.002, save.003, etc

StateManager::StateManager() {
	//if (foundExistingSaves()) {
	//	readAllSaves();
	//}
}

StateManager::~StateManager() {

}

bool StateManager::foundExistingSaves() {
	return getSaveFileList().size() > 0;
}

vector<string> StateManager::getSaveFileList() {
	vector<string> fileList;


	fileList.push_back("./save.001");


	//char targetDirPrefix[] = "save.00"; /* Prefix we're looking for */
	//DIR* dirToCheck; /* Holds the directory we're starting in */
	//struct dirent *fileInDir; /* Holds the current subdir of the starting dir */
	//struct stat dirAttributes; /* Holds information we've gained about subdir */
	//int j, foundAll = 0;

	//dirToCheck = opendir("."); /* Open up the directory this program was run in */

	//if (dirToCheck > 0) /* Make sure current directory could be opened */
	//{
	//	j = 0;
	//	while ((fileInDir = readdir(dirToCheck)) != NULL) /* Check each entry in directory */
	//	{
	//		if (strstr(fileInDir->d_name, targetDirPrefix) != NULL) /* If entry has prefix */
	//		{
	//			fileList.push_back(std::string(fileInDir->d_name));
	//		}
	//	}
	//	closedir(dirToCheck); /* Close opened directory */
	//}


	return fileList;
}

//Reading all save files
void StateManager::readAllSaves() {
	changeWorkingDir();

	vector<string> fileList = getSaveFileList();
	for (unsigned int index = 0; index < fileList.size(); index++) {
		GameState* newState = readSaveFile(fileList[index]);
		if (newState != NULL) {
			addGameState(newState);
		}
	}

	resetWorkingDir();
}

//Reading save file into GameState object
GameState* StateManager::readSaveFile(string filename) {
	//FILE* saveFile;
	GameState* newState = NULL;

	string line;
	vector<string> lines;


	/* Opening file */
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			lines.push_back(line);
		}
		myfile.close();
		/* If file was successfully opened, process lines and save data to GameState */
		newState = processFileData(lines);
	}
	else {
		cout << "Unable to open file " << filename << endl;
	}
	return newState;
}

GameState* StateManager::processFileData(vector<string> lines) {
	GameState* newState = new GameState();
	std::size_t foundRoom, foundInv;
	std::size_t foundHeader[2];
	string headerKeys[2];
	headerKeys[0] = "Time stamp:";
	headerKeys[1] = "Current room:";
	foundHeader[0] = lines[1].find(headerKeys[0]);
	foundHeader[1] = lines[2].find(headerKeys[1]);

	//Didn't find file header
	if ((foundHeader[0] == std::string::npos) || (foundHeader[1] == std::string::npos)) {
		return NULL;
	}
	//Found it
	else {
		// Save header first 
		newState->timeStamp = lines[1].substr(foundHeader[0] + headerKeys[0].length());
		string curRoom = lines[2].substr(foundHeader[1] + headerKeys[1].length());

		for (unsigned int i = 0; i < lines.size(); i++) {
			foundRoom = lines[i].find("Room:");	//Found room
			
			if (foundRoom != std::string::npos) {
				
				string roomName = lines[i].substr(foundRoom+6);
				cout << "Found room: " << roomName << endl;
				i++;
				foundInv = lines[i].find("Inventory");	//Found inventory
				
				if (foundInv != std::string::npos) {
					cout << "Found inventory" << endl;
					i++;
					foundInv = lines[i].find("Size:");
					if (foundInv != std::string::npos) {
						int numItems;
						sscanf(lines[i].c_str(), "%*s %d ", &numItems);
						//if (numItems > 0) {
							cout << "Found " << numItems << " items in room " << endl;

						//}
					}
				}
			}
		}
	}
	return newState;
}

//Transfer data from GameState to actual game 
void StateManager::promptToLoadGame(School* game) {

	printStates();

	if (haveSaves()) {
		string choice;
		int stateNum;

		cout << "Select game state: " << 1 << "-" << states.size() <<  endl;
		cin >> choice;
		stateNum = atoi(choice.c_str());
		if ((stateNum > 0) && (stateNum <= (int) states.size()) ) {
			cout << "Loading state " << stateNum << endl;
			loadState(states[stateNum - 1], game);
		}
	}
	else {
		cout << "ERROR: Cannot load game state!" << endl;
	}
}

//Transfer data from GameState to actual game 
void StateManager::promptToSaveGame(School* game) {
	string choice;

	cout << "Do you want to save current game? y/n" << endl;
	cin >> choice;
	if (choice == "y" || choice == "Y") {
		saveState(game);
		printStates();
	}
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
	cout << "Writing save file: " << fileName << endl;
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
			fprintf(saveFile, "Inventory:\n");
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
	cout << "=== SAVED GAME STATES ===" << endl;
	if (haveSaves()) {
		cout << " State       Date" << endl;
		for (unsigned int i = 0; i < states.size(); i++) {
			cout << (i + 1) << ":   " << states[i]->getTime() << endl;
		}
	}
	else {
		cout << "empty list" << endl;
	}
}

bool StateManager::haveSaves() {
	return states.size() > 0;
}

void StateManager::changeWorkingDir() {

chdir("./GameState/");
}

void StateManager::resetWorkingDir() {
	chdir("../");
}