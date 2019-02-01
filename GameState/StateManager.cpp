#include "StateManager.h"

StateManager::StateManager() {

}

StateManager::~StateManager() {

}

GameState* StateManager::readSaveFile(string filename) {
	return NULL;
}

//Transfer data from state to game 
void StateManager::loadState(GameState* state, School* game) {

}

//Writing game state to file
GameState* StateManager::saveState(School* game) {
	return NULL;
}

void StateManager::writeSaveFile(GameState* state, string filename) {

}

//Managing states list
void StateManager::addGameState(GameState* state) {
	states.push_back(state);
}

void StateManager::removeGameState(GameState* state) {
	
}

void StateManager::printStates() {
	cout << "=== GAME STATES ===";
	cout << "State  Date";

	for (unsigned int i = 0; i < states.size(); i++) {
		cout << (i + 1) << ": " << states[i]->getTime() << endl;
	}
}