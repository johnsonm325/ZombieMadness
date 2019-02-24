#include "GameState.h"

GameState::GameState() {
	player = new Player();
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
	delete player;
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
		if (nextRoom->getType() == "Chemistry")
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

	copyRoomsListToSpace();
}

void GameState::copyRoomsListToSpace() {
	for (unsigned int i = 0; i < rooms.size(); i++) {
		rooms[i]->addRoomsListToSpace(rooms);
	}
}

vector<Space*> GameState::getRoomsList(){
	return rooms;
}

Space* GameState::getCurrentRoom(){
	return currentRoom;
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

Player* GameState::getPlayer(){
	return player;
}

//Copy player data from current game to game state object
void GameState::copyPlayer(Player* player){
	this->player = new Player();
}

void GameState::copyRooms(vector<Space*> dest, vector<Space*> source){
	//Rigorous argument checks
	if(dest.size() == 0 || source.size() == 0) { return; }
	if(dest.size() != source.size() ) {return; }

	int i;
	for(i = 0; i < (int)dest.size(); i++){

		//Copying boolean State class variables first	
		// bool doorLocked = false, firstTry = true,  goneColt = false;
		bool locked = source[i]->getDoorLocked();
		if(locked){
			dest[i]->lockDoor();
		}
		else{
			dest[i]->unlockDoor();
		}
		dest[i]->setFirstTry(source[i]->isFirstTry());
		dest[i]->setColtGone(source[i]->coltGone());

		//Copying room inventory from source to dest
		copyInventory(dest[i]->getInventory(), source[i]->getInventory());	
	}
}

//Copy inventory from source to dest inventory
void GameState::copyInventory(Inventory* dest, Inventory* source){
	//Copying removable room items
	vector<Item*> sourceItems = source->getItems();
	vector<Item*> destItems = dest->getItems();
	vector<Item*> movableItems;
	int i;

	//Create vector all movable objects(copies) in the room
	for(i = 0; i < (int) sourceItems.size(); i++){
		if(sourceItems[i]->isMovable()){
			Item* newItem = createItem(sourceItems[i]->getName());
			movableItems.push_back(newItem);
		}
	}

	//Remove all movable objects in dest inventory for a clear slate
	for(i = 0; i < (int) destItems.size(); i++){
		if(destItems[i]->isMovable()){
			dest->removeItem(destItems[i]);
		}
	}
	//Add all movable objects in source inventory to dest inventory
	for(i = 0; i < (int)movableItems.size(); i++){
		dest->addItem(movableItems[i]);
	}
}

//Create new removable item to add to room in game state
Item* GameState::createItem(string name){
	Item* newItem = NULL;

	if (name == "Baseball Bat"){
		newItem = new BaseballBat();
	}
	else if(name == "Bite Cure"){
		newItem = new BiteCure();
	}
	else if (name == "Energy Drink LV1"){
		newItem = new EnergyDrink(1);
	}
	else if (name == "Energy Drink LV2"){
		newItem = new EnergyDrink(2);
	}
	else if (name == "Fire Extinguisher"){
		newItem = new FireExtinguisher();
	}
	else if (name == "First Aid"){
		newItem = new FirstAid();
	}
	else if (name == "Gun"){
		newItem = new Gun();
	}
	else if (name == "Jersey"){
		newItem = new Jersey();
	}
	else if (name == "Key"){
		newItem = new Key();
	}
	else if (name == "Knife"){
		newItem = new Knife();
	}
	else if (name == "Map"){
		newItem = new Map();
	}
	else if (name == "Paperclip"){
		newItem = new Paperclip();
	}
	else if (name == "Rocks"){
		newItem = new Rocks();
	}
	else if (name == "Steel Lid"){
		newItem = new SteelLid();
	}
	else if (name == "Sword"){
		newItem = new Sword();
	}

	return newItem;
}
