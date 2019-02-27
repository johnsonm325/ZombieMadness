#include "Math.h"

Math::Math() : Space("Math")
{
	calculator = new Item();
	string description = "# A calculator it sitting on top of one of the student's desks. It seems operational.";
	string name = "calculator";
	calculator->setDummyItem(description, name);
	string text = "# You pick up the calculator and start typing in 01134.\n# You turn the calculator upside down and it reads hEll0.";
	calculator->setAction(text, Use);
	roomInventory->addItem(calculator);

	apple = new Item();
	description = "# A small, red delicious apple sits on the teacher's desk. It looks delicious.";
	name = "apple";
	apple->setDummyItem(description, name);
	text = "# You bite into the juicy apple and the juice runs down your chin. It's absolutely delicious!";
	apple->setAction(text, Eat);
	roomInventory->addItem(apple);
}

Math::~Math(){

}

void Math::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# As you walk in you're met with a pile of dead bodies on the floor. You can't" << endl;
		cout << "# tell if they are dead or undead. You scan the room looking for any kind of" << endl;
		cout << "# items or clues that will help you get out of this place. You now wish you" << endl;
		cout << "# had payed a little more attention to your surroundings so you could use some" << endl;
		cout << "# of the items here to your advantage." << endl;
		cout << "#" << endl;
	}

	cout << "# Desks fill the center of the room and the teacher's desk is on the east wall" << endl;
	cout << "# in the corner. There is an apple on the teacher's desk and calculators on" << endl;
	cout << "# the the student's desks the north and south walls" << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Math::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'I was so bad at math, it's a miracle I didn't die in that class!'" << endl;
		cout << "# The math room was not your favorite in general, you always felt like you" << endl;
		cout << "# were behind all the other students.  Don't worry Colt, if you make it" << endl;
		cout << "# out of here, you can be assured you are better than they are! Cause, you" << endl;
		cout << "# know... you're alive and what not... and they are dead..." << endl;
		cout << "#" << endl;
	}

	cout << "# The front lobby can be reached from here so maybe check that out. The first floor" << endl;
	cout << "# hallway is right outside too and that always gives you a lot of places to go." << endl;
	cout << "#" << endl;
}

int Math::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	return 0;
}

void Math::eatApple()
{
	appleEaten = true;
}

bool Math::getAppleEaten()
{
	return appleEaten;
}
