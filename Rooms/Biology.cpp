#include "Biology.h"

Biology::Biology() : Space("Biology")
{
	this->roomInventory->addItem(new Rocks());
}

Biology::~Biology(){

}

void Biology::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# The room has a lot of plants and cases with dissected animals. 'This was never my favorite subject, but I did enjoy" << endl;
		cout << "# cutting open frogs to see what was inside of them." << endl;
		cout << "#" << endl;
	}

	cout << "# The room has a mixture of desks and tables. There are a good deal of items and tools for gardening." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Biology::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Peace out frogs!  I can't wait to get away from that smell, horrid..." << endl;
		cout << "# Yet, this entire place could not smell any worse thanks to my lovely dead classmates" << endl;
		cout << "# and teachers!'" << endl;
		cout << "#" << endl;
	}

	cout << "# 'I remember the library being really close to the Biology room, the Math room and Chemistry room" << endl;
	cout << "# were close by here too.'" << endl;
	cout << "#" << endl;
}

int Biology::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}

