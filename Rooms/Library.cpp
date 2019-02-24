#include "Library.h"

Library::Library() : Space("Library")
{
	ladder = new Item();
	string description = "# There is a ladder leaning against one of the bookshelves. It looks like you could climb it.";
	string name = "ladder";
	ladder->setDummyItem(description, name);
	string text = "# You climb the to the top of the ladder. The tops of the shelves are dusty and there are a lot of books you've never heard of.\n# Doesn't seem to be anything special going on here.";
	ladder->setAction(text, Use);
	roomInventory->addItem(ladder);

	book = new Item();
	description = "# The library is full of books. You reach up to grab a specific book. 'Wow, this is the biggest book ever.\n# What's it called? Moby Dick. Yeah, I'll never be reading that...' You put the book back on the shelf.";
	name = "book";
	book->setDummyItem(description, name);
	text = "# Call me Ishmael. Some years ago - never mind how long precisely - having little or no money in my purse,\n# and nothing particular to interest me on shore, I thought I would sail about a little and see the watery part of\n# the world. It is a way I have of driving off the spleen and regulating the circulation. Whenever I find myself\n# growing grim about the mouth; whenever it is a damp, drizzly November in my soul; whenever I find\n# myself involuntarily pausing before coffin warehouses, and bringing up the rear of every funeral I meet;\n# and especially whenever my hypos get such an upper hand of me, that it requires a strong moral\n# principle to prevent me from deliberately stepping into the street, and methodically knocking people's hats off -\n# then, I account it high time to get to sea as soon as I can. This is my substitute\n# for pistol and ball. With a philosophical flourish Cato throws himself upon his sword; I quietly take to\n# the ship. There is nothing surprising in this. If they but knew it, almost all\n# men in their degree, some time or other, cherish very nearly the same\n# feelings towards the ocean with me.";
	book->setAction(text, Read);
	roomInventory->addItem(book);
}

Library::~Library()
{
	
}

void Library::printIntro(){
	// Prints the first time the room is visited	
	if (firstTry == true)
	{
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

void Library::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Psh libraries... I mean, I probably have access to all these books on my iPad FOR FREE.'" << endl;
		cout << "# Don't let your misplaced digust for books stop you, the library was always full of cool things." << endl;
		cout << "# And it's so massive, maybe if you take your time in there, you'll find someting useful!" << endl;
		cout << "#" << endl;
	}

	cout << "# You have access to the first floow hallway as well as direct" << endl;
	cout << "# access to the biology room." << endl;
	cout << "#" << endl;
}

int Library::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	
	return 0;
}

void Library::useLadder()
{
	static_cast<FrontLobby*>(findRoom("Front Lobby"))->zombiesDead();
}
