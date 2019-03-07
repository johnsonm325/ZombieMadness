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
			cout << KMAG "# A solitary zombie is standing in the middle of the room. She appears to just be" << endl;
			cout << "# standing there, looking at nothing. 'I guess they don't really have anything to" << endl;
			cout << "# but eat' you say." << endl;
			cout << "#" << endl;
			cout << "# The zombie hears your voice and begins to make her way towards you... to feast." << endl;
		}
		else {
			cout << KMAG "# As you enter this large foyer, you can see the struggle that students and teachers" << endl;
			cout << "# had to get out. Many bodies are still there and it's just a matter of time before" << endl;
			cout << "# they all turn into zombies. As you look at the front door for your exit, you" << endl;
			cout << "# immediately see a large group of zombies standing at the entrance, trying to push" << endl;
			cout << "# their way in. Someone has chained and barred the doors so that nothing could get in." << endl;
			cout << "# 'Well, I'm defintely not getting out that way.'" << endl;
			cout << "#" << endl;
		}
	}

	cout << KMAG "# Benches line the walls and other benches have been turned over throughout the room." << endl;
	cout << "# Trophy display cases can also be seen on the east and west walls." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# The only ways out of this room are back to the hallway or heading into the" << endl;
		cout << "# front office to get to the principal's office." << endl;
		cout << "#" << endl;
	}

	cout << "# Head west to get back to the hallway and east to head into the front office. You" << endl;
	cout << "# can also head south to get into the math classroom." RESET << endl;
	cout << "#" << endl;

	if (didDieOnEnter)
	{
		cout << KRED "# Oh no! There is a zombie in here and you do not have any weapons to fight it with." << endl;
		cout << "# It is too late to run and the zombie feasted on you, game over!" RESET << endl << endl;
		return;
	}

	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}
