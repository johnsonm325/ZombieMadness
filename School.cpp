#include "School.h"


School::School()
{
	mb = new MensBathroom();
	wb = new WomensBathroom(player->getInventory());
	sfh1 = new SecondFloorHallway();
	sfh2 = new SecondFloorHallway();
	sfh3 = new SecondFloorHallway();
	sfh4 = new SecondFloorHallway();
	hist = new History();
	lit = new Literature();
	infr = new Infirmary();
	lr = new LockerRoom();
	gym2 = new GymnasiumFloor2();
	gym1 = new GymnasiumFloor1();
	fb = new Football();
	ffh1 = new FirstFloorHallway();
	ffh2 = new FirstFloorHallway();
	ffh3 = new FirstFloorHallway();
	ffh4 = new FirstFloorHallway();
	cafe = new Cafeteria();
	chem = new Chemistry();
	cs = new ComputerScience();
	bio = new Biology();
	math = new Math();
	libr = new Library();
	fl = new FrontLobby();
	fo = new FrontOffice();
	prin = new PrincipalsOffice();

	connectRooms();
	createRoomsList();

	stateManager->addRoomList(rooms);
	stateManager->init();
}

School::~School()
{
	delete mb;
	delete wb;
	delete sfh1;
	delete sfh2;
	delete sfh3;
	delete sfh4;
	delete hist;
	delete lit;
	delete infr;
	delete lr;
	delete gym2;
	delete gym1;
	delete fb;
	delete ffh1;
	delete ffh2;
	delete ffh3;
	delete ffh4;
	delete cafe;
	delete chem;
	delete cs;
	delete bio;
	delete math;
	delete libr;
	delete fl;
	delete fo;
	delete prin;
	
}

void School::beginGame()
{
	addItemsToRooms();
	setupPlayer();

	playGame();
}

int School::playGame()
{
	cout << "###################################################" << endl;
	cout << "# You are in the " << currentRoom->getType() << endl;
	cout << "#" << endl;
	currentRoom->printIntro();
	do 
	{
		cout << "#\n# Please enter choice: ";
		getline(cin, choice);
		cout << "#" << endl;
		commandVect = processCommand(parser, choice);

		if (commandVect.size() != 0) {
			currentRoom->menu(commandVect);
		}
		
	} while (choice != "q" && choice != "quit" && choice !="exit");

	return 0;
}

vector<string> School::processCommand(CmdParser* parser, string cmd) {
	vector<string> emptyVect;
	if (cmd.length() == 0) { return emptyVect; }	//Empty command

	parser->setCommand(cmd);
	CmdWord* foundCmd = 0;

	//Convert input to lower case to make parsing easier
	//transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

	//Generate cmd array, moving words into separate elements
	vector<string> cmdArray = parser->generateCmdArray(cmd);
	//Search for command in cmdList
	//Command with 2 words or more
	if (cmdArray.size() > 1) {
		//Search for valid 2-word command
		string cmd2words = cmdArray[0] + " " + cmdArray[1];
		foundCmd = parser->getCmdList()->findCommand(cmd2words);
		//Didn't find valid 2-word command, search for 1-word command
		if (foundCmd == 0) {
			foundCmd = parser->getCmdList()->findCommand(cmdArray[0]);
		}
	}

	// Command with 1 word only
	else {
		foundCmd = parser->getCmdList()->findCommand(cmdArray[0]);
	}

	parser->addCmdToHistory(cmd);

	if (foundCmd != 0) {	//Found a matching command from pre-set command list
		if (foundCmd->getType() == "help") {
			//Print available commands
			parser->getCmdList()->printListDetailed();
		}
		if (foundCmd->getType() == "inventory") { 
			player->getInventory()->printInventory();
		}
		//Syntax: go <direction> 
		if (foundCmd->getType() == "go") {		
			moveRooms(cmdArray, cmd);
		}
		if (foundCmd->getType() == "dir") {
			if (cmd == "w") {
				currentRoom->printDirection(currentRoom->getNorth());
			}
			else if (cmd == "a") {
				currentRoom->printDirection(currentRoom->getWest());
			}
			else if (cmd == "s") {
				currentRoom->printDirection(currentRoom->getSouth());
			}
			else if (cmd == "d") {
				currentRoom->printDirection(currentRoom->getEast());
			}
			else if (cmd == "dir") {
				//to be implemented
			}
		}

		if (foundCmd->getType() == "look") {		
			if (cmdArray.size() == 1) {		//Look command
				currentRoom->printIntro();
			}
		}
		if (foundCmd->getType() == "room inventory") {
			currentRoom->getInventory()->printInventory();
		}
		if (foundCmd->getType() == "look at") {
			string item = parser->extractArgument(cmdArray, foundCmd->getType());
			player->lookAtItems(item);
		}
		if (foundCmd->getType() == "take") {
			string item = parser->extractArgument(cmdArray, foundCmd->getType());

			//Try to select item from room's inventory
			Item* selectedItem = player->getRoomInventory()->selectItem(item);
			if(selectedItem != NULL){
				//Found item, dropping it
				player->takeItem(selectedItem);
			}
		}
		if (foundCmd->getType() == "drop") {
			string item = parser->extractArgument(cmdArray, foundCmd->getType());
			//Try to select item from player's inventory
			Item* selectedItem = player->getInventory()->selectItem(item);	
			if(selectedItem != NULL){
				//Found item, dropping it
				player->dropItem(selectedItem);
			}
		}
		if (foundCmd->getType() == "savegame") { //stub
			GameState* currentState = createState();
			stateManager->promptToSaveGame(currentState);
		}
		if (foundCmd->getType() == "loadgame") { //stub 
			GameState* stateToLoad = stateManager->promptToLoadGame();
			loadState(stateToLoad);
		}
		if (foundCmd->getType() == "quit") { //stub 
			cout << "\nExiting game...\n";
		}
		if (foundCmd->getType() == "debug") {
			parser->printCmdHistory();
		}
	}
	// Else, go to room name without prefix go -> <room>.
	// Ex: cmd = women's bathroom
	else {
		bool moved = moveRooms(cmdArray, cmd);
		if(!moved){	//Didn't move rooms
			//cout << "Invalid command!" << endl;
			return cmdArray;
		}
	}

	return emptyVect;
}

void School::connectRooms() {
	addRoom('s', wb, mb);
	addRoom('w', sfh1, mb);
	addRoom('w', sfh2, wb);
	addRoom('s', sfh2, sfh1);
	addRoom('w', hist, sfh3);
	addRoom('e', lit, sfh3);
	addRoom('s', sfh3, sfh2);
	addRoom('s', lr, lit);
	addRoom('w', infr, sfh4);
	addRoom('e', lr, sfh4);
	addRoom('s', sfh4, sfh3);
	addRoom('s', chem, infr);
	addRoom('s', gym2, lr);
	addRoom('s', ffh4, sfh4);
	addRoom('s', sfh4, ffh4);
	addRoom('w', gym1, gym2);
	addRoom('s', fb, gym1);
	addRoom('w', ffh4, gym1);
	addRoom('w', cafe, ffh4);
	addRoom('n', ffh3, ffh4);
	addRoom('e', cs, ffh3);
	addRoom('w', chem, ffh3);
	addRoom('n', bio, chem);
	addRoom('n', ffh2, ffh3);
	addRoom('w', bio, ffh2);
	addRoom('e', math, ffh2);
	addRoom('n', libr, bio);
	addRoom('n', fl, math);
	addRoom('n', ffh1, ffh2);
	addRoom('w', libr, ffh1);
	addRoom('e', fl, ffh1);
	addRoom('e', fo, fl);
	addRoom('e', prin, fo);

	this->currentRoom = mb;
}

void School::addRoom(char direction, Space *nextRoom, Space *prevRoom)
{	
	if (direction == 'e')
	{
		prevRoom->setEast(nextRoom);
		nextRoom->setWest(prevRoom);
	}

	else if (direction == 'w')
	{
		prevRoom->setWest(nextRoom);
		nextRoom->setEast(prevRoom);
	}

	else if (direction == 'n')
	{
		prevRoom->setNorth(nextRoom);
		nextRoom->setSouth(prevRoom);
	}

	else if (direction == 's')
	{
		// to set the non-standard joining of chemistry and infirmary rooms
		if (prevRoom->getType() == "chem")
		{
			prevRoom->setSouth(nextRoom);
			nextRoom->setSouth(prevRoom);
		}
		else
		{
			prevRoom->setSouth(nextRoom);
			nextRoom->setNorth(prevRoom);
		}
	}
}

Space* School::getCurrentRoom() {
	return currentRoom;
}

Space *School::moveEast()
{
	if (currentRoom->getEast() == NULL)
	{
		cout << "# move east, You can't go that direction." << endl;
		return NULL;
	}
	else
	{
		currentRoom = currentRoom->getEast();
		return currentRoom;
	}
}

Space *School::moveWest()
{
	if (currentRoom->getWest() == NULL)
	{
		cout << "# move west, You can't go that direction." << endl;
		return NULL;
	}
	else
	{
		currentRoom = currentRoom->getWest();
		return currentRoom;
	}
}

Space *School::moveNorth()
{
	if (currentRoom->getNorth() == NULL)
	{
		cout << "# move north, You can't go that direction." << endl;
		return NULL;
	}
	else
	{
		currentRoom = currentRoom->getNorth();
		return currentRoom;
	}
}

Space *School::moveSouth()
{
	if (currentRoom->getSouth() == NULL)
	{
		cout << "# move south, You can't go that direction." << endl;
		return NULL;
	}
	else
	{
		currentRoom = currentRoom->getSouth();
		return currentRoom;
	}
}
bool School::moveRooms(vector<string> cmdArray, string cmd){
	Space* nextRoom = currentRoom;

	// go <direction> or <direction> command
	if (cmd == "north" || cmd == "go north" || cmd == "i") {
		moveNorth();
		player->movetoRoom(currentRoom);
		cout << "###################################################" << endl;
		cout << "# You are in the " << currentRoom->getType() << endl;
		currentRoom->printIntro();
	}
	else if (cmd == "west" || cmd == "go west" || cmd == "j") {
		moveWest();
		player->movetoRoom(currentRoom);
		cout << "###################################################" << endl;
		cout << "# You are in the " << currentRoom->getType() << endl;
		currentRoom->printIntro();
	}
	else if (cmd == "south" || cmd == "go south" || cmd == "k") {
		moveSouth();
		player->movetoRoom(currentRoom);
		cout << "###################################################" << endl;
		cout << "# You are in the " << currentRoom->getType() << endl;
		currentRoom->printIntro();
	}
	else if (cmd == "east" || cmd == "go east" || cmd == "l") {	
		moveEast();
		player->movetoRoom(currentRoom);
		cout << "###################################################" << endl;
		cout << "# You are in the " << currentRoom->getType() << endl;
		currentRoom->printIntro();
	}
	else{	// go <room> command
		string roomName = parser->extractArgument(cmdArray, "go");
		Space* adjacentRoom = currentRoom->findAdjRoom(roomName);
		if(adjacentRoom != NULL){
			if(adjacentRoom == currentRoom->getNorth()){
				moveNorth();
				player->movetoRoom(currentRoom);
				cout << "###################################################" << endl;
				cout << "# You are in the " << currentRoom->getType() << endl;
				currentRoom->printIntro();
			}
			else if(adjacentRoom == currentRoom->getWest()){
				moveWest();
				player->movetoRoom(currentRoom);
				cout << "###################################################" << endl;
				cout << "# You are in the " << currentRoom->getType() << endl;
				currentRoom->printIntro();
			}
			else if(adjacentRoom == currentRoom->getSouth()){
				moveSouth();
				player->movetoRoom(currentRoom);
				cout << "###################################################" << endl;
				cout << "# You are in the " << currentRoom->getType() << endl;
				currentRoom->printIntro();
			}
			else if(adjacentRoom == currentRoom->getEast()){
				moveEast();
				player->movetoRoom(currentRoom);
				cout << "###################################################" << endl;
				cout << "# You are in the " << currentRoom->getType() << endl;
				currentRoom->printIntro();
			}
			else{
				cout << "Invalid room name!" << endl;
			}
		}
	}

	if(nextRoom != currentRoom){
		return true;
	}
	return false;
}

void School::addItemsToRooms(){
	mb->getInventory()->addItem(new BaseballBat());
	mb->getInventory()->addItem(new BaseballBat());
	wb->getInventory()->addItem(new Paperclip());
}

void School::addSteps(int newSteps){
	steps +=newSteps;
}

void School::createRoomsList() {

	addRoomToList(mb);
	addRoomToList(wb);
	addRoomToList(cafe);
	addRoomToList(libr);
	addRoomToList(sfh1);
	addRoomToList(sfh2);
	addRoomToList(sfh3);
	addRoomToList(sfh4);
	addRoomToList(hist);
	addRoomToList(lit);
	addRoomToList(chem);
	addRoomToList(cs);
	addRoomToList(bio);
	addRoomToList(math);
	addRoomToList(infr);
	addRoomToList(lr);
	addRoomToList(gym1);
	addRoomToList(gym2);
	addRoomToList(fb);
	addRoomToList(ffh1);
	addRoomToList(ffh2);
	addRoomToList(ffh3);
	addRoomToList(ffh4);
	addRoomToList(fl);
	addRoomToList(fo);
	addRoomToList(prin);

	copyRoomsListToSpace();
}

void School::addRoomToList(Space* room) {
	rooms.push_back(room);
}

void School::copyRoomsListToSpace() {
	for (unsigned int i = 0; i < rooms.size(); i++) {
		rooms[i]->addRoomsListToSpace(rooms);
	}
}

vector<Space*> School::getRoomsList() {
	return rooms;
}

void School::setupPlayer(){

	player->clearInventory();
	player->movetoRoom(currentRoom);
}

GameState* School::createState(){
	GameState* newState = new GameState();

	newState->updateTime();
	newState->setRooms(getRoomsList());
	newState->setCurrentRoom(getCurrentRoom());
	newState->setSteps(steps);
	
	return newState;
}

void School::loadState(GameState* stateToLoad){
	if(stateToLoad == NULL) { return; }
	currentRoom = stateToLoad->getCurrentRoom();
	steps = stateToLoad->getSteps();
		
}