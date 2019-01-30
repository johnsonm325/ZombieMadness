#ifndef CMD_WORD_H
#define CMD_WORD_H

#include <string>
using std::string;

class CmdWord {
private:
	string type;	//words with similar meanings will go under the same type
	string command;
	string description;
public:
	CmdWord(string type, string cmd);
	CmdWord(string type, string cmd, string desc);
	string getType();
	string getCommand();
	string getDescription();
};

#endif