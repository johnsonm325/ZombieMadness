#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../Creatures/Player.h"

//Room includes
#include "../Rooms/Biology.h"
#include "../Rooms/Cafeteria.h"
#include "../Rooms/Chemistry.h"
#include "../Rooms/ComputerScience.h"
#include "../Rooms/FirstFloorHallway.h"
#include "../Rooms/Football.h"
#include "../Rooms/FrontLobby.h"
#include "../Rooms/FrontOffice.h"
#include "../Rooms/GymnasiumFloor1.h"
#include "../Rooms/GymnasiumFloor2.h"
#include "../Rooms/History.h"
#include "../Rooms/Infirmary.h"
#include "../Rooms/Library.h"
#include "../Rooms/Literature.h"
#include "../Rooms/LockerRoom.h"
#include "../Rooms/Math.h"
#include "../Rooms/MensBathroom.h"
#include "../Rooms/PrincipalsOffice.h"
#include "../Rooms/SecondFloorHallway.h"
#include "../Rooms/WomensBathroom.h"

//Item includes
#include "../Items/BiteCure.h"
#include "../Items/BaseballBat.h"
#include "../Items/EnergyDrink.h"
#include "../Items/FireExtinguisher.h"
#include "../Items/FirstAid.h"
#include "../Items/Gun.h"
#include "../Items/Jersey.h"
#include "../Items/Key.h"
#include "../Items/Knife.h"
#include "../Items/Map.h"
#include "../Items/Paperclip.h"
#include "../Items/Rocks.h"
#include "../Items/SteelLid.h"
#include "../Items/Sword.h"

#include <ctime>
#include <cstdint>
#include <cstring>
// #include <algorithm>

class GameState 
{
private:
	Space *currentRoom;
	int roomIdx = 0;
	int steps; 

	Space *mb, *wb, *cafe, *libr, *sfh1, *sfh2, *sfh3, *sfh4;
	Space *hist, *lit, *chem, *cs, *bio, *math,*infr, *lr,*gym2, *gym1, *fb;
	Space *ffh1, *ffh2, *ffh3, *ffh4, *fl, *fo, *prin;

	string timeStamp;
	vector<Space*> rooms;
	Player* player;

public:
	GameState();
	~GameState();
	string getTime();
	void updateTime();
	void setTime(string time);

	//Rooms
	void connectRooms();
	void addRoom(char direction, Space *nextRoom, Space *prevRoom);
	void createRoomsList();
	void copyRoomsListToSpace();
	vector<Space*>& getRoomsList();
	Space* getCurrentRoom();
	void setCurrentRoom(int idx);
	void setRoomIdx(int idx);
	int getRoomIdx();
	int findRoomByIdx(Space* room);

	void setSteps(int steps);
	int getSteps();

	//Player
	Player* getPlayer();
	
	//Moving data between different objects
	void copyPlayer(Player* dest, Player* source);
	void copyRooms(vector<Space*> &dest, const vector<Space*> &source);
	void copyInventory(Inventory* dest, Inventory* source);
	static Item* createItem(string name);
	void copyCreature(Creature* destCr, Creature* sourceCr);

	//Comparing data between different objects
	template <class T>
	void printComparison(string field1, string field2, string variable, T input1, T input2);
	
	void compareRooms(const vector<Space*> &dest, const vector<Space*> &source);
	void compareInventory(Inventory* dest, Inventory* source);
	void compareCreature(Creature* destCr, Creature* sourceCr);
	void comparePlayer(Player* dest, Player* source);
	
};

#endif
