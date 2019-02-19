#include "SecondFloorHallway.h"


SecondFloorHallway::SecondFloorHallway() : Space("Second Floor Hallway")
{
	deadBody = new Item();
	string description = "As you touch the skin of the body, you draw your hand back quickly. The skin feels soft and cold. Your finger indentations are left on the skin and you notice that you actually broke the skin with your light touch. You slowly roll the body over to see a large gaping wound and the smell of rotten meat fill your nose. You gag from the sight and smell and drop the body, quickly stepping away.";
	string name = "dead body";
	deadBody->setDummyItem(description, name);
	roomInventory->addItem(deadBody);

	bulletinBoard = new Item();
	description = "Lots of papers have been pinned to the board showing different school events this month. Nothing special here.";
	name = "bulletin board";
	bulletinBoard->setDummyItem(description, name);
	roomInventory->addItem(bulletinBoard);
}

SecondFloorHallway::SecondFloorHallway(bool firstTry) : Space("Second Floor Hallway")
{
	this->firstTry = firstTry;
}

void SecondFloorHallway::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# You walk into the second floor hallway and immediately notice that everything is dark, save the emergency lights." << endl;
		cout << "# Something is not right here, you tell yourself. The air has an awful smell that you can't describe. And what's" << endl;
		cout << "# worse, you can see blood smears on the walls and floor. 'Oh my god, what has happened here?!' You feel your" << endl;
		cout << "# heart begin to race, and you start breathing heavy, looking around for some danger that you begin to sense." << endl;
		cout << "#" << endl;
		cout << "# That's when you notice a few bodies, lying on the ground through out the hallway. None of them are moving, and" << endl;
		cout << "# they appear to be dead. 'What is happening!?'" << endl;
		cout << "#" << endl;
	}

	cout << "# Bulletin boards line the walls and there is lots of debris strewn across the floor." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

int SecondFloorHallway::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

	return 0;
}


void SecondFloorHallway::firstTime()
{
	firstTry = false;
}


bool SecondFloorHallway::coltGone()
{
	return goneColt;
}


bool SecondFloorHallway::itemSearch(vector<string> inv, string a)
{
	return false;
}
