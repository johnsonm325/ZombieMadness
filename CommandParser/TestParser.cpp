#include "CmdParser.h"
#include "CmdList.h"

int main() {
	CmdParser* testParser = new CmdParser();
	testParser->initCmdList();
	//testParser->getCmdList()->printList();
	string input;

	vector<string> testCmds;
	testCmds.push_back("go north");
	testCmds.push_back("look at");
	testCmds.push_back("help");
	testCmds.push_back("");
	for (int i = 0; i < testCmds.size(); i++) {
		vector<string> tmpVect= testParser->generateCmdArray(testCmds[i]);
		cout << "Generated array:\n";
		for (int j = 0; j < tmpVect.size(); j++) {
			cout << "idx " << j << ": " << tmpVect[j] << endl;
		}
	}

	/*do {
		cout << "\nEnter command: ";
		getline(cin, input);
		testParser->handleCommand(input);

	} while (input.compare("quit") != 0);*/
	
}