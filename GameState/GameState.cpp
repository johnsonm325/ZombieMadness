#include "GameState.h"

GameState::GameState() {
	player = new Player();
	PlayerInventory* inv = new PlayerInventory();
	
	mb = new MensBathroom();
	wb = new WomensBathroom(inv);
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

bool GameState::getGameWon(){
	return isGameWon;
}

void GameState::setGameWon(bool won){
	isGameWon = won;
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

vector<Space*>& GameState::getRoomsList(){
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
void GameState::copyPlayer(Player* dest, Player* source){

	//Copying player's objects
	copyInventory(dest->getInventory(), source->getInventory());
	copyCreature(dest->getPlayer(), source->getPlayer());
}

//Copy room data from source to dest (by value, not pointer)
void GameState::copyRooms(vector<Space*> &dest, const vector<Space*> &source){
	//Rigorous argument checks
	if(dest.size() == 0 || source.size() == 0) { return; }
	if(dest.size() != source.size() ) {return; }

	int i;
	for(i = 0; i < (int)dest.size(); i++){

		//Copying boolean Space class variables first	
		// bool doorLocked = false, firstTry = true,  goneColt = false, deadZombies = true;
		bool locked = source[i]->getDoorLocked();
		if(locked == true){
			dest[i]->lockDoor();
		}
		else{
			dest[i]->unlockDoor();
		}
		dest[i]->setFirstTry(source[i]->getFirstTry());
		dest[i]->setDieOnEnter(source[i]->getDieOnEnter());

		//Copying derived room class booleans next
		if(source[i]->getType() == "Biology"){
			Biology* bioRoom = static_cast<Biology*>(dest[i]); 
			bioRoom->setPlantsEaten(static_cast<Biology*>(source[i])->getPlantsEaten());
		}
		if(source[i]->getType() == "Chemistry"){
			Chemistry* chemRoom = static_cast<Chemistry*>(dest[i]); 
			chemRoom->setHoleVisible(static_cast<Chemistry*>(source[i])->getHoleVisible());
		}
		if(source[i]->getType() == "Cafeteria"){
			Cafeteria* cafRoom = static_cast<Cafeteria*>(dest[i]); 
			if(static_cast<Cafeteria*>(source[i])->getVendingMachineUsed() == true){
				cafRoom->useVendingMachine();
			}
			else{
				cafRoom->eatSnack();
			}
		}
		if(source[i]->getType() == "Literature"){
			Literature* litRoom = static_cast<Literature*>(dest[i]); 
			litRoom->setNoteVisible(static_cast<Literature*>(source[i])->getNoteVisible());
		}
		if(source[i]->getType() == "Math"){
			Math* mathRoom = static_cast<Math*>(dest[i]); 
			mathRoom->eatApple(static_cast<Math*>(source[i])->getAppleEaten());
		}
		if(source[i]->getType() == "Men's Bathroom"){
			MensBathroom* mbRoom = static_cast<MensBathroom*>(dest[i]); 
			mbRoom->setHoleVisible(static_cast<MensBathroom*>(source[i])->getHoleVisible());
		}

		//Copying room inventory from source to dest
		copyInventory(dest[i]->getInventory(), source[i]->getInventory());	

		//Copying zombies
		copyCreature(dest[i]->getZombie(), source[i]->getZombie());	
	}
}

//Copy inventory from source to dest inventory
void GameState::copyInventory(Inventory* dest, Inventory* source){
	//Copying removable room items
	vector<Item*> sourceItems = source->getItems();
	vector<Item*> destItems = dest->getItems();
	vector<Item*> movableItems;
	PlayerInventory *dest0, *source0;
	int i;

	//Create vector of all movable objects(copies) in the room
	for(i = 0; i < (int)sourceItems.size(); i++){
		if(sourceItems[i]->isMovable()){
			Item* newItem = GameState::createItem(sourceItems[i]->getName());
			movableItems.push_back(newItem);
		}
	}

	if(source->getInventoryType() != "Player")
	{
		//Remove all movable objects in dest0 inventory for a clear slate
		for(i = 0; i < (int)destItems.size(); i++){
			if(destItems[i]->isMovable()){
				dest->removeItem(destItems[i]);
			}
		}
		//Add all movable objects in source inventory to dest inventory
		for(i = 0; i < (int)movableItems.size(); i++){
			dest->addItem(movableItems[i]);
		}
	}
	else{
		dest0 = static_cast<PlayerInventory*>(dest);
		source0 = static_cast<PlayerInventory*>(source);
		dest0->setLogLevel(true);	//Silence item additions to player's inventory
		source0->setLogLevel(true);	//Silence item additions to player's inventory

		//Update size, if needed
		if(source0->getSize() > 7){
			dest0->increaseSize();
		}
		else{
			dest0->setInitialSize();
		}
		//Remove all movable objects in inventory for a clear slate
		for(i = 0; i < (int)destItems.size(); i++){
			if(destItems[i]->isMovable()){
				dest0->removeItem(destItems[i], true);
			}
		}
		//Add all movable objects in source inventory to dest inventory
		for(i = 0; i < (int)movableItems.size(); i++){
			dest0->addItem(movableItems[i]);
		}
		dest0->setLogLevel(false);	//Reset silent flag back to original state
		source0->setLogLevel(false);	
	}
}

//Create new removable item to add to room in game state
Item* GameState::createItem(string name){
	Item* newItem = NULL;

	if ( name.find("Baseball Bat") !=std::string::npos ){
		newItem = new BaseballBat();
	}
	else if( name.find("Bite Cure") !=std::string::npos ){
		newItem = new BiteCure();
	}
	else if ( name.find("Fire Extinguisher") !=std::string::npos ){
		newItem = new FireExtinguisher();
	}
	else if ( name.find("First Aid") !=std::string::npos ){
		newItem = new FirstAid();
	}
	else if ( name.find("Gun") !=std::string::npos ){
		newItem = new Gun();
	}
	else if ( name.find("Jersey") !=std::string::npos ){
		newItem = new Jersey();
	}
	else if ( name.find("Key") !=std::string::npos ){
		newItem = new Key();
	}
	else if ( name.find("Knife") !=std::string::npos ){
		newItem = new Knife();
	}
	else if ( name.find("Rocks") !=std::string::npos ){
		newItem = new Rocks();
	}
	else if ( name.find("Steel Lid") !=std::string::npos ){
		newItem = new SteelLid();
	}
	else if ( name.find("Sword") !=std::string::npos ){
		newItem = new Sword();
	}
	else if ( name.find("Ropes") !=std::string::npos ){
		newItem = new Ropes();
	}
	else if ( name.find("Bookbag") !=std::string::npos ){
		newItem = new Bookbag();
	}
	return newItem;
}

void GameState::copyCreature(Creature* destCr, Creature* sourceCr){
	if( sourceCr != NULL && sourceCr != NULL ){
		destCr->setAlive(sourceCr->isAlive());
		destCr->setHealth(sourceCr->getHealth());
		destCr->setDefense(sourceCr->getDefense());
	}
}

template <class T>
void GameState::printComparison(string field1, string field2, string variable, T input1, T input2){
	if(input1 != input2){
		cout << field1 << " " << field2 << "\tvar = " << variable << "\tsource: " << input2;
		cout << "\tdest: " << input1 << endl;
	}
}

void GameState::compareRooms(const vector<Space*> &dest, const vector<Space*> &source){
//Rigorous argument checks
	if(dest.size() == 0 || source.size() == 0) {
		cout << "one of the rooms vectors is empty!" << endl;
		return;
	}
	if(dest.size() != source.size() ) 
	{
		cout << "room vectors not of equal size!" << endl;
		return; 
	}
	cout << "Comparing rooms...\n";
	// cout << "dest[0]:" << dest[0] << "rooms[0]:" << rooms[0] << endl;

	int i;
	for(i = 0; i < (int)dest.size(); i++){
		cout << "Room: " << source[i]->getType() << endl;

		printComparison("Room:", source[i]->getType(), "doorLocked", dest[i]->getDoorLocked(), source[i]->getDoorLocked());
		printComparison("Room:", source[i]->getType(), "firstTry", dest[i]->getFirstTry(), source[i]->getFirstTry());


		//Copying derived room class booleans next
		if(source[i]->getType() == "Biology"){
			printComparison("Room:", source[i]->getType(), "plantsEaten", static_cast<Biology*>(dest[i])->getPlantsEaten(), static_cast<Biology*>(source[i])->getPlantsEaten());
		}
		if(source[i]->getType() == "Chemistry"){
			printComparison("Room:", source[i]->getType(), "holeVisible", static_cast<Chemistry*>(dest[i])->getHoleVisible(), static_cast<Chemistry*>(source[i])->getHoleVisible());
		}
		if(source[i]->getType() == "Cafeteria"){
			printComparison("Room:", source[i]->getType(), "vendingMachineUsed", static_cast<Cafeteria*>(dest[i])->getVendingMachineUsed(),
			 static_cast<Cafeteria*>(source[i])->getVendingMachineUsed());
		}
		if(source[i]->getType() == "Literature"){
			printComparison("Room:", source[i]->getType(), "noteVisible", static_cast<Literature*>(dest[i])->getNoteVisible(), static_cast<Literature*>(source[i])->getNoteVisible());
		}
		if(source[i]->getType() == "Math"){
			printComparison("Room:", source[i]->getType(), "appleEaten", static_cast<Math*>(dest[i])->getAppleEaten(), static_cast<Math*>(source[i])->getAppleEaten());
		}
		if(source[i]->getType() == "Men's Bathroom"){
			printComparison("Room:", source[i]->getType(), "holeVisible", static_cast<MensBathroom*>(dest[i])->getHoleVisible(), static_cast<MensBathroom*>(source[i])->getHoleVisible());
		}

		compareInventory(dest[i]->getInventory(), source[i]->getInventory());
		compareCreature(dest[i]->getZombie(), source[i]->getZombie());
	}
}
void GameState::compareInventory(Inventory* dest, Inventory* source){
	//Copying removable room items
	vector<Item*> sourceItems = source->getItems();
	vector<Item*> destItems = dest->getItems();
	int i;

	cout << "Comparing inventories...\n";
	printComparison("Inventory:", source->getInventoryType(), "num of items", destItems.size(), sourceItems.size());

	if(source->getInventoryType() == "Player"){
		PlayerInventory* dest0 = static_cast<PlayerInventory*>(dest);
		PlayerInventory* source0 = static_cast<PlayerInventory*>(source);
		//Update size, if needed
		printComparison("Inventory:", source->getInventoryType(), "size", dest0->getSize(), source0->getSize());
	}
	for(i = 0; i < (int)sourceItems.size(); i++){
		if(dest->findItem(sourceItems[i]->getName()) == NULL){
			printComparison("Item:", "", "name", destItems[i]->getName(), sourceItems[i]->getName());
		}
	}
}

void GameState::compareCreature(Creature* destCr, Creature* sourceCr){
	// printComparison("Creature:", "ptr", "ptr", destCr, sourceCr);
	if( sourceCr != NULL && destCr != NULL ){
		cout << "Comparing creatures...\n";
		printComparison("Creature:", "", "isAlive", destCr->isAlive(), sourceCr->isAlive());
		printComparison("Creature:", "", "health", destCr->getHealth(), sourceCr->getHealth());
		printComparison("Creature:", "", "defense", destCr->getDefense(), sourceCr->getDefense());
	}
}

void GameState::comparePlayer(Player* dest, Player* source){
	cout << "Comparing players...\n";
	compareInventory(dest->getInventory(), source->getInventory());
	compareCreature(dest->getPlayer(), source->getPlayer());
}
