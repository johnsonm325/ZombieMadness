#include "GameState.h"

GameState::GameState() {
	PlayerInventory* inv = new PlayerInventory();
	mb = new MensBathroom();
	wb = new WomensBathroom(inv);
	sfh1 = new SecondFloorHallway();
	sfh2 = new SecondFloorHallway();
	sfh3 = new SecondFloorHallway(false);
	sfh4 = new SecondFloorHallway(false);
	hist = new History();
	lit = new Literature();
	infr = new Infirmary();
	lr = new LockerRoom();
	gym2 = new GymnasiumFloor2();
	gym1 = new GymnasiumFloor1();
	fb = new Football();
	ffh1 = new FirstFloorHallway(false);
	ffh2 = new FirstFloorHallway(false);
	ffh3 = new FirstFloorHallway(false);
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
	createRoomsList();
}
GameState::~GameState() {

}

string GameState::getTime() {
	return timeStamp;
}
void GameState::setTime(string time){
	timeStamp = time;
}

void GameState::updateTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
	std::string str(buffer);
	timeStamp = str;
}

void GameState::connectRooms() {
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
	addRoom('s', sfh4, ffh4);
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

void GameState::addRoom(char direction, Space *nextRoom, Space *prevRoom)
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

void GameState::createRoomsList(){
	
	rooms.push_back(mb);
	rooms.push_back(wb);
	rooms.push_back(cafe);
	rooms.push_back(libr);
	rooms.push_back(sfh1);
	rooms.push_back(sfh2);
	rooms.push_back(sfh3);
	rooms.push_back(sfh4);
	rooms.push_back(hist);
	rooms.push_back(lit);
	rooms.push_back(chem);
	rooms.push_back(cs);
	rooms.push_back(bio);
	rooms.push_back(math);
	rooms.push_back(infr);
	rooms.push_back(lr);
	rooms.push_back(gym1);
	rooms.push_back(gym2);
	rooms.push_back(fb);
	rooms.push_back(ffh1);
	rooms.push_back(ffh2);
	rooms.push_back(ffh3);
	rooms.push_back(ffh4);
	rooms.push_back(fl);
	rooms.push_back(fo);
	rooms.push_back(prin);
}


void GameState::copyRoomsListToSpace() {
	for (unsigned int i = 0; i < rooms.size(); i++) {
		rooms[i]->addRoomsListToSpace(rooms);
	}
}

vector<Space*> GameState::getRooms(){
	return rooms;
}

Space* GameState::getCurrentRoom(){
	return currentRoom;
}

void GameState::setCurrentRoom(Space* room){
	currentRoom = room;
	roomIdx = findRoomByIdx(room);
}

void GameState::setCurrentRoom(int idx){
	currentRoom = rooms[idx];
	roomIdx = idx;
}

void GameState::setRoomIdx(int idx){
	roomIdx = idx;
}
int GameState::getRoomIdx(){
	return roomIdx;
}

int GameState::findRoomByIdx(Space* room){
	for(unsigned int i = 0; i < getRooms().size(); i++){
		if(room == rooms[i]){
			return i;
		}
	}
	return -1;
}
	
void GameState::setSteps(int steps){
	this->steps = steps;
}

int GameState::getSteps(){
	return steps;
}

void GameState::addPlayer(Player* player){
	this->player = player;
}

Player* GameState::getPlayer(){
	return player;
}