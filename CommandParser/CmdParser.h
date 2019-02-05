#ifndef DEBUG_PARSER
	//#define DEBUG_PARSER
#endif

#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include "CmdList.h"
#include <algorithm>
using std::endl;

class CmdParser {
private:
	string command;
	CmdList* cmdList;	
	vector<string> cmdHistory;	//Might not be used really, could be helpful for debugging or testing purposes
public:
	CmdParser();	
	~CmdParser();

	void initCmdList();

	//void processCommand(string cmd);
	void setCommand(string cmd);
	string getCommand();
	CmdList* getCmdList();
	void printCmdArray(vector<string> cmdArray);
	string convertToItem(vector<string> cmdArray);
	vector<string> generateCmdArray(string cmd);

	void addCmdToHistory(string cmd);
	void printCmdHistory();
	void clearCmdHistory();
};

#endif
