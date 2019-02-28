#include "FrontLobby.h"

FrontLobby::FrontLobby() : Space("Front Lobby")
{
	this->zombie = new Zombie(false);
	this->deadZombies = false;
	
	bench = new Item();
	string description = "# A bench sits in the middle of the room. There's a dead body slumped over it.";
	string name = "bench";
	bench->setDummyItem(description, name);
	string text = "You sit on the bench, next to the dead body. 'Woah, this is weird.\n# So, how's it going?' you ask; but get no response.";
	bench->setAction(text, Use);
	roomInventory->addItem(bench);

	displayCase = new Item();
	description = "# The display case has a bunch of trophies showing state championships\n# that the school has won over the years. You helped the\n# football team get one of the trophies last year. You can see\n# the team photo and spot yourself standing off to the end of the\n# line of teammates. You beam with pride. 'Ok, time to\n# get back to the issue at hand.";
	name = "display case";
	displayCase->setDummyItem(description, name);
	roomInventory->addItem(displayCase);
}

FrontLobby::~FrontLobby()
{
	
}

void FrontLobby::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# As you enter this large foyer, you can see the struggle that students and teachers had to get out. Many bodies are still there" << endl;
		cout << "# and it's just a matter of time before they all turn into zombies. As you look at the front door for your exit, you immediately" << endl;
		cout << "# see a large group of zombies standing at the entrance, trying to push their way in. Someone has chained and barred the doors" << endl;
		cout << "# so that nothing could get in. 'Well, I'm defintely not getting out that way.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Benches line the walls and other benches have been turned over throughout the room. Trophy cases can also be seen on the" << endl;
	cout << "# east and west walls and there are lots of student's items to be searched." << endl;

	if (zombie != NULL)
		cout << "# Oh no, a zombie is in here!" << endl;

	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void FrontLobby::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# Why is it that the easiest way to get in is the hardest way to get out? IS ANYTHING EASY?!" << endl;
		cout << "# Guess that is just the nature of being stuck in this school of death and horror." << endl;
		cout << "# 'If I make it through this mess, I will never use a front enterance ever again," << endl;
		cout << "# 'just in spite of how frustrating this is!!!'" << endl;
		cout << "#" << endl;
	}

	cout << "# The front lobby has access to some pretty import rooms.  There is the" << endl;
	cout << "# front office and then the principal's office.  Wait... you can raid the principal's office" << endl;
	cout << "# without getting in trouble? Maybe this isn't so bad..." << endl;
	cout << "#" << endl;
}

int FrontLobby::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}
