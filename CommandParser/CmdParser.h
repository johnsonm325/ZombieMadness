#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include "Globals.h"
#include "CmdList.h"
#include <algorithm>

class CmdParser {
private:
	string command;
	CmdList* cmdList;	
	vector<string> cmdHistory;	//Might not be used really, could be helpful for debugging or testing purposes
public:
	CmdParser();	
	~CmdParser();

	void initCmdList();

	void handleCommand(string cmd);
	void setCommand(string cmd);
	string getCommand();
	CmdList* getCmdList();
	vector<string> generateCmdArray(string cmd);
	bool tryMovingRooms(string room);

	void addCmdToHistory(string cmd);
	void printCmdHistory();
	void clearCmdHistory();
};

#endif
