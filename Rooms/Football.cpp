#include "Football.h"


Football::Football() : Space("Football Field")
{
	lockDoor();
	this->zombie = new Zombie(true);
}
void Football::printIntro()
{
	cout << "# 'Looks like this is the way out.' You look across the dark field, fog creeping across the ground and" << endl;
	cout << "# spot a heart-stopping sight as a large zombie is seen standing between you and your exit. The zombie" << endl;
	cout << "# is larger than most, and you immediately recognize him. It's your fellow football teammate, Scott," << endl;
	cout << "# the middle linebacker. You remember that he weighs in at a whopping 310 pounds, and every bit of" << endl;
	cout << "# his weight adds to the fear in your body." << endl;
	cout << "#" << endl;
	cout << "# He spots you almost immediately and lets out a gargled yell. In a span of seconds, he begins sprinting" << endl;
	cout << "# in your direction. 'Wow, I had no idea he could run that fast!'" << endl;
	cout << "#" << endl;

	cout << "# What do you do?" << endl;
	cout << "#" << endl;
}

void Football::printExitDesc()
{
	cout << "# YOU DID IT!!!! Scott put up on hell of a fight but you didn't let that phase you!" << endl;
	cout << "# As you run as far away from the school as possible, you look behind you and look at the devestation." << endl;
	cout << "# 'Worst day of school... EVER.'" << endl;
	cout << "#" << endl;
}

int Football::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();	
	return 0;
}


void Football::zombiesDead()
{
	deadZombies = true;
}


void Football::firstTime()
{
	firstTry = false;
}


bool Football::coltGone()
{
	return goneColt;
}


bool Football::itemSearch(vector<string> inv, string a)
{
	return false;
}
