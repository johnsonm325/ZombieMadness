#ifndef CMD_LIST_H
#define CMD_LIST_H

#include "CmdWord.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class CmdList{
private:
	string command;
	vector<vector<CmdWord*>> list;
public:
	CmdList();
	~CmdList();
	void deleteList();
	vector<vector<CmdWord*>> getList();
	void setList(vector<vector<CmdWord*>> list);
	void addItemToList(CmdWord* word);
	CmdWord* findCommand(string cmd);
	bool foundType(string type);
	unsigned int getSize();
	bool isListEmpty();
	void printList();
	void printListDetailed();
};

#endif

