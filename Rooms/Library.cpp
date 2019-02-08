#include "Library.h"


Library::Library() : Space("Library")
{
	
}

void Library::printIntro(){
	// Prints the first time the room is visited	
	if (firstTry == true)
	{
		firstTime();
		cout << "As expected, you walk into a room lined with tall shelves, making it very difficult to see much of anything." << endl;
		cout << "As big as this room is, you know you can probably find some good items in here to help you survive this school." << endl;
		cout << "'Let's get what we need and out of here quickly. I don't like libraries.'" << endl;
		cout << endl;
	}

	cout << "There are 5 rows of long book cases that run along most of the length of the room from east to west." << endl;
	cout << "A circular librarian's stations sits in the middle of the room." << endl;
	cout << endl;
	cout << "What do you do now?" << endl;
	cout << endl;
}

int Library::menu()
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	
	return 0;
}


void Library::inspectToilet()
{

}


bool Library::firstTime()
{
	firstTry = false;
	return firstTry;
}


bool Library::coltGone()
{
	return goneColt;
}


bool Library::itemSearch(vector<string> inv, string a)
{
	return false;
}
