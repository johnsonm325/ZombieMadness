#include "FrontLobby.h"

FrontLobby::FrontLobby() : Space("Front Lobby")
{
	
}
void FrontLobby::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# As you enter this large foyer, you can see the struggle that students and teachers had to get out. Many bodies are still there" << endl;
		cout << "# and it's just a matter of time before they all turn into zombies. As you look at the front door for your exit, you immediately" << endl;
		cout << "# see a large group of zombies standing at the entrance, trying to push their way in. Someone has chained and barred the doors" << endl;
		cout << "# so that nothing could get in. 'Well, I'm defintely not getting out that way.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Benches line the walls and other benches have been turned over throughout the room. Trophy cases can also be seen on the" << endl;
	cout << "# east and west walls and there are lots of student's items to be searched." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
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

void FrontLobby::zombiesDead()
{
	deadZombies = true;
}

bool FrontLobby::coltGone()
{
	return goneColt;
}

bool FrontLobby::itemSearch(vector<string> inv, string a)
{
	return false;
}
