#include "CmdParser.h"
#include "CmdList.h"

int main() {
	CmdParser* testParser = new CmdParser();
	testParser->initCmdList();
	//testParser->getCmdList()->printList();
	string input;

	//Initializing list of test commands
	//cmdList->addItemToList(new CmdWord("go", "go", " - go <direction>, moves players through the indicated direction to the next room"));
	//cmdList->addItemToList(new CmdWord("go", "walk"));
	//cmdList->addItemToList(new CmdWord("go", "run"));
	//cmdList->addItemToList(new CmdWord("look", "look", " - display long form description of the room"));
	//cmdList->addItemToList(new CmdWord("look", "see"));
	//cmdList->addItemToList(new CmdWord("look at", "look", " - display description of an object or feature"));
	//cmdList->addItemToList(new CmdWord("help", "help", " - show list of all available commands"));
	//cmdList->addItemToList(new CmdWord("inventory", "inventory", " - shows player's current inventory"));
	//cmdList->addItemToList(new CmdWord("inventory", "show inventory"));
	//cmdList->addItemToList(new CmdWord("take", "take", " - get an object, place it in inventory"));
	//cmdList->addItemToList(new CmdWord("take", "grab"));
	//cmdList->addItemToList(new CmdWord("take", "pick up"));
	//cmdList->addItemToList(new CmdWord("savegame", "savegame", " - save the current game state to a file"));
	//cmdList->addItemToList(new CmdWord("loadgame", "loadgame", " - on user confirmation, loads previous game state from file"));
	//cmdList->addItemToList(new CmdWord("debug", "debug", " - shows useful debug info for developers"));
	//cmdList->addItemToList(new CmdWord("quit", "quit", " - quits game"));
	//cmdList->addItemToList(new CmdWord("quit", "exit"));

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
*/
	int cmdIdx = 0;
	do {
		cout << "\nEnter command: ";
		//getline(cin, input);
		if (cmdIdx < testCmds.size()) {
			input = testCmds[cmdIdx];
			cout << input;
			cmdIdx++;
		}
		testParser->handleCommand(input);
	} while(input.compare("quit") != 0);
	
}