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

	int findCommand(string cmd);	
	void handleCommand(string cmd);
	string getCurrentCmd();
	void initCmdList();
	CmdList* getCmdList();

	void printCmdHistory();
	void clearCmdHistory();
};


#endif
