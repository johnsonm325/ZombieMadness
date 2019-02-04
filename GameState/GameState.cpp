#include "GameState.h"

GameState::GameState() {

}
GameState::~GameState() {

}

string GameState::getTime() {
	return timeStamp;
}

void GameState::setTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string str(buffer);
	timeStamp = str;

}

void GameState::addRoomList(vector<Space*> rooms) {
	this->rooms = rooms;
}