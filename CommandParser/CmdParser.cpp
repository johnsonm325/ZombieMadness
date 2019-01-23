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

	//Search for command in list
	CmdWord* foundCmd = cmdList->foundCommand(cmd);
	addCmdToHistory(cmd);

	if (foundCmd != 0) {
		command = cmd;
		if(foundCmd->type == "help") { 
			//Print available commands
			cmdList->printListDetailed();
		}
		if(foundCmd->type == "inventory") { //stub 
			cout << " ===Inventory===\n";	
			cout << "Empty inventory\n";	
		}
		if(foundCmd->type == "go") {		//stub 
			cout << "Moving rooms...\n";	
		}
		if(foundCmd->type == "look") {		//stub 
			cout << "Printing long form room description\n";	
		}
		if(foundCmd->type == "savegame") { //stub
			cout << "Saving game...\n";		 
		}
		if(foundCmd->type == "loadgame") { //stub 
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
}

string CmdParser::getCurrentCmd() {
	return command;
}

void CmdParser::initCmdList() {
	cmdList = new CmdList();
	cmdList->addItemToList(new CmdWord("go", "go", " - go <direction>, moves players through the indicated direction to the next room"));
	cmdList->addItemToList(new CmdWord("go", "walk"));
	cmdList->addItemToList(new CmdWord("go", "run"));
	cmdList->addItemToList(new CmdWord("look", "look", " - display long form description of the room"));
	cmdList->addItemToList(new CmdWord("look", "see"));
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