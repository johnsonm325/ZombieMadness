#include "School.h"


School::School()
{
	mb = new MensBathroom();
	wb = new WomensBathroom();
	sfh1 = new SecondFloorHallway();
	sfh2 = new SecondFloorHallway();
	sfh3 = new SecondFloorHallway();
	sfh4 = new SecondFloorHallway();
	hist = new History();
	lit = new Literature();
	infr = new Infirmary();
	lr = new LockerRoom();
	gym2 = new GymnasiumFloor2();
	gym1 = new GymnasiumFloor1();
	fb = new Football();
	ffh1 = new FirstFloorHallway();
	ffh2 = new FirstFloorHallway();
	ffh3 = new FirstFloorHallway();
	ffh4 = new FirstFloorHallway();
	cafe = new Cafeteria();
	chem = new Chemistry();
	cs = new ComputerScience();
	bio = new Biology();
	math = new Math();
	libr = new Library();
	fl = new FrontLobby();
	fo = new FrontOffice();
	prin = new PrincipalsOffice();

	connectRooms();
}

School::~School()
{
	delete mb;
	delete wb;
	delete sfh1;
	delete sfh2;
	delete sfh3;
	delete sfh4;
	delete hist;
	delete lit;
	delete infr;
	delete lr;
	delete gym2;
	delete gym1;
	delete fb;
	delete ffh1;
	delete ffh2;
	delete ffh3;
	delete ffh4;
	delete cafe;
	delete chem;
	delete cs;
	delete bio;
	delete math;
	delete libr;
	delete fl;
	delete fo;
	delete prin;
	
}


void School::beginGame()
{
	
}


//int School::playGame()
//{
//	while(currentRoom != NULL)
//	{
//		cout << "You are in the " << currentRoom->getType() << endl << endl;
//		cout << "Please enter choice:" << endl;
//		cin >> choice;
//
//		if (choice == "q")
//		{
//			return 0;
//		}
//
//		else if(choice == "w")
//		{
//			if(currentRoom->getNorth() != NULL){	
//				cout << currentRoom->getNorth()->getType() << endl;
//			}
//		}
//
//		else if(choice == "a")
//		{
//			if(currentRoom->getWest() != NULL){
//				cout << currentRoom->getWest()->getType() << endl;
//			}
//		}
//		
//		else if(choice == "s")
//		{
//			if(currentRoom->getSouth() != NULL){
//				cout << currentRoom->getSouth()->getType() << endl;
//			}
//		}
//
//		else if(choice == "d")
//		{
//			if(currentRoom->getEast() != NULL){
//				cout << currentRoom->getEast()->getType() << endl;
//			}
//		}
//
//		else if(choice == "i")
//		{
//			moveNorth();
//		}
//
//		else if(choice == "j")
//		{
//			moveWest();
//		}
//
//		else if(choice == "k")
//		{
//			moveSouth();
//		}
//
//		else if(choice == "l")
//		{
//			moveEast();
//		}
//	}
//	return 0;
//}

int School::playGame()
{
	CmdParser* parser = new CmdParser();

	do 
	{
		cout << "You are in the " << currentRoom->getType() << endl << endl;
		cout << "Please enter choice:" << endl;
		cin >> choice;

		processCommand(parser, choice);
	} while (choice != "q" && choice != "quit");

	return 0;
}

void School::processCommand(CmdParser* parser, string cmd) {
	if (cmd.length() == 0) { return; }	//Empty command

	parser->setCommand(cmd);
	CmdWord* foundCmd = 0;

	//Convert input to lower case to make parsing easier
	transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

	//Generate cmd array, moving words into separate elements
	vector<string> cmdArray = parser->generateCmdArray(cmd);

	//Search for command in cmdList
	//Command with 2 words or more
	if (cmdArray.size() > 1) {
		//Search for valid 2-word command
		string cmd2words = cmdArray[0] + " " + cmdArray[1];
		foundCmd = parser->getCmdList()->findCommand(cmd2words);

		//Didn't find valid 2-word command, search for 1-word command
		if (foundCmd == 0) {
			foundCmd = parser->getCmdList()->findCommand(cmdArray[0]);
		}
	}
	// Command with 1 word only
	else {
		foundCmd = parser->getCmdList()->findCommand(cmdArray[0]);
	}

	parser->addCmdToHistory(cmd);

	if (foundCmd != 0) {	//Found a matching command from pre-set command list
		if (foundCmd->getType() == "help") {
			//Print available commands
			parser->getCmdList()->printListDetailed();
		}
		if (foundCmd->getType() == "inventory") { //stub 
			cout << "\n ===Inventory===\n";
			cout << "Empty inventory\n";
		}
		//Syntax: go <direction> 
		if (foundCmd->getType() == "go") {		//stub 
			//Go in a specific direction
			if (cmd == "north" || cmd == "go north" || cmd == "i") {
				moveNorth();
			}
			else if (cmd == "west" || cmd == "go west" || cmd == "j") {
				moveWest();
			}
			else if (cmd == "south" || cmd == "go south" || cmd == "k") {
				moveSouth();
			}
			else if (cmd == "east" || cmd == "go east" || cmd == "l") {
				moveEast();
			}
			else {
				//Go to a specific room 
			}
		}
		if (foundCmd->getType() == "dir") {
			if (cmd == "w") {
				currentRoom->printDirection(currentRoom->getNorth());
			}
			else if (cmd == "a") {
				currentRoom->printDirection(currentRoom->getWest());
			}
			else if (cmd == "s") {
				currentRoom->printDirection(currentRoom->getSouth());
			}
			else if (cmd == "d") {
				currentRoom->printDirection(currentRoom->getEast());
			}
			else if (cmd == "dir") {

			}
		}

		if (foundCmd->getType() == "look") {		//stub 
			if (cmdArray.size() == 1) {		//Look command
				cout << "\nPrinting long form room description\n";
			}
		}
		if (foundCmd->getType() == "look at") {
			cout << "\nPrinting description of item/feature\n";
		}
		if (foundCmd->getType() == "take") {
			cout << "\nTaking an item\n";
		}
		if (foundCmd->getType() == "drop") {
			cout << "\nDropping an item\n";
		}
		if (foundCmd->getType() == "savegame") { //stub
			cout << "\nSaving game...\n";
		}
		if (foundCmd->getType() == "loadgame") { //stub 
			cout << "\nLoading game...\n";
			cout << "There are no saved games to load from!\n";
		}
		if (foundCmd->getType() == "quit") { //stub 
			cout << "\nExiting game...\n";
		}
		if (foundCmd->getType() == "debug") {
			parser->printCmdHistory();
		}
	}
	//Else,go to room name without adding prefix like go <room>.
	// Ex: cmd = math classroom
	else {
		//parser->tryMovingRooms(cmdArray[0]);
	}
}

void School::connectRooms() {
	addRoom('s', wb, mb);
	addRoom('w', sfh1, mb);
	addRoom('w', sfh2, wb);
	addRoom('s', sfh2, sfh1);
	addRoom('w', hist, sfh3);
	addRoom('e', lit, sfh3);
	addRoom('s', sfh3, sfh2);
	addRoom('s', lr, lit);
	addRoom('w', infr, sfh4);
	addRoom('e', lr, sfh4);
	addRoom('s', sfh4, sfh3);
	addRoom('s', chem, infr);
	addRoom('s', gym2, lr);
	addRoom('s', ffh4, sfh4);
	addRoom('w', gym1, gym2);
	addRoom('s', fb, gym1);
	addRoom('w', ffh4, gym1);
	addRoom('w', cafe, ffh4);
	addRoom('n', ffh3, ffh4);
	addRoom('e', cs, ffh3);
	addRoom('w', chem, ffh3);
	addRoom('n', bio, chem);
	addRoom('n', ffh2, ffh3);
	addRoom('w', bio, ffh2);
	addRoom('e', math, ffh2);
	addRoom('n', libr, bio);
	addRoom('n', fl, math);
	addRoom('n', ffh1, ffh2);
	addRoom('w', libr, ffh1);
	addRoom('e', fl, ffh1);
	addRoom('e', fo, fl);
	addRoom('e', prin, fo);

	this->currentRoom = mb;
}

void School::addRoom(char direction, Space *nextRoom, Space *prevRoom)
{
	
	if (direction == 'e')
	{
		prevRoom->setEast(nextRoom);
		nextRoom->setWest(prevRoom);
	}

	else if (direction == 'w')
	{
		prevRoom->setWest(nextRoom);
		nextRoom->setEast(prevRoom);
	}

	else if (direction == 'n')
	{
		prevRoom->setNorth(nextRoom);
		nextRoom->setSouth(prevRoom);
	}

	else if (direction == 's')
	{
		// to set the non-standard joining of chemistry and infirmary rooms
		if (prevRoom->getType() == "chem")
		{
			prevRoom->setSouth(nextRoom);
			nextRoom->setSouth(prevRoom);
		}
		else
		{
			prevRoom->setSouth(nextRoom);
			nextRoom->setNorth(prevRoom);
		}
	}
}

Space* School::getCurrentRoom() {
	return currentRoom;
}

Space *School::moveEast()
{
	if (currentRoom->getEast() == NULL)
	{
		cout << "move east, You can't go that direction." << endl;
		return NULL;
	}
	else
	{
		currentRoom = currentRoom->getEast();
		return currentRoom;
	}
}


Space *School::moveWest()
{
	if (currentRoom->getWest() == NULL)
	{
		cout << "move west, You can't go that direction." << endl;
		return NULL;
	}
	else
	{
		currentRoom = currentRoom->getWest();
		return currentRoom;
	}
}


Space *School::moveNorth()
{
	if (currentRoom->getNorth() == NULL)
	{
		cout << "move north, You can't go that direction." << endl;
		return NULL;
	}
	else
	{
		currentRoom = currentRoom->getNorth();
		return currentRoom;
	}
}


Space *School::moveSouth()
{
	if (currentRoom->getSouth() == NULL)
	{
		cout << "move south, You can't go that direction." << endl;
		return NULL;
	}
	else
	{
		currentRoom = currentRoom->getSouth();
		return currentRoom;
	}
}


void School::addItem(string i)
{
	if (inventory.size() > 2)
	{
		cout << "You do not have enough space in your inventory" << endl;
	}

	else
	{
		inventory.push_back(i);
	}
}


void School::removeItem(string a)
{
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		if (a == inventory[i])
		{
			inventory.pop_back();
		}
	}
}


bool School::itemSearch(string a)
{
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		if (a == inventory[i])
		{
			return true;
		}
	}
	return false;
}
