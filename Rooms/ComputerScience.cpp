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

}

void ComputerScience::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << KMAG "# 'Ahh, the nerd class. But, now that I think about it, maybe they would be" << endl;
		cout << "# able to fare better than me right now. They would probably be able to" << endl;
		cout << "# create some sort of program to hack the school infrastructure and kill" << endl;
		cout << "# all fo the zombies or something.'" << endl;
		cout << "#" << endl;
	}

	cout << KMAG "# Computers fill the room, some of them turned on. The whiteboard on the" << endl;
	cout << "# north wall has definition on it and one computer has some weird symbols and" << endl;
	cout << "# characters that you don't understand. Must be code." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# Only one way out of here, and that's back through the hallway." << endl;
		cout << "#" << endl;
	}

	cout << "# To get back to the hallway, just head west." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}
