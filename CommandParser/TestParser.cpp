#include "CmdParser.h"
#include "CmdList.h"

int main() {
	CmdParser* testParser = new CmdParser();
	testParser->initCmdList();
	//testParser->getCmdList()->printList();
	string input;

	do {
		cout << "\nEnter command: ";
		getline(cin, input);
		testParser->handleCommand(input);

	} while (input.compare("quit") != 0);

}