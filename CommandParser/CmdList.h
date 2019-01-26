#ifndef CMD_LIST_H
#define CMD_LIST_H

#include "Globals.h"
#include "CmdWord.h"

class CmdList{
private:
	string command;
	vector<vector<CmdWord*>> list;
public:
	CmdList();
	~CmdList();
	void deleteList();
	CmdList* getList();
	void setList(CmdList* list);
	void addItemToList(CmdWord* word);
	CmdWord* findCommand(string cmd);
	bool foundType(string type);
	unsigned int getSize();
	bool isListEmpty();
	void printList();
	void printListDetailed();
};

#endif

