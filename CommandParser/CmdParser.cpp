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

	//Convert input to lower case to make parsing easier
	transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

	//Generate cmd array, moving words into separate elements
	vector<string> cmdArray = generateCmdArray(cmd);

	//Search for command in list
	CmdWord* foundCmd = cmdList->foundCommand(cmdArray[0]);
	addCmdToHistory(cmd);

	if (foundCmd != 0) {	//Found a matching command from pre-set command list
		command = cmd;
		if (foundCmd->type == "help") {
			//Print available commands
			cmdList->printListDetailed();
		}
		if (foundCmd->type == "inventory") { //stub 
			cout << " ===Inventory===\n";
			cout << "Empty inventory\n";
		}
		//Syntax: go <north> or go <room>
		if (foundCmd->type == "go") {		//stub 
			cout << "Moving rooms...\n";
			tryMovingRooms(cmdArray[1]);
		}
		if (foundCmd->type == "look") {		//stub 
			if (cmdArray.size() == 1) {		//Look command
				cout << "Printing long form room description\n";
			}
			else if (cmdArray.size() > 1) {
				if (cmdArray[2] == "at") {	//Look at command
					cout << "Printing description of item/feature\n";
					//Object* currentItem = game->getCurrentItem(); //Get current item to be interacted with
					//cout << currentItem->description << endl;		//Print its description
				}
			}
		}
		if (foundCmd->type == "savegame") { //stub
			cout << "Saving game...\n";
		}
		if (foundCmd->type == "loadgame") { //stub 
			cout << "Loading game...\n";
			cout << "There are no saved games to load from!\n";
		}
		if (foundCmd->type == "quit") { //stub 
			cout << "Exiting game...\n";
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
	cmdList->addItemToList(new CmdWord("look at", "look", " - display description of an object or feature"));
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

vector<string> CmdParser::generateCmdArray(string cmd) {
	string delimiter = " ";
	vector<string> cmdArray;
	size_t pos = 0;
	string token;

	while ((pos = cmd.find(delimiter)) != string::npos) {
		token = cmd.substr(0, pos);
		//cout << token << endl;
		cmdArray.push_back(token);
		cmd = cmd.substr(pos + delimiter.length());
		//cout << cmd << endl;
	}
	cmdArray.push_back(cmd);
	return cmdArray;
}

bool tryMovingRooms(string room) {
	bool movedRooms = false;
	//Space* currentRoom = School->getCurrentRoom();
	//vector<Space*> availableExits= currentRoom->getExits();
	//vector<strings> availableDirs= currentRoom->getDirections();

	//for(int i = 0; i < availableExits.size(); i++){	//Check for available rooms connected to current room
	//	if (room == availableExits[i].getRoomName()) {
	//		School->moveToRoom(availableExits[i]);
	//		return true;
	//	}
	//}
	//for(int i = 0; i < availableDirs.size(); i++){ //Check for available directions connected to current room
	//	if (room == availableDirs[i]) {
	//		School->moveToRoom(availableDirs[i]);
	//		return true;		
	//	}
	//}
	if (!movedRooms) {
		cout << "Invalid command" << endl;
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
	cout << " ===Command history===\n";
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