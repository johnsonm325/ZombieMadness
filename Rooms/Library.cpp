#include "Library.h"


Library::Library() : Space("Library")
{
	ladder = new Item();
	string description = "# There is a ladder leaning against one of the bookshelves. It looks like you could climb it.";
	string name = "ladder";
	ladder->setDummyItem(description, name);

	roomInventory->addItem(ladder);
}

void Library::printIntro(){
	// Prints the first time the room is visited	
	if (firstTry == true)
	{
		firstTime();
		cout << "# As expected, you walk into a room lined with tall shelves, making it very difficult to see much of anything." << endl;
		cout << "# As big as this room is, you know you can probably find some good items in here to help you survive this school." << endl;
		cout << "# 'Let's get what we need and out of here quickly. I don't like libraries.'" << endl;
		cout << "#" << endl;
	}

	cout << "# There are 5 rows of long book cases that run along most of the length of the room from east to west." << endl;
	cout << "# A circular librarian's stations sits in the middle of the room." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

int Library::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

        if ((commandVector[0].compare("use") == 0 || commandVector[0].compare("climb") == 0) && commandVector[1].compare("ladder") == 0) {
                useLadder();
        }

        else {
                cout << "# You can't " << commandVector[0] << " the " << commandVector[1] << "." << endl << "#" << endl;
        }
	
	return 0;
}


void Library::useLadder()
{
	cout << "# You climb the to the top of the ladder. The tops of the shelves are dusty and there are a lot of books you've never heard of. Doesn't seem to be anything special going on here." << endl << "#" << endl;
	fl = static_cast<FrontLobby*>(findRoom("Front Lobby"));
	fl->zombiesDead();
}


void Library::firstTime()
{
	firstTry = false;
}


bool Library::coltGone()
{
	return goneColt;
}


bool Library::itemSearch(vector<string> inv, string a)
{
	return false;
}
