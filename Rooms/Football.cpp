#include "Football.h"

Football::Football() : Space("Football Field")
{
	lockDoor();
	this->zombie = new Zombie(true);

	football = new Item();
	string description = "# A football is resting in the middle of the field. Looks like a brand new ball.";
	string name = "football";
	football->setDummyItem(description, name);
	string text = "# You pick up the football and hurl it downfield. It looks to have gone about 50 yards.\n# Not a bad throw, you think.";
	football->setAction(text, Throw);
	roomInventory->addItem(football);

	pompom = new Item();
	description = "# One of the cheerleader's pom-poms was left on the field. I wonder which cheerleader...";
	name = "pom-pom";
	pompom->setDummyItem(description, name);
	text = "# You pick up the pom-pom and rehearse one of the cheers that you see the cheerleaders\n# do every game. You look around to make sure no one saw and put\n# the pom-pom back on the ground.";
	pompom->setAction(text, Use);
	roomInventory->addItem(pompom);
}

Football::~Football()
{
	
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
