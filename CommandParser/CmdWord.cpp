#include "CmdWord.h"

CmdWord::CmdWord(string type, string cmd) {
	this->type = type;
	this->command = cmd;
}
CmdWord::CmdWord(string type, string cmd, string desc) {
	this->type = type;
	this->command = cmd;
	this->description = desc;
}
string CmdWord::getType() {
	return type;
}
string CmdWord::getCommand() {
	return command;
}
string CmdWord::getDescription() {
	return description;
}