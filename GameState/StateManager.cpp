#include "StateManager.h"

//Structure of game state save file
// Name: save.001, save.002, save.003, etc

StateManager::StateManager() {
	
}

StateManager::~StateManager() {

}

void StateManager::init(){
	changeWorkingDir();
	
	clearStates();
	getSaveFileList();
	if (foundSaves()) {

#ifdef STATE_DEBUG
	cout << "Found existing saves:" << fileList.size() << endl;

	for(unsigned int i = 0; i < fileList.size(); i++){
		cout << "File: " << fileList[i] << endl;
	}
#endif
		readAllSaves();
	}
	resetWorkingDir();
}

bool StateManager::foundSaves() {
	return fileList.size() > 0;
}

vector<string> StateManager::getSaveFileList() {
	//fileList.push_back("./save.001");

	char targetDirPrefix[] = "save.00"; /* Prefix we're looking for */
	DIR* dirToCheck; /* Holds the directory we're starting in */
	struct dirent *fileInDir; /* Holds the current subdir of the starting dir */
	//struct stat dirAttributes; /* Holds information we've gained about subdir */
	//int j;

	dirToCheck = opendir("."); /* Open up the directory this program was run in */

	if (dirToCheck > 0) /* Make sure current directory could be opened */
	{
		while ((fileInDir = readdir(dirToCheck)) != NULL) /* Check each entry in directory */
		{
			string fileName = fileInDir->d_name;
			if (fileName.find(targetDirPrefix) != std::string::npos) /* If entry has prefix */
			{
				fileList.push_back(std::string(fileInDir->d_name));
			}
		}
		closedir(dirToCheck); /* Close opened directory */
	}
	
	if(fileList.size() > 1){
		//If list was created in reverse: save.003, save.002, save.001, reverse it back
		if(fileList[fileList.size()-1] == "save.001"){
			std::reverse(fileList.begin(), fileList.end());
		}
	}

	return fileList;
}

//Reading all save files
void StateManager::readAllSaves() {
	for (unsigned int index = 0; index < fileList.size(); index++) {
		GameState* newState = readSaveFile(fileList[index]);
		if (newState != NULL) {
			addGameState(newState);
		}
	}
}

//Reading save file into GameState object
GameState* StateManager::readSaveFile(string filename) {
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
	string invalidFile = "Error reading save file! Invalid format";
	string headerKeys[3];
	size_t foundRooms, 
		   foundHeader[3];
	vector<string>::iterator line; 

	headerKeys[0] = "Time stamp:";
	headerKeys[1] = "Current room:";
	headerKeys[2] = "Room idx:";
	foundHeader[0] = lines[1].find(headerKeys[0]);
	foundHeader[1] = lines[2].find(headerKeys[1]);
	foundHeader[2] = lines[3].find(headerKeys[2]);

	//Didn't find file header
	if ((foundHeader[0] == std::string::npos) || (foundHeader[1] == std::string::npos) ||
		(foundHeader[2] == std::string::npos)){	

		cout << invalidFile << endl;
		return NULL;		
	}

	//Found it
	else {
		// Save header first 
		string newTime = lines[1].substr(foundHeader[0] + headerKeys[0].length());

		//Adding header info to state object;
		int rIdx, i;
		sscanf(lines[3].c_str(), "%*s %*s %d ", &rIdx);

		newState->setRooms(this->rooms);
		newState->setCurrentRoom(rIdx);
		newState->setTime(newTime);

		line = lines.begin();
		line +=6;
		cout << "line 6: " << *line << endl;

		while(line != lines.end()){

			foundRooms = (*line).find("Rooms");
			//Found rooms section in file, start processing room data
			if(foundRooms != std::string::npos){
				for(i = 0; i < (int)newState->getRooms().size(); i++){
					line++; //Go to first room name;
					readRoom(line, rooms[i]);
				}
			}
			else{
				cout << invalidFile << endl;
				break;
			}
			line++;
		}
	}
	return newState;
}

void StateManager::readRoom(vector<string>::iterator line, Space* room){

	string invalidFile = "Error reading save file! Invalid format";
	size_t foundRoomStart = (*line).find("<Room>");	//Found room section start
	size_t foundRoomEnd = (*line).find("</Room>");	//Found room section end
	size_t foundInv, foundStr;

	if(foundRoomStart != std::string::npos){
		while (foundRoomEnd == std::string::npos) {
			line++;
			foundStr = (*line).find("Room:");
			string roomName = (*line).substr(foundStr+6);
			cout << "Found room: " << roomName << endl;
			line++;

			//Read doorLocked, firstTime
			int doorLocked, firstTry;

			sscanf((*line).c_str(), "%*s %d", &doorLocked);
			line++;
			sscanf((*line).c_str(), "%*s %*s %d", &firstTry);
			line++;

			if(doorLocked == 0 || doorLocked == 1){
				cout << "Found doorLocked" << endl;
				if(doorLocked == 1){
					room->lockDoor();
				}
			}	
			if(firstTry == 0 || firstTry == 1){
				cout << "Found firstTry" << endl;
				room->setFirstTry((bool)firstTry);
			}
			else{
				cout << invalidFile << endl;
				break;
			}

			//Searching for inventory
			foundInv = (*line).find("Room inventory");	
			if (foundInv != std::string::npos) {
				cout << "Found inventory" << endl;
				line++;
				foundInv = (*line).find("Size:");
				if (foundInv != std::string::npos) {
					int numItems;
					sscanf((*line).c_str(), "%*s %d ", &numItems);

					if (numItems > 0) {
						cout << "Found " << numItems << " items in room " << endl;
					}
				}
				else{
					cout << invalidFile << endl;
					break;
				}
			}
			else{
				cout << invalidFile << endl;
				break;
			}
			foundRoomEnd = (*line).find("</Room>");
			line++;
		}
	}
	else{
		cout << invalidFile << endl;
	}	
}

void StateManager::readItem(vector<string>::iterator line, Item* item){
	
}

//Transfer data from GameState to actual game 
GameState* StateManager::startLoadingGame() {
	string choice;
	int stateNum;

	printStates();

	if (haveSaves()) {
		cout << "Select game state to load: ( " << 1 << "-" << states.size() << " )" << endl;
		getline(cin, choice);
		stateNum = atoi(choice.c_str());
		if ((stateNum > 0) && (stateNum <= (int) states.size()) ) {
			cout << "Loading state " << stateNum << "..." << endl;
			stateNum--; //align with state vector's initial zero offset;
			return states[stateNum];
		}
	}
	return NULL;
}

//Transfer data from actual game to GameState vector 
bool StateManager::startSavingGame(GameState* state) {
	string choice;

	printStates();
	cout << "\nDo you want to save current game state? y/n" << endl;
	getline(cin, choice);
	if (choice == "y" || choice == "Y") {
		saveState(state);
		printStates();
		return true;
	}
	return false;
}

//Writing game state to file
void StateManager::saveState(GameState* state) {
	char fileCnt[8];
	changeWorkingDir(); //set working directory  to ./GameState

	addGameState(state);
	
	//Update all save files
	for(unsigned int i = 0; i < states.size(); i++){
		snprintf(fileCnt, sizeof(fileCnt), "%d", i+1);
		string fileName = "save.00";
		fileName += fileCnt;
		cout << "Writing save file: " << fileName << endl;
		writeSaveFile(states[i], fileName);
	}
	
	resetWorkingDir();	//reset directory back to root 
}

void StateManager::writeSaveFile(GameState* state, string filename) {
	FILE* saveFile;

	/* Opening file */
	saveFile = fopen(filename.c_str(), "w");

	/* If file was successfully open, write room struct data to file */
	if (saveFile != 0) {
		//fprintf(saveFile, "Number of save files: %d\n", (int) states.size());
		fprintf(saveFile, "Filename: %s\n", filename.c_str());
		fprintf(saveFile, "Time stamp: %s\n", state->getTime().c_str());
		fprintf(saveFile, "Current room: %s\n", state->getCurrentRoom()->getType().c_str());
		fprintf(saveFile, "Room idx: %d\n", state->getRoomIdx());
		fprintf(saveFile, "Steps: %d\n", state->getSteps());
		vector<Space*> rooms = state->getRooms();

		fprintf(saveFile, "\nRooms\n");
		for (unsigned int i = 0; i < rooms.size(); i++) {
			writeRoom(saveFile, rooms[i]);
			fprintf(saveFile, " \n");
		}
		writePlayer(saveFile, state->getPlayer());

		fclose(saveFile);
	}
	else {
		printf("Error opening save file %s\n", filename.c_str());
	}
}

void StateManager::writeRoom(FILE* saveFile, Space* room){
	vector<Item*> items = room->getInventory()->getItems();
	vector<Creature*> creatures = room->getCreatures();
	int numItems = items.size(),
		numCreatures = creatures.size(),
		j = 0;
	bool doorLocked = room->getDoorLocked();
	fprintf(saveFile, "<Room>");
	fprintf(saveFile, "Room: %s\n", room->getType().c_str());
	fprintf(saveFile, "Locked: %d\n", (int)doorLocked);
	fprintf(saveFile, "First time: %d\n", (int)room->isFirstTry());

	fprintf(saveFile, "Room inventory\n");
	fprintf(saveFile, "Size: %d\n", numItems);
	for (j = 0; j < numItems; j++) {
		writeItem(saveFile, items[j], j+1);
	}

	fprintf(saveFile, "Room creatures\n");
	fprintf(saveFile, "Size: %d\n", numCreatures);
	for (j = 0; j < numCreatures; j++){
		writeCreature(saveFile, creatures[j], j+1);
	}
	fprintf(saveFile, "</Room>");
}

void StateManager::writeItem(FILE* saveFile, Item* item, int count){
	fprintf(saveFile, "Item %d\n", count);
	fprintf(saveFile, "Removable: %d\n", (int)item->isMovable());
	fprintf(saveFile, "Type: %s\n", item->getType().c_str());
	fprintf(saveFile, "Name: %s\n", item->getName().c_str());
	fprintf(saveFile, "Description: %s\n", item->getDesc().c_str());
}

void StateManager::writeCreature(FILE* saveFile, Creature* creature, int count){
	fprintf(saveFile, "Creature %d\n", count);
	fprintf(saveFile, "Type: %s\n", creature->getType().c_str());
	fprintf(saveFile, "Name: %s\n", creature->getType().c_str());
	fprintf(saveFile, "IsDead: %d\n", (int)!creature->isAlive());
	fprintf(saveFile, "Health: %d\n", creature->getHealth());
}

void StateManager::writePlayer(FILE* saveFile, Player* player){
	vector<Item*> items = player->getInventory()->getItems();
	int j, numItems = items.size();
	Creature* playerCr = player->getPlayer();

	fprintf(saveFile, "<Player>")
	fprintf(saveFile, "Player\n");
	fprintf(saveFile, "Player inventory\n");
	fprintf(saveFile, "Size: %d\n", numItems);
	for (j = 0; j < numItems; j++) {
		writeItem(saveFile, items[j], j+1);
	}
	fprintf(saveFile, "Player stats\n");
	writeCreature(saveFile, playerCr, 1);
	fprintf(saveFile "</Player>")
}

//Managing states list
void StateManager::addGameState(GameState* state) {
	if (states.size() < maxStates) {
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
		cout << "#      Room        Date" << endl;
		for (unsigned int i = 0; i < states.size(); i++) {
			cout <<  (i + 1) << ": " << states[i]->getCurrentRoom()->getType() << "    " << states[i]->getTime() << endl;
		}
	}
	else {
		cout << "Empty list" << endl;
	}
}

void StateManager::clearStates(){
	for(unsigned int i = 0; i < states.size(); i++){
		delete states[i];
	}
	states.clear();
}

bool StateManager::haveSaves() {
	return states.size() > 0;
}

void StateManager::addRoomList(vector<Space*> rooms){
	this->rooms = rooms;
}

void StateManager::changeWorkingDir() {

chdir("./GameState/");
}

void StateManager::resetWorkingDir() {
	chdir("../");
}
