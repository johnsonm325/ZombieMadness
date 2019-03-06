#include "Library.h"

Library::Library() : Space("Library")
{
	ladder = new Item();
	string description = "# There is a ladder leaning against one of the bookshelves. It looks\n# like you could climb it.";
	string name = "ladder";
	ladder->setDummyItem(description, name);
	string text = "# You climb the to the top of the ladder. The tops of the shelves are dusty\n# and there are a lot of books you've never heard of. Doesn't seem\n# to be anything special going on here.";
	ladder->setAction(text, Use);
	roomInventory->addItem(ladder);

	book = new Item();
	description = "# The library is full of books. You reach up to grab a specific book. 'Wow,\n# this is the biggest book ever. What's it called? Moby Dick. Yeah,\n# I'll never be reading that...' You put the book back on the shelf.";
	name = "book";
	book->setDummyItem(description, name);
	text = "# Call me Ishmael. Some years ago - never mind how long precisely - having little\n# or no money in my purse, and nothing particular to interest me on shore, I thought\n# I would sail about a little and see the watery part of the world. It is a way I have of\n# driving off the spleen and regulating the circulation. Whenever I find myself growing grim\n# about the mouth; whenever it is a damp, drizzly November in my soul; whenever I find\n# myself involuntarily pausing before coffin warehouses, and bringing up the rear of every\n# funeral I meet; and especially whenever my hypos get such an upper hand of me, that it\n# requires a strong moral principle to prevent me from deliberately stepping into the street,\n# and methodically knocking people's hats off - then, I account it high time to get to sea\n# as soon as I can. This is my substitute for pistol and ball. With a philosophical flourish\n# Cato throws himself upon his sword; I quietly take to the ship. There is nothing surprising\n# in this. If they but knew it, almost all men in their degree, some time or other, cherish\n# very nearly the same feelings towards the ocean with me.";
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
		cout << "# As expected, you wak into a room lined with tall shelves, making it very difficult" << endl;
		cout << "# to see much of anything. As big as this room is, you know you can probably find" << endl;
		cout << "# some good items in here to help you survive this school. 'Let's get what we need" << endl;
		cout << "# and out of here quickly. I don't like libraries.'" << endl;
		cout << "#" << endl;
	}

	cout << "# There are 5 rows of long book cases that run along most of the length of the room" << endl;
	cout << "# from east to west. Leaning against one of the bookshelves is a ladder, and the shelves" << endl;
	cout << "# are filled with books." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# The biology classroom and hallway are both accessible from here." << endl;
		cout << "#" << endl;
	}

	cout << "# The classroom is to the south and you can get to the hallway by going east." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void Library::useLadder()
{
	static_cast<FrontLobby*>(findRoom("Front Lobby"))->getZombie()->die();
}
