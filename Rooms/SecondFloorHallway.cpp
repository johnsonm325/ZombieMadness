#include "SecondFloorHallway.h"

SecondFloorHallway::SecondFloorHallway() : Space("Second Floor Hallway")
{
	string name, description;
	deadBody = new Item();
	description = "# As you touch the skin of the body, you draw your hand back quickly. The skin\n# feels soft and cold. Your finger indentations are left on the skin and you notice that\n# you actually broke the skin with your light touch. You slowly roll the body over to see a large gaping\n# wound and the smell of rotten meat fill your nose. You gag from the sight and smell and\n# drop the body, quickly stepping away.";
	name = "dead body";
	deadBody->setDummyItem(description, name);
	roomInventory->addItem(deadBody);

	bulletinBoard = new Item();
	description = "# Lots of papers have been pinned to the board showing different school events this month.\n# Nothing special here.";
	name = "bulletin board";
	bulletinBoard->setDummyItem(description, name);
	roomInventory->addItem(bulletinBoard);
}

SecondFloorHallway::~SecondFloorHallway(){

}

void SecondFloorHallway::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# You walk into the second floor hallway and immediately notice that everything is dark," << endl;
		cout << "# save the emergency lights. Something is not right here, you tell yourself. The air has" << endl;
		cout << "# an awful smell that you can't describe. And what's worse, you can see blood smears on" << endl;
		cout << "# the walls and floor. 'Oh my god, what has happened here?!' You feel your heart begin" << endl;
		cout << "# to race, and you start breathing heavy, looking around for some danger that you begin" << endl;
		cout << "# to sense." << endl;
		cout << "#" << endl;
		cout << "# That's when you notice a few bodies, lying on the ground through out the hallway. None" << endl;
		cout << "# of them are moving, and they appear to be dead. 'What is happening!?'" << endl;
		cout << "#" << endl;
	}

	cout << "# Bulletin boards line the walls and there are lots of dead bodies strewn across" << endl;
	cout << "# the floor." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		disableFirstTries();
		cout << "# Lots of classrooms and other rooms are connected to the hallway here. Six to be exact." << endl;
		cout << "# To get to these rooms." << endl;
		cout << "#" << endl;
	}

	cout << "# You can move north and south through the hallway to get to the rooms on the east and west." << endl;
	cout << "# You can also head downstairs using the stairwell on the south side of the hallway." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

//Function allows to print long intro only once for all rooms that share the same derived Space type
void SecondFloorHallway::disableFirstTries(){
	//Set firstTry boolean to false for all hallway rooms not visited yet 
	for(int i = 0; i < (int)roomsList.size(); i++){
		if(roomsList[i]->getType() == "Second Floor Hallway" && roomsList[i]->getFirstTry()){
			roomsList[i]->firstTime();
		}
	}
}
