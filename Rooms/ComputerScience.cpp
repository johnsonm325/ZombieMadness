#include "ComputerScience.h"

ComputerScience::ComputerScience() : Space("Computer Science")
{
	this->roomInventory->addItem(new Sword());

	computer = new Item();
	string description = "# One computer remains on in the room. All others are turned off.";
	string name = "computer";
	computer->setDummyItem(description, name);
	string text = "# You click around on the screen. There is a black screen with some green text on it.\n# You don't understand it. 'This must be what code is.'\n# int main()\n# {\n#\t	cout << \"Hello World\" << endl;\n#\t	return 0;\n# }";
	computer->setAction(text, Read);
	roomInventory->addItem(computer);

	whiteboard = new Item();
	description = "# There are some terms and definitions written on the board.";
	name = "whiteboard";
	whiteboard->setDummyItem(description, name);
	text = "# Class: In object-oriented programming, a class is an extensible program-code-template for creating objects,\n# providing initial values for state (member variables) and implementations of behavior (member functions or methods).";
	whiteboard->setAction(text, Read);
	roomInventory->addItem(whiteboard);
}

ComputerScience::~ComputerScience(){

}

void ComputerScience::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# 'Ahh, the nerd class. But, now that I think about it, maybe they would be able to fare better than" << endl;
		cout << "# me right now. I remember hearing that someone had created some sort of program to hack the school" << endl;
		cout << "# infrastructure and mess with the lighting and locks on some of the doors.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Computers fill the room, some of them turned on, and the whiteboard on the north wall has some weird" << endl;
	cout << "# symbols and characters that you don't understand. Must be code." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void ComputerScience::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'I actually am somewhat envious of the com sci kids, they seem really smart and cool" << endl;
		cout << "# and they really have it made out for them career-wise.'  This room has a lot to offer" << endl;
		cout << "# so you should keep this one in mind!" << endl;
		cout << "#" << endl;
	}

	cout << "# You vividly remember the math room being right next to the computer science room (makes sense)." << endl;
	cout << "# You also remember the long hallway you have to take to get in the computer science room." << endl;
	cout << "#" << endl;
}

int ComputerScience::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}


