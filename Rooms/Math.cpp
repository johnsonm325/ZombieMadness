#include "Math.h"
#define KMAG  "\x1B[35m"
#define RESET "\x1B[0m"

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

	roomInventory->addItem(new FirstAid());
}

Math::~Math(){

}

void Math::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << KMAG "# As you walk in you're met with a pile of dead bodies on the floor. You can't" << endl;
		cout << "# tell if they are dead or undead. You scan the room looking for any kind of" << endl;
		cout << "# items or clues that will help you get out of this place. You now wish you" << endl;
		cout << "# had payed a little more attention to your surroundings so you could use some" << endl;
		cout << "# of the items here to your advantage." << endl;
		cout << "#" << endl;
	}

	cout << KMAG "# Desks fill the center of the room and the teacher's desk is on the east wall" << endl;
	cout << "# in the corner. There is an apple on the teacher's desk and calculators on" << endl;
	cout << "# the the student's desks the north and south walls" << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# From here, there are two ways to get to the front lobby from here, through" << endl;
		cout << "# the door on the north wall or out to the hallway where you can head north." << endl;
		cout << "#" << endl;
	}

	cout << "# Head north to get out to the lobby and to the west to get back out to the hallway." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Math::eatApple()
{
	appleEaten = true;
}

bool Math::getAppleEaten()
{
	return appleEaten;
}
