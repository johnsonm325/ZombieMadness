#include "GameState.h"

GameState::GameState() {

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

void GameState::setRooms(vector<Space*> allrooms) {
	
	Space *mb, *wb, *cafe, *libr, *sfh1, *sfh2, *sfh3, *sfh4;
	Space *hist, *lit, *chem, *cs, *bio, *math,*infr, *lr,*gym2, *gym1, *fb;
	Space *ffh1, *ffh2, *ffh3, *ffh4, *fl, *fo, *prin;
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
	int rIdx;
	for(unsigned int i = 0; i < getRooms().size(); i++){
		if(room == rooms[i]){
			rIdx = i;
			break;
		}
	}
	return rIdx;
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