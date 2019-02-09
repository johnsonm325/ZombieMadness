#include "Math.h"


Math::Math() : Space("Math")
{
	
}

void Math::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "As you walk in you're met with a pile of dead bodies on the floor. You can't tell if they are dead or undead." << endl;
		cout << "You scan the room looking for any kind of items or clues that will help you get out of this place. You now" << endl;
		cout << "wish you had payed a little more attention in this class so you could use some of the items here to your" << endl;
		cout << "advantage." << endl;
		cout << endl;
	}

	cout << "Desks fill the center of the room and the teacher's desk is on the east wall in the corner. A few shelves line" << endl;
	cout << "the north and south walls" << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int Math::menu()
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();	
	
	return 0;
}


void Math::inspectToilet()
{

}


void Math::firstTime()
{
	firstTry = false;
}


bool Math::coltGone()
{
	return goneColt;
}


bool Math::itemSearch(vector<string> inv, string a)
{
	return false;
}
