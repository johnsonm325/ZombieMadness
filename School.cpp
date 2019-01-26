#include "School.h"


School::School()
{
	mb = new MensBathroom();
	wb = new WomensBathroom();
	sfh1 = new SecondFloorHallway1();
	sfh2 = new SecondFloorHallway1();
	sfh3 = new SecondFloorHallway1();
	sfh4 = new SecondFloorHallway1();
	hist = new History();
	lit = new Literature();
	infr = new Infirmary();
	lr = new LockerRoom();
	gym2 = new GymnasiumFloor2();
	gym1 = new GymnasiumFloor1();
	fb = new Football();
	ffh1 = new FirstFloorHallway1();
	ffh2 = new FirstFloorHallway1();
	ffh3 = new FirstFloorHallway1();
	ffh4 = new FirstFloorHallway1();
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
	delete currentRoom;
}


void School::beginGame()
{
}


int School::playGame()
{
	return 0;
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

	Space *currentRoom = mb;
}

/****************************************************************************************************
**				Adds a value to the back of the list. Same set up as QueueList
****************************************************************************************************/
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
		prevRoom->setSouth(nextRoom);
		nextRoom->setSouth(prevRoom);
	}
}

Space* School::getCurrentRoom() {
	return currentRoom;
}

Space *School::moveEast()
{
	if (currentRoom->getEast() == NULL)
	{
		cout << "You can't go that direction." << endl;
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
		cout << "You can't go that direction." << endl;
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
		cout << "You can't go that direction." << endl;
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
		cout << "You can't go that direction." << endl;
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


/****************************************************************************************************
**				Removes item in the inventory to make space for new item
****************************************************************************************************/
void School::removeItem(string a)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (a == inventory[i])
		{
			inventory.pop_back();
		}
	}
}


/****************************************************************************************************
**							Searches for item in the inventory
****************************************************************************************************/
bool School::itemSearch(string a)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (a == inventory[i])
		{
			return true;
		}
	}
	return false;
}
