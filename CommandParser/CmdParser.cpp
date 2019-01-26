#include "CmdParser.h"


//	string getCurrentCmd();
//	void printCmdHistory();
//	void clearCmdHistory();
//	void clearCmdList();

CmdParser::CmdParser() {

}

CmdParser::~CmdParser() {
	
}
	
void CmdParser::handleCommand(string cmd) {
	if (cmd.length() == 0) { return; }	//Empty command

	this->command = cmd;
	CmdWord* foundCmd = 0;

	//Convert input to lower case to make parsing easier
	transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

	//Generate cmd array, moving words into separate elements
	vector<string> cmdArray = generateCmdArray(cmd);

	//Search for command in cmdList
	//Command with 2 words or more
	if (cmdArray.size() > 1) {	
		//Search for valid 2-word command
		string cmd2words = cmdArray[0] + " " + cmdArray[1];
		foundCmd = cmdList->findCommand(cmd2words);

		//Didn't find valid 2-word command, search for 1-word command
		if (foundCmd == 0) {
			foundCmd = cmdList->findCommand(cmdArray[0]);
		}
	}
	// Command with 1 word only
	else {
		foundCmd = cmdList->findCommand(cmdArray[0]);
	}

	addCmdToHistory(cmd);

	if (foundCmd != 0) {	//Found a matching command from pre-set command list
		if (foundCmd->type == "help") {
			//Print available commands
			cmdList->printListDetailed();
		}
		if (foundCmd->type == "inventory") { //stub 
			cout << "\n ===Inventory===\n";
			cout << "Empty inventory\n";
		}
		//Syntax: go <north> or go <room>
		if (foundCmd->type == "go") {		//stub 
			//cout << "\nMoving rooms...\n";
			tryMovingRooms(cmdArray[1]);
		}
		if (foundCmd->type == "look") {		//stub 
			if (cmdArray.size() == 1) {		//Look command
				cout << "\nPrinting long form room description\n";
			}
		}
		if (foundCmd->type == "look at") {
			cout << "\nPrinting description of item/feature\n";
		}
		if (foundCmd->type == "take") {
			cout << "\nTaking an item\n";
		}
		if (foundCmd->type == "savegame") { //stub
			cout << "\nSaving game...\n";
		}
		if (foundCmd->type == "loadgame") { //stub 
			cout << "\nLoading game...\n";
			cout << "There are no saved games to load from!\n";
		}
		if (foundCmd->type == "quit") { //stub 
			cout << "\nExiting game...\n";
		}
		if (foundCmd->type == "debug") {
			printCmdHistory();
		}
	}
	//Else, search room name without adding prefix like go.
	// Ex: cmd = math classroom, cmd = north 
	else {
		tryMovingRooms(cmdArray[0]);
	}
}
	
string CmdParser::getCurrentCmd() {
	return command;
}

void CmdParser::initCmdList() {
	cmdList = new CmdList();

	//Adding all command words with their synonyms to list
	cmdList->addItemToList(new CmdWord("go", "go", " - go <direction>, moves players through the indicated direction to the next room"));
	cmdList->addItemToList(new CmdWord("go", "walk"));	
	cmdList->addItemToList(new CmdWord("go", "run"));
	cmdList->addItemToList(new CmdWord("look", "look", " - display long form description of the room"));
	cmdList->addItemToList(new CmdWord("look", "see"));
	cmdList->addItemToList(new CmdWord("look at", "look at", " - display description of an object or feature"));
	cmdList->addItemToList(new CmdWord("help", "help", " - show list of all available commands"));
	cmdList->addItemToList(new CmdWord("inventory", "inventory", " - shows player's current inventory"));
	cmdList->addItemToList(new CmdWord("inventory", "show inventory"));
	cmdList->addItemToList(new CmdWord("take", "take", " - get an object, place it in inventory"));
	cmdList->addItemToList(new CmdWord("take", "grab"));
	cmdList->addItemToList(new CmdWord("take", "pick up"));
	cmdList->addItemToList(new CmdWord("savegame", "savegame", " - save the current game state to a file"));
	cmdList->addItemToList(new CmdWord("loadgame", "loadgame", " - on user confirmation, loads previous game state from file"));
	cmdList->addItemToList(new CmdWord("debug", "debug", " - shows useful debug info for developers"));
	cmdList->addItemToList(new CmdWord("quit", "quit", " - quits game"));
	cmdList->addItemToList(new CmdWord("quit", "exit"));
}

CmdList* CmdParser::getCmdList() {
	return cmdList;
}

// Split up string into array of words, delimited by spaces
vector<string> CmdParser::generateCmdArray(string cmd) {
	string delimiter = " ";	//character used to split up input array
	vector<string> cmdArray;
	size_t pos = 0;
	string token;

	while ((pos = cmd.find(delimiter)) != string::npos) {
		token = cmd.substr(0, pos);
		cmdArray.push_back(token);
		cmd = cmd.substr(pos + delimiter.length());
	}
	cmdArray.push_back(cmd);
	return cmdArray;
}

bool CmdParser::tryMovingRooms(string room) {
	bool movedRooms = false;
	cout << "\nTrying to move Rooms\n" << endl;
	//Space* currentRoom = School->getCurrentRoom();
	//vector<Space*> availableExits = currentRoom->getExits();
	//vector<strings> availableDirs = currentRoom->getExitDirections();

	//for(int i = 0; i < availableExits.size(); i++){	//Check for available rooms connected to current room
	//	if (room == availableExits[i].getType()) {
	//		School->moveToRoom(room);
	//		return true;
	//	}
	//}
	//for(int i = 0; i < availableDirs.size(); i++){ //Check for available directions connected to current room
	//	if (room == availableDirs[i]) {
	//		School->moveToRoom(room);
	//		return true;		
	//	}
	//}
	if (!movedRooms) {
		cout << "Invalid room\n";
	}
	return movedRooms;
}

void CmdParser::addCmdToHistory(string cmd) {
	char count[16];
	snprintf(count, sizeof(count), "[ %d ]", cmdHistory.size()+1);
	string historyItem = count;
	historyItem += " - " + cmd;
	cmdHistory.push_back(historyItem);
}

void CmdParser::printCmdHistory() {
	cout << "\n====Command history====\n";
	cout << "  #     Command\n";
	for (unsigned int i = 0; i < cmdHistory.size(); i++) {
		cout << cmdHistory[i] << endl;
	}
	if (cmdHistory.size() == 0) {
		cout << "Empty history\n";
	}
}

void CmdParser::clearCmdHistory() {
	cmdHistory.clear();
}

//vector<Space*> Space::getExits() {
//	vector<Space*> exitList;
//	Space* exit;
//	 
//	if ((exit = room->getNorth()) != 0) {
//			exitList.push_back(exit);
//	}
//	if ((exit = room->getSouth()) != 0) {
//		exitList.push_back(exit);
//	}
//	if ((exit = room->getEast()) != 0) {
//		exitList.push_back(exit);
//	}
//	if ((exit = room->getWest()) != 0) {
//		exitList.push_back(exit);
//	}
//	return exitList;
//}

//vector<string> Space::getExitDirections() {
//	vector<string> exitList;
//	Space* exit;
//
//	if ((exit = room->getNorth()) != 0) {
//		exitList.push_back("north");
//	}
//	if ((exit = room->getSouth()) != 0) {
//		exitList.push_back("south");
//	}
//	if ((exit = room->getEast()) != 0) {
//		exitList.push_back("east");
//	}
//	if ((exit = room->getWest()) != 0) {
//		exitList.push_back("west");
//	}
//	return exitList;
//}