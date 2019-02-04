
#include "StateManager.h"
#include "../Rooms/Space.h"
#include "../School.h"


int main() {

	School school;
	StateManager* manager = new StateManager();
	
	cout << "Printing empty list of saved states" << endl;
	manager->printStates();
	manager->saveState(&school);
	manager->saveState(&school);
	manager->saveState(&school);
	manager->printStates();

}
