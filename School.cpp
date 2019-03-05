#include "School.h"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\x1B[0m"


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

bool isInt(string input)
{
	bool status;

	if (input == "")
		return false;

	//if the first element is a negative sign, the rest of the string
	//can be checked
	if (input[0] == '-')
	{
		for (unsigned int index = 1; index < input.size(); index++)
		{
			if (isdigit(input[index]))
				status = true;

			//if anything other than a number is encountered
			else
				return false;
		}
	}

	//if the first element is not a negative sign
	else
	{
		for (unsigned int index = 0; index < input.size(); index++)
		{
			if (isdigit(input[index]))
				status = true;

			//if anything other than a number is encountered
			else
				return false;
		}
	}

	return status;
}

int getInt()
{
	//user input is stored as string
	string input;
	//integer variable to store the returned unsigned integer
	int any;

	do
	{
		//getline will get every character from the string
		getline(cin, input);

		//the following code taken from 
		//https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		//end of copied code. this code will remove
		//all whitespace from the string

		//if the string is found NOT to be an unsigned integer
		if (!(isInt(input)))
			cout << KRED "Error.  Please enter an integer." RESET << endl;

	} while (!(isInt(input)));

	//converts string to integer
	any = atoi(input.c_str());

	return any;
}

void School::beginGame()
{
	int menuChoice;
	GameState* stateToLoad = NULL;

	cout << KCYN "			----------- ZOMBIE MADDNESS --------------" << endl;
	cout << "			A game by Jeremy Einhorn, Michael Johnson, and Artem Slivka" << endl << endl;
	cout << "Welcome to Zombie Maddness, the text-based survival game where going to school becomes a little more..." << endl;
	cout << endl << endl << "Interesting." << endl << endl;

	cout << "The objective is to get through the school while efficiently balancing your inventory" << endl;
	cout << "in order to get to the end where you will use those items to defeat your biggest foe!" << endl << endl;
	cout << "It is critical you save game often.  If you do not save and you die in game or totally quit the program," << endl;
	cout << "you will be forced to start a new game entirely." << endl << endl;
	cout << "As a final reminder, remember to be smart with your invetory management!" << endl;
	cout << "Just carrying only weapons or only picking up the few first items you come across" << endl;
	cout << "may bode really badly for you later in the game!" << endl << endl;


	while (menuChoice != 3)
	{
		cout << KCYN "Please enter the number corresponding to your option" << endl;
		cout << endl;
		cout << "1: New Game" << endl;
		cout << "2: Load Game" << endl;
		cout << "3: Quit" << endl;
		cout << endl;
		
		cout << "Choice: " RESET;
		menuChoice = getInt();

		while (menuChoice < 1 || menuChoice > 3)
		{
			cout << KRED "Invalid choice. Please enter the correct corresponding number to your choice" RESET << endl;
			cout << KCYN "Choice: " RESET;
			menuChoice = getInt();
		}

		switch (menuChoice)
		{
			case 1:
				loadState(stateManager->getNewGameState(), false);
				//setupPlayer();
				playGame();
				break;

			case 2:
				stateToLoad = stateManager->startLoadingGame();
				loadState(stateToLoad, false);
				if(stateToLoad != NULL){	//If selected a valid save, play saved game
					playGame();
				}
				break;

			case 3:
				exit(0);

			default:
				exit(0);
		}
	}
}

bool isGameOver(bool isGameWon, Creature *player)
{
	if (isGameWon)
		return true;
	
	else if (!player->isAlive())
		return true;

	return false;
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
		processCommand(parser, choice);

		//if (commandVect.size() != 0) {
		//	currentRoom->menu(commandVect);
		//}
		
	} while (choice != "q" && choice != "quit" && choice != "exit" && !isGameOver(isGameWon, player->getPlayer()));

	return 0;
}

void School::processCommand(CmdParser* parser, string cmd) {
	if (cmd.length() == 0) { return; }	//Empty command

	parser->setCommand(cmd);
	CmdWord* foundCmd = 0;

	//Convert input to lower case to make parsing easier
	transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

	//Generate cmd vector, moving words into separate elements
	vector<string> cmdVector = parser->createCmdVector(cmd);
	//Search for command in cmdList
	//Command with 2 words or more
	if (cmdVector.size() > 1) {
		//Search for valid 2-word command
		string cmd2words = cmdVector[0] + " " + cmdVector[1];
		foundCmd = parser->getCmdList()->findCommand(cmd2words);
		//Didn't find valid 2-word command, search for 1-word command
		if (foundCmd == 0) {
			foundCmd = parser->getCmdList()->findCommand(cmdVector[0]);
		}
	}

	// Command with 1 word only
	else {
		foundCmd = parser->getCmdList()->findCommand(cmdVector[0]);
	}

	parser->addCmdToHistory(cmd);

	if (foundCmd != 0) {	//Found a matching command from pre-set command list
		if (foundCmd->getType() == "help") {
			//Print available commands
			parser->getCmdList()->printListDetailed();
		}
		//Syntax: go <direction> 
		if (foundCmd->getType() == "go") {
			if (currentRoom->getZombie() && currentRoom->getZombie()->isAlive()) {
				cout << KRED "# You cannot leave until the zombie is destroyed!" RESET << endl;
				return;
			}
			if(currentRoom->getType() == "Men's Bathroom"){
				if (static_cast<MensBathroom*>(currentRoom)->getHoleVisible() == true) {
					if(cmd == "go hole") {
						moveRooms(cmdVector, "south");
						return;
					}
				}
				else if(static_cast<MensBathroom*>(currentRoom)->getHoleVisible() == false){
					if(cmd == "go south" || cmd == "south"){
						cout << "# You can't go that direction." << endl;
						return;
					}
				}
            		}
	
			if(currentRoom->getType() == "Second Floor Hallway"){
				if ((wb->getDoorLocked() == true) && (cmd == "go east" || cmd == "east" || cmd == "go women's bathroom" || cmd =="women's bathroom" )
					  && (currentRoom->getEast() != NULL)) {
					Space *tempRoom;
					tempRoom = currentRoom->getEast();
						if (tempRoom->getType() == "Women's Bathroom") {
							cout << "# The door is locked from the inside and can't be picked or unlocked from the outside." << endl;
							return;
						}
				}
			
				if ((infr->getDoorLocked() == true) && ( cmd == "go west" || cmd == "west" ) && (currentRoom->getWest() != NULL)) {
					Space *tempRoom;
					tempRoom = currentRoom->getWest();
						if (tempRoom->getType() == "Infirmary") {
							cout << "# The door is locked from the inside and can't be picked or unlocked from the outside." << endl;
							return;
						}
				}
			}
			
			if((currentRoom->getType() == "Women's Bathroom") && ( cmd == "go west" || cmd == "west" )) {
				currentRoom->unlockDoor();
      }

			if(currentRoom->getType() == "Gymnasium First Floor"){
				if( cmd == "south" || cmd == "go south" || cmd == "go football field" || cmd == "football field"){
					if(fb->getDoorLocked() == true){
						cout << "# The door is locked from the inside and can't be picked or unlocked from the outside." << endl;
						return;
					}
				}	
			}

			if(currentRoom->getType() == "Chemistry"){
				if (static_cast<Chemistry*>(currentRoom)->getHoleVisible() == true) {
					if(cmd == "go hole" || cmd == "go south" || cmd == "south") {
						moveRooms(cmdVector, "south");
						return;
					}
				}
				else if(static_cast<Chemistry*>(currentRoom)->getHoleVisible() == false){
					if(cmd == "go hole" || cmd == "go south" || cmd == "south") {
						cout << "# You can't go that direction." << endl;
						return;
					}
				}
      }	
			
			if((currentRoom->getType() == "Infirmary") && (cmd == "go east")) {
				currentRoom->unlockDoor();
      }

			moveRooms(cmdVector, cmd);
		}
		if (foundCmd->getType() == "where") {
				cout << "###################################################" << endl;
				cout << "# You are in the " << currentRoom->getType() << endl;
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
				currentRoom->printDirections();
			}
		}
		if (foundCmd->getType() == "look") {		
			if (cmdVector.size() == 1) {		//Look command
				currentRoom->printIntro();
			}
		}
		if (foundCmd->getType() == "room inventory") {
			currentRoom->getInventory()->printInventory();
		}
		if (foundCmd->getType() == "inventory") { 
			player->getInventory()->printInventory();
		}
		if (foundCmd->getType() == "look at") {
			string item = parser->extractArgument(cmdVector, foundCmd->getType());
			player->lookAtItems(item);

			if(currentRoom->getType() == "Men's Bathroom") {
				if(item == "toilet") {
					static_cast<MensBathroom*>(currentRoom)->inspectToilet();
				}
			}

			if(currentRoom->getType() == "History") {
				if(item == "george washington bust") {
					static_cast<History*>(currentRoom)->inspectBust();
				}
			}

			if(currentRoom->getType() == "Literature") {
				if(item == "desk") {
					static_cast<Literature*>(currentRoom)->inspectDesk();
				}
			}

			if(currentRoom->getType() == "Chemistry") {
				if(item == "cabinet") {
					static_cast<Chemistry*>(currentRoom)->inspectCabinet();
				}
			}
		}
		if (foundCmd->getType() == "take") {
			string item = parser->extractArgument(cmdVector, foundCmd->getType());

			//Try to select item from room's inventory
			Item* selectedItem = player->getRoomInventory()->selectItem(item);
			if(selectedItem != NULL){
				//Found item, dropping it
				player->takeItem(selectedItem);
			}
		}
		if (foundCmd->getType() == "drop") {
			string item = parser->extractArgument(cmdVector, foundCmd->getType());
			//Try to select item from player's inventory
			Item* selectedItem = player->getInventory()->selectItem(item);	
			if(selectedItem != NULL){
				//Found item, dropping it
				player->dropItem(selectedItem);
			}
		}
		if (foundCmd->getType() == "use") {
			string item = parser->extractArgument(cmdVector, foundCmd->getType());
			cout << "#\n# Using item" << endl;
			
			if(currentRoom->getType() == "Chemistry") {
				if(item == "ladder") {
					moveRooms(cmdVector, "south");
					return;
				}
			}
			
			if(currentRoom->getType() == "Library") {
				if(item == "ladder") {
					static_cast<Library*>(currentRoom)->useLadder();
				}
			}
			
			if(currentRoom->getType() == "Front Office") {
				if(item == "PA system") {
					static_cast<FrontOffice*>(currentRoom)->usePA();
				}
			}
			
			if(currentRoom->getType() == "Cafeteria") {
				if(item == "vending machine" && static_cast<Cafeteria*>(currentRoom)->getVendingMachineUsed() == false) {
					static_cast<Cafeteria*>(currentRoom)->useVendingMachine();
				}
			}
			
			if(currentRoom->getType() == "Women's Bathroom"){
				if(item == "bookbag") {
					doItemAction(foundCmd->getType(), cmdVector);
					static_cast<WomensBathroom*>(currentRoom)->increaseBagSize();
					return;
				}
			}

			doItemAction(foundCmd->getType(), cmdVector);
		}
		if (foundCmd->getType() == "throw") {
			string item = parser->extractArgument(cmdVector, foundCmd->getType());
			
			if (currentRoom->getType() == "Cafeteria") {
				if(item == "food") {
					static_cast<Cafeteria*>(currentRoom)->throwFood();
					return;
				}
			}

			cout << "#\n# Throwing item" << endl;
			doItemAction(foundCmd->getType(), cmdVector);		
		}
		if (foundCmd->getType() == "push") {
			string item = parser->extractArgument(cmdVector, foundCmd->getType());
			cout << "#\n# Pushing item" << endl;
			
			if(currentRoom->getType() == "Chemistry") {
				if(item == "cabinet") {
					static_cast<Chemistry*>(currentRoom)->moveCabinet();
				}
			}
			doItemAction(foundCmd->getType(), cmdVector);
		}
		if (foundCmd->getType() == "read") {
			cout << "#\n# Reading item" << endl;
			doItemAction(foundCmd->getType(), cmdVector);
		}
		if (foundCmd->getType() == "wear") {
			cout << "#\n# Wearing item" << endl;
			doItemAction(foundCmd->getType(), cmdVector);
		}
		if (foundCmd->getType() == "eat") {
			string item = parser->extractArgument(cmdVector, foundCmd->getType());
			cout << "#\n# Eating item" << endl;
			
			if (currentRoom->getType() == "Biology") {
				if(item == "plants" && static_cast<Biology*>(currentRoom)->getPlantsEaten() == false) {
					srand(time(NULL));
					int randNum = (rand() % 2) + 1;

					if(randNum == 1) {
						(player->getPlayer())->setHealth((player->getPlayer())->getHealth() - 30);
						doItemAction(foundCmd->getType(), cmdVector);
						cout << "#\n# You took the wrong ones and your health was damaged by 30 points.\n";
						static_cast<Biology*>(currentRoom)->setPlantsEaten();
						return;
					}
					else {
						(player->getPlayer())->setHealth((player->getPlayer())->getHealth() + 20);
						doItemAction(foundCmd->getType(), cmdVector);
						cout << "#\n# You took the right one and your health was increased by 20 points.\n";
						static_cast<Biology*>(currentRoom)->setPlantsEaten();
						return;
					}
				}
				else {
					cout << "# You have already eaten the plants." << endl;
					return;
				}
			}
			
			if (currentRoom->getType() == "Math") {
				if(item == "apple" && static_cast<Math*>(currentRoom)->getAppleEaten() == false) {
					static_cast<Math*>(currentRoom)->eatApple();
				}
				else {
					cout << "# You've already eaten the apple." << endl;
					return;
				}
			}
			
			if (currentRoom->getType() == "Cafeteria") {
				if(item == "snack" && currentRoom->getInventory()->findItem("snack") != NULL) {
					doItemAction(foundCmd->getType(), cmdVector);
					static_cast<Cafeteria*>(currentRoom)->eatSnack();
					return;
				}
				else if(item == "snack" && currentRoom->getInventory()->findItem("snack") == NULL){
					cout << "# There are no snacks in the machine" << endl;
					return;
				}
			}
			
			doItemAction(foundCmd->getType(), cmdVector);
		}
		if (foundCmd->getType() == "cut") {
			string item = parser->extractArgument(cmdVector, foundCmd->getType());
			
			cout << "\nCutting something with a weapon?" << endl;
			if (currentRoom->getType() == "Gymnasium Second Floor") {
				if(item == "ropes") {
					doItemAction(foundCmd->getType(), cmdVector);
					static_cast<GymnasiumFloor2*>(currentRoom)->cutRopes();
					return;
				}
			}
			doItemAction(foundCmd->getType(), cmdVector);
		}
		if (foundCmd->getType() == "attack") {
			if(currentRoom->getType() != "Football Field"){
				player->attackEnemy();
			}
			else{
				startFinalFight();
			}
		}
		if (foundCmd->getType() == "block") {
			player->defend();
		}
		if (foundCmd->getType() == "open") {
			cout << "#\n# Opening..." << endl;

			//Opening rooms
			if(currentRoom->getType() == "Gymnasium First Floor"){
				if(cmd == "open Football Field" || cmd == "open football field"){
					//Try to select item from player's inventory
					Item* selectedItem = player->getInventory()->selectItem("key");	
					if(selectedItem != NULL){
						cout << "Opening/unlocking door to Football room" << endl;
						fb->unlockDoor();
					}
					else{
						cout << "Didn't find key in player's inventory, cannot open door!" << endl;
					}
				}
				return;
			}
			//Opening items
			doItemAction(foundCmd->getType(), cmdVector);
		}
		if (foundCmd->getType() == "stats") { //stub
			player->printStats();
		}
		if (foundCmd->getType() == "savegame") { //stub
			GameState* currentState = createState();
			stateManager->startSavingGame(currentState);
		}
		if (foundCmd->getType() == "loadgame") { //stub 
			GameState* stateToLoad = stateManager->startLoadingGame();
			loadState(stateToLoad, true);
		}
		if (foundCmd->getType() == "cleargames") { //stub 
			stateManager->removeSaves();
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
		bool moved = moveRooms(cmdVector, cmd);
		if(!moved){	//Didn't move rooms
			cout << "# Invalid command!" << endl;
		}
	}
}

void School::doItemAction(string cmdType, vector<string> cmdVector){
	string item = parser->extractArgument(cmdVector, cmdType);

	//Try to select item from room and player's inventory
	Item* selectedItem = player->selectItem(item);	
	if(selectedItem != NULL){ 	//Found item, dropping it
		if(cmdType == "use"){
			player->useItem(selectedItem);
		}
		else if (cmdType == "throw") {
			selectedItem->throwItem();
		}
		else if (cmdType == "push") {
			selectedItem->pushItem();
		}
		else if (cmdType == "read") {
			selectedItem->readItem();	
		}
		else if (cmdType == "wear") {
			selectedItem->wearItem();
		}
		else if (cmdType == "eat") {
			selectedItem->eatItem();
			if(selectedItem->isMovable() == true) {
				player->useItem(selectedItem);
			}
		}
		else if (cmdType == "cut") {
			selectedItem->cutItem();
		}
		else if (cmdType == "open") {
			selectedItem->openItem();
		}
	}
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
		if (nextRoom->getType() == "Chemistry")
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
		currentRoom->printExitDesc();
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
		currentRoom->printExitDesc();
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
		currentRoom->printExitDesc();
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
		currentRoom->printExitDesc();
		currentRoom = currentRoom->getSouth();
		return currentRoom;
	}
}

bool School::moveRooms(vector<string> cmdArray, string cmd){
	Space* nextRoom = currentRoom;

	if (!player->getPlayer()->isAlive())
		return true;

	// go <direction> or <direction> command
	if (cmd == "north" || cmd == "go north") {
		moveNorth();
		player->movetoRoom(currentRoom);
		cout << "###################################################" << endl;
		cout << "# You are in the " << currentRoom->getType() << endl;
		currentRoom->printIntro();
	}
	else if (cmd == "west" || cmd == "go west") {
		moveWest();
		player->movetoRoom(currentRoom);
		cout << "###################################################" << endl;
		cout << "# You are in the " << currentRoom->getType() << endl;
		currentRoom->printIntro();
	}
	else if (cmd == "south" || cmd == "go south") {
		moveSouth();
		player->movetoRoom(currentRoom);
		cout << "###################################################" << endl;
		cout << "# You are in the " << currentRoom->getType() << endl;
		currentRoom->printIntro();
	}
	else if (cmd == "east" || cmd == "go east") {	
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

	if(nextRoom != currentRoom){	//Player moved rooms
		return true;
	}
	return false;	//Player didn't move rooms
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

int School::getRoomIdx(Space* room){
	for (int i = 0; i < (int)rooms.size(); i++) {
		if(rooms[i] == room){
			return i;
		}
	}
	return -1;
}

GameState* School::createState(){
	GameState* newState = new GameState();

	newState->updateTime();	
	newState->setCurrentRoom(getRoomIdx(currentRoom));
	vector<Space*> stateRooms = newState->getRoomsList();
	newState->copyRooms(stateRooms, this->rooms);
	newState->copyPlayer(newState->getPlayer(), this->player);

	// newState->compareRooms(stateRooms, this->rooms);
	// newState->comparePlayer(newState->getPlayer(), this->player);

	newState->setSteps(steps);

	return newState;
}

void School::loadState(GameState* loadState, bool printIntro = true){
	if(loadState == NULL) { return; }

	//Set current room by index
	int curRoomIdx = loadState->getRoomIdx();	
	currentRoom = rooms[curRoomIdx];

	vector<Space*> stateRooms = loadState->getRoomsList();
	loadState->copyRooms(this->rooms, stateRooms);
	loadState->copyPlayer(this->player, loadState->getPlayer());

	// loadState->compareRooms(this->rooms, stateRooms);
	// loadState->comparePlayer(this->player, loadState->getPlayer());

	steps = loadState->getSteps();		//Set steps

	//Loading finished
	player->movetoRoom(currentRoom);
	if(printIntro)
	{
		cout << "###################################################" << endl;
		cout << "# You are in the " << currentRoom->getType() << endl;
		currentRoom->printIntro();
	}
}

void School::startFinalFight(){

		Zombie* boss = currentRoom->getZombie();

		while (player->getPlayer()->isAlive())
		{
			if (!player->getInventory()->hasWeapon())
			{
				cout << KRED "# Oh no, you ran out of weapons! Scott got you!" RESET << endl << endl;
				player->getPlayer()->die();
				break;
			}
			
			player->attackEnemy();

			if (!boss->isAlive())
			{
				cout << "# DOWN GOES SCOTT!" << endl << endl;
				isGameWon = true;
				break;
			}

			boss->attackEnemy(player->getPlayer());
		}

		printFinalGameState();
}

void School::printFinalGameState(){
		if (!player->getPlayer()->isAlive())
			cout << KRED "You died, game over!" RESET << endl << endl;
		
		else
			cout << KGRN "Victory is yours!  Thanks for playing a great game!" RESET << endl << endl;

		Zombie* zombie = currentRoom->getZombie();
		if(zombie != NULL){
			cout << "Printing final stats..." << endl;
			player->printStats();
			zombie->printStats();
		}
}

