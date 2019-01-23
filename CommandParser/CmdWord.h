#ifndef CMD_WORD_H
#define CMD_WORD_H

#include "../Globals.h"

class CmdWord {
public:
	string type;	//words with similar meanings will go under the same type
	string command;
	string description;

	CmdWord(string type, string cmd) {
		this->type = type;
		this->command = cmd;
	}
	CmdWord(string type, string cmd, string desc) {
		this->type = type;
		this->command = cmd;
		this->description = desc;
	}
};

#endif