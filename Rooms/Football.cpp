#include "Football.h"
#define KMAG  "\x1B[35m"
#define RESET "\x1B[0m"

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
	if (zombie->isAlive()) {
		cout << KMAG "# 'Looks like this is the way out.' You look across the dark field, fog creeping across" << endl;
		cout << "# the ground and spot a heart-stopping sight as a large zombie is seen standing between" << endl;
		cout << "# you and your exit. The zombie is larger than most, and you immediately recognize him." << endl;
		cout << "# It's your fellow football teammate, Scott, the middle linebacker. You remember that he" << endl;
		cout << "# weighs in at a whopping 310 pounds, and every bit of his weight adds to the fear in" << endl;
		cout << "# your body." << endl;
		cout << "#" << endl;
		cout << "# He spots you almost immediately and lets out a gargled yell. In a span of seconds, he" << endl;
		cout << "# begins sprinting in your direction. 'Wow, I had no idea he could run that fast!'" << endl;
		cout << "#" << endl;
	}

	else {
		cout << KMAG "# There's a football on the field and a pompom over by the bleachers." << endl;
		cout << "#" << endl;
	}

	if (firstTry == true) {
		firstTime();
		cout << "# Finally, the exit! I'm so close to getting out of here and back home." << endl;
		cout << "#" << endl;
	}
	cout << "# The exit is through the football field to the gates at the south." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do?" << endl;
	cout << "#" << endl;
}
