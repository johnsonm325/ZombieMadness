#include "MensBathroom.h"


MensBathroom::MensBathroom() : Space("Men's Bathroom")
{
	toilet = new Item();
	string description = "# The toilet is dirty. Looks like it hasn't been cleaned in weeks. As you stare at the toilet, you notice a hole behind the toilet.";
	string name = "toilet";
	toilet->setDummyItem(description, name);
	toilet->setFeature();
	roomInventory->addItem(toilet);
}

void MensBathroom::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# You jump awake, realizing that you've been asleep on the toilet for quit a while. I guess staying up so late" << endl;
		cout << "# studying has taken its toll on you. 'How long have I been asleep?' you ask yourself. 'Have I missed all of my" << endl;
		cout << "# classes?' Something doesn't seem right to you. The emergency lights are on and you don't hear any noises" << endl;
		cout << "# outside of the door. 'Maybe everyone left and someone shut off the lights for the night." << endl;
		cout << "#" << endl;
		cout << "# You pull off a few squares of tissue paper and wipe your butt, now crusted up from the hours your feces spent" << endl;
		cout << "# drying while you were asleep. It hurts to move your legs since they have fallen asleep from sitting too long." << endl;
		cout << "# You finish wiping, stand up, pull up your pants and examine the room around you. 'Well, I guess I need to" << endl;
		cout << "# get out of here.' You step out of the stall, and into the bathroom." << endl;
		cout << "#" << endl;
	}

	cout << "# Sinks stand against the west wall, and urinals and toilets line the east wall. Nothing much going on in here." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
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
	string description = "# There is a small hole behind the toilet. It looks like you could probably fit through it.";
	string name = "hole";
	hole->setDummyItem(description, name);
	hole->setFeature();
	roomInventory->addItem(hole);
}

bool MensBathroom::getHoleVisible()
{
	return holeVisible;
}

bool MensBathroom::coltGone()
{
	return goneColt;
}

bool MensBathroom::itemSearch(vector<string> inv, string a)
{
	return false;
}

