#include "MensBathroom.h"

MensBathroom::MensBathroom() : Space("Men's Bathroom")
{
	toilet = new Item();
	string description = "# The toilet is dirty. Looks like it hasn't been cleaned in weeks. As you\n# stare at the toilet, you notice a hole behind the toilet.";
	string name = "toilet";
	toilet->setDummyItem(description, name);
	roomInventory->addItem(toilet);
}

MensBathroom::~MensBathroom(){

}

void MensBathroom::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# You jump awake, realizing that you've been asleep on the toilet for quit a while." << endl;
		cout << "# I guess staying up so late studying has taken its toll on you. 'How long have I" << endl;
		cout << "# been asleep?' you ask yourself. 'Have I missed all of my classes?' Something" << endl;
		cout << "# doesn't seem right to you. The emergency lights are on and you don't hear any" << endl;
		cout << "# noises outside of the door. 'Maybe everyone left and someone shut off the lights" << endl;
		cout << "# for the night." << endl;
		cout << "#" << endl;
		cout << "# You pull off a few squares of tissue paper and wipe. It hurts to move your legs" << endl;
		cout << "# since they have fallen asleep from sitting too long. You finish wiping, stand" << endl;
		cout << "# up, pull up your pants and examine the room around you. 'Well, I guess I need" << endl;
		cout << "# to get out of here.' You step out of the stall, and into the bathroom." << endl;
		cout << "#" << endl;
	}

	cout << "# Sinks stand against the west wall, and urinals and toilets line the east wall. Nothing" << endl;
	cout << "# much going on in here." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void MensBathroom::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# 'Well, here goes nothing... Let's hope the front doors aren't locked." << endl;
		cout << "# You really are unsure if anyone is left in the school right now, or if" << endl;
		cout << "# you'll get in trouble. Looks like there's only one way out." << endl;
		cout << "#" << endl;
	}

	cout << "# Never forget where you came from! This room managed to keep you alive" << endl;
	cout << "# while you were asleep, maybe it's a magical bathroom?  Anyways," << endl;
	cout << "# you can only really go out into the 2nd floor hallway..." << endl;
	cout << "#" << endl;
}

int MensBathroom::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 0;
	}

	return 0;
}

void MensBathroom::inspectToilet()
{
	holeVisible = true;

	hole = new Item();
	string description = "# There is a small hole behind the toilet. It looks like you could\n# probably fit through it.";
	string name = "hole";
	hole->setDummyItem(description, name);
	roomInventory->addItem(hole);
}

bool MensBathroom::getHoleVisible()
{
	return holeVisible;
}

