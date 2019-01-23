#include "CmdParser.h"


//	string getCurrentCmd();
//
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

	if (foundCmd != 0) {
		command = cmd;
		if (foundCmd->type == "help") {
			//Print available commands
			cmdList->printListDetailed();
		}
	}
}

string CmdParser::getCurrentCmd() {
	return command;
}

void CmdParser::initCmdList() {
	cmdList = new CmdList();
	cmdList->addItemToList(*(new CmdWord("go", "go", " - go <direction>, moves players through the indicated direction to the next room")));
	cmdList->addItemToList(*(new CmdWord("go", "walk")));
	cmdList->addItemToList(*(new CmdWord("go", "run")));
	cmdList->addItemToList(*(new CmdWord("look", "look", " - display long form description of the room")));
	cmdList->addItemToList(*(new CmdWord("look", "see")));
	cmdList->addItemToList(*(new CmdWord("help", "help", " - show list of all available commands")));
	cmdList->addItemToList(*(new CmdWord("inventory", "inventory", " - shows player's current inventory")));
	cmdList->addItemToList(*(new CmdWord("inventory", "show inventory")));
	cmdList->addItemToList(*(new CmdWord("take", "take", " - get an object, place it in inventory")));
	cmdList->addItemToList(*(new CmdWord("take", "grab")));
	cmdList->addItemToList(*(new CmdWord("take", "pick up")));
	cmdList->addItemToList(*(new CmdWord("savegame", "savegame", " - save the current game state to a file")));
	cmdList->addItemToList(*(new CmdWord("loadgame", "loadgame", " - on user confirmation, loads previous game state from file")));
}

CmdList* CmdParser::getCmdList() {
	return cmdList;
}
