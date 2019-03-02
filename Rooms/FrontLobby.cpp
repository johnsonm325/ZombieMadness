#include "FrontLobby.h"

FrontLobby::FrontLobby() : Space("Front Lobby")
{
	this->zombie = new Zombie(false);
	
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
		if (zombie->isAlive() == true) {
			cout << "# A solitary zombie is standing in the middle of the room. She appears to just be" << endl;
			cout << "# standing there, looking at nothing. 'I guess they don't really have anything to" << endl;
			cout << "# but eat' you say." << endl;
			cout << "#" << endl;
			cout << "# The zombie hears your voice and begins to make her way towards you... to feast." << endl;
		}
		else {
			cout << "# As you enter this large foyer, you can see the struggle that students and teachers" << endl;
			cout << "# had to get out. Many bodies are still there and it's just a matter of time before" << endl;
			cout << "# they all turn into zombies. As you look at the front door for your exit, you" << endl;
			cout << "# immediately see a large group of zombies standing at the entrance, trying to push" << endl;
			cout << "# their way in. Someone has chained and barred the doors so that nothing could get in." << endl;
			cout << "# 'Well, I'm defintely not getting out that way.'" << endl;
			cout << "#" << endl;
		}
	}

	cout << "# Benches line the walls and other benches have been turned over throughout the room." << endl;
	cout << "# Trophy display cases can also be seen on the east and west walls." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void FrontLobby::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# Why is it that the easiest way to get in is the hardest way to get out? IS ANYTHING" << endl;
		cout << "# EASY?! Guess that is just the nature of being stuck in this school of death and" << endl;
		cout << "# horror. 'If I make it through this mess, I will never use a front enterance ever" << endl;
		cout << "# again, just in spite of how frustrating this is!!!'" << endl;
		cout << "#" << endl;
	}

	cout << "# The front lobby has access to some pretty import rooms.  There is the" << endl;
	cout << "# front office and then the principal's office.  Wait... you can raid the principal's" << endl;
	cout << "# office without getting in trouble? Maybe this isn't so bad..." << endl;
	cout << "#" << endl;
}

int FrontLobby::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

	return 0;
}
