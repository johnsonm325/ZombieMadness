#include "SecondFloorHallway.h"


SecondFloorHallway::SecondFloorHallway() : Space("Second Floor Hallway")
{
	
}
void SecondFloorHallway::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "You walk into the second floor hallway and immediately notice that everything is dark, save the emergency lights." << endl;
		cout << "Something is not right here, you tell yourself. The air has an awful smell that you can't describe. And what's" << endl;
		cout << "worse, you can see blood smears on the walls and floor. 'Oh my god, what has happened here?!' You feel your" << endl;
		cout << "heart begin to race, and you start breathing heavy, looking around for some danger that you begin to sense." << endl;
		cout << endl;
		cout << "That's when you notice a few bodies, lying on the ground through out the hallway. None of them are moving, and" << endl;
		cout << "they appear to be dead. 'What is happening!?'" << endl;
		cout << endl;
	}

	cout << "Bulletin boards line the walls and there is lots of debris strewn across the floor." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int SecondFloorHallway::menu()
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();	
	return 0;
}


void SecondFloorHallway::inspectToilet()
{

}


bool SecondFloorHallway::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool SecondFloorHallway::coltGone()
{
	return goneColt;
}


bool SecondFloorHallway::itemSearch(vector<string> inv, string a)
{
	return false;
}
