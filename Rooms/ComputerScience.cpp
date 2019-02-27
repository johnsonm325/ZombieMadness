#include "ComputerScience.h"

ComputerScience::ComputerScience() : Space("Computer Science")
{
	this->roomInventory->addItem(new Sword());

	computer = new Item();
	string description = "# One computer remains on in the room. All others are turned off.";
	string name = "computer";
	computer->setDummyItem(description, name);
	string text = "# You click around on the screen. There is a black screen with some green text\n# on it. You don't understand it. 'This must be what code is.'\n# int main()\n# {\n#\t	cout << \"Hello World\" << endl;\n#\t	return 0;\n# }";
	computer->setAction(text, Read);
	roomInventory->addItem(computer);

	whiteboard = new Item();
	description = "# There are some terms and definitions written on the board.";
	name = "whiteboard";
	whiteboard->setDummyItem(description, name);
	text = "# Class: In object-oriented programming, a class is an extensible program-code-template for\n# creating objects, providing initial values for state (member variables)\n# and implementations of behavior (member functions or methods).";
	whiteboard->setAction(text, Read);
	roomInventory->addItem(whiteboard);
}

ComputerScience::~ComputerScience(){
	delete computer;
	delete whiteboard;
}

void ComputerScience::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# 'Ahh, the nerd class. But, now that I think about it, maybe they would be" << endl;
		cout << "# able to fare better than me right now. They would probably be able to" << endl;
		cout << "# create some sort of program to hack the school infrastructure and kill" << endl;
		cout << "# all fo the zombies or something.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Computers fill the room, some of them turned on, and the whiteboard on the" << endl;
	cout << "# north wall has some weird symbols and characters that you don't understand." << endl;
	cout << "# Must be code." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void ComputerScience::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'I actually am somewhat envious of the com sci kids, they seem really smart" << endl;
		cout << "# and they really have it made out for them career-wise.' This career path" << endl;
		cout << "# has a lot to offer so you should keep this one in mind!" << endl;
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

	return 0;
}


