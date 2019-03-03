#include "StateManager.h"

//Structure of game state save file
// Name: save.001, save.002, save.003, etc

StateManager::StateManager() {
	init();
}

StateManager::~StateManager() {

}

void StateManager::init(){
	changeWorkingDir();
	
	clearStates();
	getSaveFileList();
	if (foundSaveFiles()) {
#ifdef STATE_DEBUG
		cout << "Found " << fileList.size() << " save files." << endl;
		//Found files, print their names
		if(fileList.size() > 0){
			cout << "Files: ";
			for(unsigned int i = 0; i < fileList.size(); i++){
				cout << fileList[i] <<  " ";
			}
		}
		cout << endl;
#endif
		readAllSaves();
	}
	
	newGameState = new GameState();
	resetWorkingDir();
}

bool StateManager::foundSaveFiles() {
	return fileList.size() > 0;
}

bool StateManager::haveSaves() {
	return states.size() > 0;
}

void StateManager::getSaveFileList() {
	fileList.clear();

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
}

//Transfer data from GameState to actual game 
GameState* StateManager::startLoadingGame() {
	string choice;
	int stateNum;

	printStates();

	if (haveSaves()) {
		cout << "Select game save to load: ( " << 1 << "-" << states.size() << " )" << endl;
		getline(cin, choice);
		stateNum = atoi(choice.c_str());
		if ((stateNum > 0) && (stateNum <= (int) states.size()) ) {
			cout << "Loading save " << stateNum << "..." << endl;
			stateNum--; //align with state vector's initial zero offset;
			return states[stateNum];
		}
		else{
			cout << "Selected invalid save!" << endl;
		}
	}
	return NULL;
}

//Reading all save files
void StateManager::readAllSaves() {
	for (unsigned int index = 0; index < fileList.size(); index++) {
		GameState* newState = readSaveFile(fileList[index]);
		if (newState != NULL) {
			addGameState(newState);
		}
		else{ 
			cout << "Error: File " << fileList[index] << " has invalid format!\n"; 
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

	headerKeys[0] = "Time_stamp:";
	headerKeys[1] = "Current_room:";
	headerKeys[2] = "Room_idx:";
	foundHeader[0] = lines[1].find(headerKeys[0]);
	foundHeader[1] = lines[2].find(headerKeys[1]);
	foundHeader[2] = lines[3].find(headerKeys[2]);

	//Didn't find file header
	if ((foundHeader[0] == std::string::npos) || (foundHeader[1] == std::string::npos) ||
		(foundHeader[2] == std::string::npos)){	
		cout << invalidFile << endl;
		delete newState;
		return NULL;		
	}

	//Found it
	else {
		// Save header first 
		string newTime = lines[1].substr(foundHeader[0] + headerKeys[0].length());

		//Adding header info to state object;
		int rIdx, i;
		int numValidRooms = 0;
		bool readSuccess;
		vector<Space*> rooms = newState->getRoomsList();

		sscanf(lines[3].c_str(), "%*s %d ", &rIdx);
		newState->setCurrentRoom(rIdx);
		newState->setTime(newTime);

		line = lines.begin();
		line +=6;

		while(line != lines.end()){
			foundRooms = (*line).find("<Rooms>");
			//Found rooms section in file, start processing room data
			if(foundRooms != std::string::npos){
				for(i = 0; i < (int)rooms.size(); i++){
					readSuccess = readRoom(line, rooms[i]);
					if(readSuccess == false){
#ifdef STATE_DEBUG
						cout << invalidFile << endl;
#endif						
						delete newState;
						return NULL;
					}
					else{
						numValidRooms++;
					}
				}
			}
			else{	//If all rooms weren't read, read state is not valid, so return NULL	
				if(numValidRooms < ((int)rooms.size() - 1)){				
#ifdef STATE_DEBUG
					cout << invalidFile << endl;
#endif
					delete newState;
					return NULL;
				}
				//All states read were valid, so now read player's data
				else{
					readSuccess = readPlayer(line, newState->getPlayer());
					if(readSuccess){
						break;
					}					
					else{
#ifdef STATE_DEBUG
						cout << invalidFile << endl;
#endif						
						delete newState;
						return NULL;
					}
				}
			}
			line++;
		}
	}
	return newState;
}

//Find and extract string parameter from line
string StateManager::readStrValue(vector<string>::iterator& line, string key){
	string strValue;
	size_t foundStr = (*line).find(key);
	if(foundStr != std::string::npos){
		strValue = (*line).substr(foundStr+key.length()+1);	
// #ifdef STATE_DEBUG
// 		cout << "Found string: " << strValue << endl;
// #endif
	}
	else{
// #ifdef STATE_DEBUG
// 		cout << "Didn't find string " << key << ", line: " << *line << endl;
// #endif
	}

	line++;
	return strValue;
}

int StateManager::readInt(vector<string>::iterator& line, string key){
	int intValue = -1;
	if((*line).find(key) != std::string::npos){
		sscanf((*line).c_str(), "%*s %d", &intValue);
#ifdef STATE_DEBUG
		cout << "Found " << key << " " << intValue << endl;
#endif	
	}
	else{
 #ifdef STATE_DEBUG
 		cout << "Didn't find " << key << ", line: " << *line << endl;
 #endif	
	}
	
	line++;
	return intValue;
}

void StateManager::readEndSection(vector<string>::iterator& line, string token){
	size_t foundEnd;
	//int linesRead = 0;
	do{
		foundEnd = (*line).find(token);
		if(foundEnd == std::string::npos){
			line++;
			//linesRead++;
		}
	}while(foundEnd == std::string::npos);
}

bool StateManager::readRoomBools(vector<string>::iterator& line, Space* room, string roomName){
	int readValue = -1;

	//Read base Space class booleans
	readValue = readInt(line, "Locked_door");
	if(readValue != -1){
		if(readValue == 1){
			room->lockDoor();	
		}
	}
	else{ 
		return false;
	}

	readValue = readInt(line, "First_try");
	if(readValue != -1){	
		room->setFirstTry((bool)readValue);	
	}
	else{ 
		return false;	
	}

	readValue = readInt(line, "Colt_gone");
	if(readValue != -1){
		room->setColtGone((bool)readValue);	
	}
	else{ 
		return false;	
	}

	//Read derived Space class booleans
	if(roomName.find("Biology") != std::string::npos){
		readValue = readInt(line, "Plants_eaten");
		if(readValue != -1){
			if(readValue == 1){
				static_cast<Biology*>(room)->setPlantsEaten();	
			}
		}
		else{ 
			return false;	
		}
	}
	if(roomName.find("Chemistry") != std::string::npos){
		readValue = readInt(line, "Hole_visible");
		if(readValue != -1){
			if(readValue == 1){	
				static_cast<Chemistry*>(room)->moveCabinet();	
			}
		}
		else{ 
			return false;	
		}
	}
	if(roomName.find("Cafeteria") != std::string::npos){
		readValue = readInt(line, "VendMachine_used");
		if(readValue != -1){
			if(readValue == 1){
				static_cast<Cafeteria*>(room)->useVendingMachine();	
			}
		}
		else{ 
			return false;	
		}
	}
	if(roomName.find("Literature") != std::string::npos){
		readValue = readInt(line, "Note_visible");
		if(readValue != -1){
			if(readValue == 1){	
				static_cast<Literature*>(room)->inspectDesk();		
			}
		}
		else{ 
			return false;	
		}
	}
	if(roomName.find("Math") != std::string::npos){
		readValue = readInt(line, "Apple_eaten");
		if(readValue != -1){
			if(readValue == 1){
				static_cast<Math*>(room)->eatApple();	
			}
		}
		else{ 
			return false;	
		}
	}
	if(roomName.find("Men's Bathroom") != std::string::npos){
		readValue = readInt(line, "Hole_visible");
		if(readValue != -1){
			if(readValue == 1){	
				static_cast<MensBathroom*>(room)->inspectToilet();	
			}
		}
		else{
			return false;	
		}
	}
	return true;
}

bool StateManager::readRoom(vector<string>::iterator& line, Space* room){

	line++; //Go to tag <Room>;

	bool isValid = true,
		 readBoolValues = false;
	string invalidFile = "Error reading save file! Invalid format";
	string roomName;
	size_t foundStart = (*line).find("<Room>");

	if(foundStart != std::string::npos){
#ifdef STATE_DEBUG
			cout << "======= Found room: " << room->getType() << " =====" << endl;
#endif
			line++;
			roomName = readStrValue(line, "Type:");
			if(roomName.length() == 0){
				isValid = false;
			}
			//Read booleans for Space and derived Space classes
	 		readBoolValues = readRoomBools(line, room, roomName);
			if(!readBoolValues){
				isValid = false;
			}

			//Read inventory
			isValid = readInventory(line, room->getInventory());

			//Read creatures
			isValid = readCreature(line, room->getZombie());

			readEndSection(line, "</Room>");
#ifdef STATE_DEBUG		
				cout << "Found room end: </Room>" << endl;
#endif		
	}
	else{
		//cout << invalidFile << endl;
		isValid = false;
	}
	line++;

	return isValid;	
}

Item* StateManager::readItem(vector<string>::iterator& line){
	/* Example of Item data in save file
	<Item>
	Item 1
	Removable: 0
	Type: Dummy
	Name: toilet
	</Item>
	*/
	// cout << "Begin readItem()" << endl;

	Item* newItem = NULL;
	string itemType;
	line++;	

	if((*line).find("<Item>") != std::string::npos){
		line+=2; //Skip Item # 
		int removable = readInt(line, "Removable");
		if( removable == 1){
			line++; 	//Skip line Type: 
			itemType = readStrValue(line, "Name:");
			newItem = GameState::createItem(itemType);
		}
	}
	//Now read until seeing </Item> tag
	readEndSection(line, "</Item>");

	return newItem;
}

//Add movable items to room inventory
bool StateManager::readInventory(vector<string>::iterator& line, Inventory* inv){
	int size, numItems, i;
	bool isValid = true;
	size_t foundInv, foundSize, foundNumItems;
	vector<Item*> currentItems = inv->getItems();

	foundInv = (*line).find("<Inventory>");	
	if (foundInv != std::string::npos) {
#ifdef STATE_DEBUG
		cout << "Found inventory" << endl;
#endif
		line++;
		if(inv->getInventoryType() == "Player"){
			foundSize = (*line).find("Size:");
			if(foundSize != std::string::npos){
				sscanf((*line).c_str(), "%*s %d ", &size);
#ifdef STATE_DEBUG
				cout << "Found player's inventory size" << endl;
#endif
				if(size > 6){
					static_cast<PlayerInventory*>(inv)->increaseSize();
				}
			}
			else{ isValid = false;}
			line++;
		}
		foundNumItems = (*line).find("Num_items:");
		if (foundNumItems != std::string::npos) {
			sscanf((*line).c_str(), "%*s %d ", &numItems);
#ifdef STATE_DEBUG
			cout << "Found " << numItems << " items" << endl;
#endif
			//Remove all removable items from room inventory,
			// to clear for addition of items from file
			for(i = 0; i < (int)currentItems.size(); i++){
				if(currentItems[i]->isMovable()){
					inv->removeItem(currentItems[i]);
				}
			} 
			//Now read an item from file, then add it to inventory
			for(i = 0; i < numItems; i++){
				Item* newItem = readItem(line);
				if(newItem != NULL){
#ifdef STATE_DEBUG
					cout << "Added " << newItem->getName() <<  " to inventory:" << endl;
#endif
					inv->addItem(newItem);
				}
			}
		}	
		else{ 
			isValid = false; 
		}
	}
	else{ 
		isValid = false;	
	}
	//Now read until seeing </Item> tag
	readEndSection(line, "</Inventory>");

	return isValid;
}

bool StateManager::readCreature(vector<string>::iterator& line, Creature* creature){
	/*
<Creatures>
Num_creatures: 1
<Creature>
Type: Zombie
Name: Zombie
IsAlive: 1
Health: 0
</Creature>
</Creatures>

	*/
	size_t foundStart;
	bool isValid = true;
	int numCreatures, isAlive, health;
	string creatureType;

	line++; 	//go to Creatures line
	foundStart = (*line).find("<Creatures>");

	if(foundStart != std::string::npos){
#ifdef STATE_DEBUG
		cout << "Found <Creatures>" << endl;
#endif
		line++;
		numCreatures = readInt(line, "Num_creatures");
		if(numCreatures != -1){
			if(numCreatures > 0 && creature != NULL){
				foundStart = (*line).find("<Creature>");

				if(foundStart != std::string::npos){
					line +=3;		//go to Type and Name lines
					isAlive = readInt(line, "IsAlive");
					if(isAlive != -1){
						if(isAlive == 0){	//dead creature
							creature->die();			//Make creature die
						}
					}
					else{ 
						isValid = false;
					}
					health = readInt(line, "Health");
					if(health != -1){
						creature->setHealth(health);	//Set creature's health
					}
					else{ 
						isValid = false;
					}
				}
			}
		}
		else{ 
			isValid = false;	
		}
	}
	else{ 
		isValid = false; 
	}
	readEndSection(line, "</Creatures>");

	return isValid;
}

bool StateManager::readPlayer(vector<string>::iterator& line, Player* player){
	/*
	<Player>
	<Inventory>
	Size: 6
	Num_items: 0
	</Inventory>
	<Creatures>
	Num_creatures: 1
	<Creature>
	Type: Player
	Name: Player
	IsAlive: 1
	Health: 100
	</Creature>
	</Creatures>
	</Player>

	*/
	size_t foundStart;
	bool isValid = true;

	line++; 	//go to Player line
	foundStart = (*line).find("<Player>");
	player->getInventory()->setLogLevel(true);	//Silence item additions to player's inventory

	if(foundStart != std::string::npos){
#ifdef STATE_DEBUG
		cout << "Found <Player>" << endl;
#endif
		line++;
		isValid = readInventory(line, player->getInventory());
		isValid = readCreature(line, player->getPlayer());
	}
	else{
		isValid = false;
	}
	readEndSection(line, "</Player>");
#ifdef STATE_DEBUG
		cout << "Found </Player>" << endl;
#endif

	player->getInventory()->setLogLevel(false);
	return isValid;
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

	removeSaveFiles();	

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
	FILE* saveFile = NULL;

	/* Opening file */
	saveFile = fopen(filename.c_str(), "w");

	/* If file was successfully open, write room struct data to file */
	if (saveFile != 0) {
		//fprintf(saveFile, "Number of save files: %d\n", (int) states.size());
		fprintf(saveFile, "Filename: %s\n", filename.c_str());
		fprintf(saveFile, "Time_stamp: %s\n", state->getTime().c_str());
		fprintf(saveFile, "Current_room: %s\n", state->getCurrentRoom()->getType().c_str());
		fprintf(saveFile, "Room_idx: %d\n", state->getRoomIdx());
		fprintf(saveFile, "Steps: %d\n", state->getSteps());
		vector<Space*> rooms = state->getRoomsList();

		fprintf(saveFile, "\n<Rooms>\n");
		for (int i = 0; i < (int)rooms.size(); i++) {
			writeRoom(saveFile, rooms[i]);
			if(i < ((int)rooms.size()-1) ){
				fprintf(saveFile, "\n");
			}		
		}
		fprintf(saveFile, "</Rooms>\n\n");
		writePlayer(saveFile, state->getPlayer());

		fclose(saveFile);
	}
	else {
		printf("Error opening save file %s\n", filename.c_str());
	}
}

void StateManager::writeRoom(FILE* saveFile, Space* room){
	vector<Item*> items = room->getInventory()->getItems();
	Creature* zombie = room->getZombie();
	int numItems = items.size();
	int	j, numZombies = 0;
	// bool doorLocked = room->getDoorLocked();
	fprintf(saveFile, "<Room>\n");
	fprintf(saveFile, "Type: %s\n", room->getType().c_str());

	//Writing Space class booleans
	fprintf(saveFile, "Locked_door: %d\n", (int)room->getDoorLocked());
	fprintf(saveFile, "First_try: %d\n", (int)room->getFirstTry());
	fprintf(saveFile, "Colt_gone: %d\n", (int)room->coltGone());

	//Writing derived room class booleans
	if(room->getType() == "Biology"){
		fprintf(saveFile, "Plants_eaten: %d\n", (int)static_cast<Biology*>(room)->getPlantsEaten());
	}
	if(room->getType() == "Chemistry"){
		fprintf(saveFile, "Hole_visible: %d\n", (int)static_cast<Chemistry*>(room)->getHoleVisible());
	}
	if(room->getType() == "Cafeteria"){
		fprintf(saveFile, "VendMachine_used: %d\n", (int)static_cast<Cafeteria*>(room)->getVendingMachineUsed());
	}
	if(room->getType() == "Literature"){
		fprintf(saveFile, "Note_visible: %d\n", (int)static_cast<Literature*>(room)->getNoteVisible());
	}
	if(room->getType() == "Math"){
		fprintf(saveFile, "Apple_eaten: %d\n", (int)static_cast<Math*>(room)->getAppleEaten());
	}
	if(room->getType() == "Men's Bathroom"){
		fprintf(saveFile, "Hole_visible: %d\n", (int)static_cast<MensBathroom*>(room)->getHoleVisible());
	}

	fprintf(saveFile, "<Inventory>\n");
	fprintf(saveFile, "Num_items: %d\n", numItems);
	for (j = 0; j < numItems; j++) {
		writeItem(saveFile, items[j], j+1);
	}
	fprintf(saveFile, "</Inventory>\n");

	fprintf(saveFile, "<Creatures>\n");
	if(zombie != NULL){
		numZombies = 1;
		fprintf(saveFile, "Num_creatures: %d\n", numZombies);
		writeCreature(saveFile, zombie);
	}
	else{
		fprintf(saveFile, "Num_creatures: %d\n", numZombies);
	}
	fprintf(saveFile, "</Creatures>\n");
	fprintf(saveFile, "</Room>\n");
}

void StateManager::writeItem(FILE* saveFile, Item* item, int count){
	fprintf(saveFile, "<Item>\n");
	fprintf(saveFile, "Item: %d\n", count);
	fprintf(saveFile, "Removable: %d\n", (int)item->isMovable());
	fprintf(saveFile, "Type: %s\n", item->getType().c_str());
	fprintf(saveFile, "Name: %s\n", item->getName().c_str());
	fprintf(saveFile, "</Item>\n");
}

void StateManager::writeCreature(FILE* saveFile, Creature* creature){
	
	fprintf(saveFile, "<Creature>\n");
	// fprintf(saveFile, "Creature %d\n", count);
	fprintf(saveFile, "Type: %s\n", creature->getType().c_str());
	fprintf(saveFile, "Name: %s\n", creature->getType().c_str());
	fprintf(saveFile, "IsAlive: %d\n", (int)creature->isAlive());
	fprintf(saveFile, "Health: %d\n", creature->getHealth());
	fprintf(saveFile, "</Creature>\n");
}

void StateManager::writePlayer(FILE* saveFile, Player* player){
	vector<Item*> items = player->getInventory()->getItems();
	int numItems = items.size();
	Creature* playerCr = player->getPlayer();

	fprintf(saveFile, "<Player>\n");
	fprintf(saveFile, "<Inventory>\n");
	fprintf(saveFile, "Size: %d\n", player->getInventory()->getSize());
	fprintf(saveFile, "Num_items: %d\n", numItems);
	for (int i = 0; i < numItems; i++) {
		writeItem(saveFile, items[i], i+1);
	}
	fprintf(saveFile, "</Inventory>\n");
	fprintf(saveFile, "<Creatures>\n");
	fprintf(saveFile, "Num_creatures: 1\n");
	writeCreature(saveFile, playerCr);
	fprintf(saveFile, "</Creatures>\n");
	fprintf(saveFile, "</Player>\n");
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

void StateManager::removeSaveFiles(){
	changeWorkingDir(); // Navigate to ./GameState/ folder
	getSaveFileList();	// Get latest file list

	//Now delete all of them
	for(int i = 0; i < (int)fileList.size(); i++){
		int result = remove(fileList[i].c_str());
		if(result != 0){
			string error = "Deleting " + fileList[i] +" error:";
			perror(error.c_str());
		}
	}
	resetWorkingDir();
}

void StateManager::removeSaves(){
	if(states.size() > 0){
		cout << "Clearing all game saves..." << endl;
		clearStates();
		removeSaveFiles();			//Now remove any existing save files for a clean slate
	}
	else{
		cout << "No game saves to clear!" << endl;
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
	cout << " === GAME SAVES ===" << endl;
	if (haveSaves()) {
		cout << "#      Room        Date" << endl;
		for (unsigned int i = 0; i < states.size(); i++) {
			cout <<  (i + 1) << ": " << states[i]->getCurrentRoom()->getType() << "    " << states[i]->getTime() << endl;
		}
	}
	else {
		cout << " Empty!" << endl;
	}
}

void StateManager::clearStates(){
	for(unsigned int i = 0; i < states.size(); i++){
		delete states[i];
	}
	states.clear();
}

void StateManager::changeWorkingDir() {
chdir("./GameState/");
}

void StateManager::resetWorkingDir() {
	chdir("../");
}

GameState* StateManager::getNewGameState(){
	return newGameState;
}
