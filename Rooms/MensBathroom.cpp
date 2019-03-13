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
		cout << KMAG "# You jump awake, realizing that you've been asleep on the toilet for quite a while." << endl;
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

	cout << KMAG "# Sinks stand against the west wall, and urinals and toilets line the east wall. Nothing" << endl;
	cout << "# much going on in here." << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# There's only one way out of this room, and that's the door I used to get in here." << endl;
		cout << "# The hallway seems eeriely quiet, making you more nervous about your situation." << endl;
		cout << "#" << endl;
	}

	cout << "# The door to the hallway is on the west wall" RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void MensBathroom::inspectToilet()
{
	setHoleVisible(true);
}

bool MensBathroom::getHoleVisible()
{
	return holeVisible;
}

void MensBathroom::setHoleVisible(bool visible){
	holeVisible = visible;

	hole = roomInventory->findItem("hole");
	if(hole != NULL){
		roomInventory->removeItem(hole);
		delete hole;
		hole = NULL;
	}

	if(holeVisible){
		hole = new Item();
		string description = "# There is a small hole behind the toilet. It looks like you could\n# probably fit through it.";
		string name = "hole";
		hole->setDummyItem(description, name);
		roomInventory->addItem(hole);
	}
}
