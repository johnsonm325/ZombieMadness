#include "CmdParser.h"
#include "CmdList.h"

int main2() {
	CmdParser* testParser = new CmdParser();
	//testParser->getCmdList()->printList();
	string input;

	vector<string> testCmds;
	testCmds.push_back("go Mens Bathroom");
	testCmds.push_back("Mens Bathroom");
	testCmds.push_back("go north");
	testCmds.push_back("north");
	testCmds.push_back("walk Mens Bathroom");
	testCmds.push_back("walk north");
	testCmds.push_back("run Mens Bathroom");
	testCmds.push_back("run north");

	testCmds.push_back("look");
	testCmds.push_back("look at toilet");

	testCmds.push_back("help");
	testCmds.push_back("inventory");
	testCmds.push_back("show inventory");

	testCmds.push_back("take plunger");
	testCmds.push_back("grab plunger");
	testCmds.push_back("pick up plunger");

	testCmds.push_back("savegame");
	testCmds.push_back("loadgame");
	testCmds.push_back("debug");
	testCmds.push_back("quit");

	/*for (int i = 0; i < testCmds.size(); i++) {
		vector<string> tmpVect= testParser->generateCmdArray(testCmds[i]);
		cout << "Generated array:\n";
		for (int j = 0; j < tmpVect.size(); j++) {
			cout << "idx " << j << ": " << tmpVect[j] << endl;
		}
	}

	int cmdIdx = 0;
	do {
		cout << "\nEnter command: ";
		//getline(cin, input);
		if ((unsigned int) cmdIdx < testCmds.size()) {
			input = testCmds[cmdIdx];
			cout << input;
			cmdIdx++;
		}
		testParser->handleCommand(input);
	} while(input.compare("quit") != 0);

	*/
	return 0;
	
}