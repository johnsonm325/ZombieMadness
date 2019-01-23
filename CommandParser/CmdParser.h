#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include "../Globals.h"
#include "CmdList.h"

class CmdParser {
private:
	string command;
	CmdList* cmdList;	
	vector<string> cmdHistory;	//Might not be used really, could be helpful for debugging or testing purposes
public:
	CmdParser();	
	~CmdParser();

	void handleCommand(string cmd);
	string getCurrentCmd();
	void initCmdList();
	CmdList* getCmdList();

	void addCmdToHistory(string cmd);
	void printCmdHistory();
	void clearCmdHistory();
};


#endif
