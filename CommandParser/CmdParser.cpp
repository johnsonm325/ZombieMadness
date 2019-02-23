#include "CmdParser.h"

CmdParser::CmdParser() {
	initCmdList();
}

CmdParser::~CmdParser() {
}
	
void CmdParser::setCommand(string cmd) {
	command = cmd;
}
string CmdParser::getCommand() {
	return command;
}

void CmdParser::initCmdList() {
	cmdList = new CmdList();

	//Adding all command words with their synonyms to list
	cmdList->addItemToList(new CmdWord("help", "help", " - show list of all available commands"));

	//Moving player through rooms
	cmdList->addItemToList(new CmdWord("go", "go", " - go <direction>, moves players through the indicated direction to the next room"));
	cmdList->addItemToList(new CmdWord("go", "walk"));	
	cmdList->addItemToList(new CmdWord("go", "run"));
	cmdList->addItemToList(new CmdWord("go", "go north"));
	cmdList->addItemToList(new CmdWord("go", "north"));
	cmdList->addItemToList(new CmdWord("go", "i"));
	cmdList->addItemToList(new CmdWord("go", "go south"));
	cmdList->addItemToList(new CmdWord("go", "south"));
	cmdList->addItemToList(new CmdWord("go", "k"));
	cmdList->addItemToList(new CmdWord("go", "go east"));
	cmdList->addItemToList(new CmdWord("go", "east"));
	cmdList->addItemToList(new CmdWord("go", "l"));
	cmdList->addItemToList(new CmdWord("go", "go west"));
	cmdList->addItemToList(new CmdWord("go", "west"));
	cmdList->addItemToList(new CmdWord("go", "j"));
	cmdList->addItemToList(new CmdWord("dir", "dir", " - displays all available exits in current room"));
	cmdList->addItemToList(new CmdWord("dir", "w"));
	cmdList->addItemToList(new CmdWord("dir", "a"));
	cmdList->addItemToList(new CmdWord("dir", "s"));
	cmdList->addItemToList(new CmdWord("dir", "d"));
	// cmdList->addItemToList(new CmdWord("backtrack", "backtrack", " - player can head back to previous room"));
	// cmdList->addItemToList(new CmdWord("backtrack", "bk"));
	//cmdList->addItemToList(new CmdWord("where", "where", " - displays room player is currently in"));

	//Interacting with room
	cmdList->addItemToList(new CmdWord("look", "look", " - display long form description of the room"));
	cmdList->addItemToList(new CmdWord("look", "see"));

	//Interacting with objects
	//debug
	cmdList->addItemToList(new CmdWord("room inventory", "room inventory", " - display all room items"));
	cmdList->addItemToList(new CmdWord("room inventory", "ri"));
	//debug

	//-----Item commands------
	cmdList->addItemToList(new CmdWord("inventory", "inventory", " - shows player's current inventory"));
	cmdList->addItemToList(new CmdWord("inventory", "show inventory"));
	cmdList->addItemToList(new CmdWord("inventory", "inv"));
	cmdList->addItemToList(new CmdWord("look at", "look at", " - display description of an object or feature"));
	cmdList->addItemToList(new CmdWord("look at", "examine"));
	cmdList->addItemToList(new CmdWord("take", "take", " - get an object, place it in inventory"));
	cmdList->addItemToList(new CmdWord("take", "grab"));
	cmdList->addItemToList(new CmdWord("take", "pickup"));

	// Additional item commands
	cmdList->addItemToList(new CmdWord("drop", "drop", " - drop an object from player's inventory"));
	cmdList->addItemToList(new CmdWord("use", "use", " - use an item player has obtained, results in some event"));
	cmdList->addItemToList(new CmdWord("throw", "throw", " - throw an item in direction of zombie"));
	cmdList->addItemToList(new CmdWord("push", "push", " - push an item in room"));
	cmdList->addItemToList(new CmdWord("read", "read", " - read text on item in room (like note or book)"));
	cmdList->addItemToList(new CmdWord("wear", "wear", " - wear an item for defense against attacks"));
	cmdList->addItemToList(new CmdWord("eat", "eat", " - eat an item (ex: Energy Drink)"));
	cmdList->addItemToList(new CmdWord("cut", "cut", " - cut item in room"));
	
	//Player actions
	// cmdList->addItemToList(new CmdWord("jump", "jump", " - jump to higher ground or over an obstacle"));
	cmdList->addItemToList(new CmdWord("attack", "attack", " - attack zombie with a weapon from inventory"));
	cmdList->addItemToList(new CmdWord("attack", "hit"));
	cmdList->addItemToList(new CmdWord("block", "block", " - in fight with zombie, player can block to reduce damage"));
	cmdList->addItemToList(new CmdWord("open", "open", " - open door with key (usually)"));
	   
	//Saving/Loading Game
	cmdList->addItemToList(new CmdWord("savegame", "savegame", " - save the current game state to a file"));
	cmdList->addItemToList(new CmdWord("loadgame", "loadgame", " - on user confirmation, loads previous game state from file"));
	cmdList->addItemToList(new CmdWord("cleargames", "cleargames", " - on user confirmation, clears alls saved games from list"));
	
	//Debug and quit actions
	cmdList->addItemToList(new CmdWord("debug", "debug", " - shows useful debug info for developers"));
	cmdList->addItemToList(new CmdWord("quit", "quit", " - quits game"));
	cmdList->addItemToList(new CmdWord("quit", "exit"));
	cmdList->addItemToList(new CmdWord("quit", "q"));
}

CmdList* CmdParser::getCmdList() {
	return cmdList;
}

void CmdParser::printCmdVector(vector<string> cmdVector){
	for(unsigned int i = 0; i < cmdVector.size(); i++){
		cout << i << ": " << cmdVector[i] << endl;
	}
}

string CmdParser::extractArgument(vector<string> cmdVector, string cmdType){
	string item = "";

	//drop|take|action <item name>
	if(cmdType == "drop" || cmdType == "take" || cmdType == "use" || cmdType == "throw" ||
	   cmdType == "push" || cmdType == "read" || cmdType == "wear" || cmdType == "eat" ||
	   cmdType == "open" || cmdType == "cut"){	
		if(cmdVector.size() > 1){
			item = buildArgString(cmdVector, 1);
		}
	}
	else if(cmdType == "look at"){ //look at <item name>
		if(cmdVector.size() > 2){
			item = buildArgString(cmdVector, 2);
		}
	}
	else if(cmdType == "go"){	
		if (cmdVector[0] != "go"){		//Just room name
			item = buildArgString(cmdVector, 0);
		}
		else if(cmdVector.size() > 1){	//go <roomName>
			item = buildArgString(cmdVector, 1);
		}
	}
	return item;
}

string CmdParser::buildArgString(vector<string> cmdVector, int start){
	string item;
	unsigned int i;
	for(i = start; i < cmdVector.size(); i++){
		item += cmdVector[i];
		if(i < cmdVector.size() - 1){
			item +=" ";
		}
	}
	return item;
}

// Split up string into vector of words, delimited by spaces
vector<string> CmdParser::createCmdVector(string cmd) {
	string delimiter = " ";	//character used to split up input array
	vector<string> cmdVector;
	size_t pos = 0;
	string token;

	while ((pos = cmd.find(delimiter)) != string::npos) {
		token = cmd.substr(0, pos);
		cmdVector.push_back(token);
		cmd = cmd.substr(pos + delimiter.length());
	}
	cmdVector.push_back(cmd);
#ifdef DEBUG_PARSER
	printCmdVector(cmdVector);
#endif
	return cmdVector;
}

void CmdParser::addCmdToHistory(string cmd) {
	char count[16];
	snprintf(count, sizeof(count), "[ %d ]", (int) cmdHistory.size()+1);
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

