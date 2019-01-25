#include "CmdList.h"

CmdList::CmdList(){}
CmdList::~CmdList(){}

void CmdList::deleteList() {
	list.clear();
}

//Add command word to list
void CmdList::addItemToList(CmdWord* word) {
	if (!foundType(word->type)) {	//Word with that command type is not in the list
		vector<CmdWord*> newVect;
		newVect.push_back(word);
		list.push_back(newVect);
	}
	else {		//Word with that command type is  in the list
		for (unsigned int i = 0; i < list.size(); i++) {
			for (unsigned int j = 0; j < list[i].size(); j++) {
				if (list[i][j]->type.compare(word->type) == 0) {
					//cout << "Found same type, adding another word\n";
					list[i].push_back(word);
				}
				break;
			}
		}
	}
}

//Search for any command with a specific type
bool CmdList::foundType(string type) {
	for (unsigned int i = 0; i < list.size(); i++) {
		for (unsigned int j = 0; j < list[i].size(); j++) {
			//Found command type
			if (list[i][j]->type.compare(type) == 0) {
				return true;
			}
			//Go to next command type
			else {
				break;
			}
		}
	}
	return false;
}

CmdWord* CmdList::foundCommand(string keyCmd) {
	for (unsigned int i = 0; i < list.size(); i++) {
		for (unsigned int j = 0; j < list[i].size(); j++) {
			if (list[i][j]->command.compare(keyCmd) == 0) {
				return list[i][j];
			}
		}
	}
	return 0;
}
bool CmdList::isListEmpty() {
	return list.size() == 0;
}

unsigned int CmdList::getSize() {
	return list.size();
}

void CmdList::printList() {
	cout << "\n=== Printing list contents ===\n";
	if (!isListEmpty()) {
		for (unsigned int i = 0; i < list.size(); i++) {
			for (unsigned int j = 0; j < list[i].size(); j++) {
				if (j == 0 && list[i].size() > 0) {
					cout << "\nType: " << list[i][0]->type << "  commands: ";
				}
				cout  << list[i][j]->command << ", ";
			}
		}
	}
	else {
		cout << "List is empty\n";
	}
}

void CmdList::printListDetailed(){

	int cmdNum = 0;
	cout << "\n === List of Commands ===";
	if (!isListEmpty()) {
		for (unsigned int i = 0; i < list.size(); i++) {
			for (unsigned int j = 0; j < list[i].size(); j++) {
				if (j == 0 && list[i].size() > 0) {
					cmdNum++;
					cout << "\n " << cmdNum << ": " << list[i][0]->type << list[i][0]->description;
					break;
				}
			}
		}
	}
	else {
		cout << "List is empty\n";
	}
}