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

void GameState::setSteps(int steps){
	this->steps = steps;
}

int GameState::getSteps(){
	return steps;
}

void GameState::setRooms(vector<Space*> rooms) {
	this->rooms = rooms;
}

vector<Space*> GameState::getRooms(){
	return rooms;
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
	