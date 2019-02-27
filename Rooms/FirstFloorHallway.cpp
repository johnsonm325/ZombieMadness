#include "FirstFloorHallway.h"

FirstFloorHallway::FirstFloorHallway() : Space("First Floor Hallway")
{
	vomit = new Item();
	string description = "# You can see you fresh pile of vomit on the floor. The smell comes up to\n# meet your nose and you almost gag.";
	string name = "vomit";
	vomit->setDummyItem(description, name);
	string text = "# You eat the vomit.\n# You are disgusting! What's wrong with you?!";
	vomit->setAction(text, Eat);
	roomInventory->addItem(vomit);

	bulletinBoard = new Item();
	description = "# The bulletin board has a bunch of pamphlets and flyers about events taking\n# place at school this month.";
	name = "bulletin board";
	bulletinBoard->setDummyItem(description, name);
	text = "# 'Football tryouts next Thursday! We'll provide the equipment. Come out and show\n# us what you're made of.";
	bulletinBoard->setAction(text, Read);
	roomInventory->addItem(bulletinBoard);
}

FirstFloorHallway::FirstFloorHallway(bool firstTry) : Space("First Floor Hallway")
{
	this->firstTry = firstTry;
}

FirstFloorHallway::~FirstFloorHallway(){

}

void FirstFloorHallway::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# This hallway doesn't look much better than the second floor. Blood is" << endl;
		cout << "# smeared everywhere and there are half-eaten bodies, and some with just" << endl;
		cout << "# holes chewed into their stomachs, just lying along the hallway. You" << endl;
		cout << "# wrench at the sight and throw up on the floor. These are people you" << endl;
		cout << "# went to school with and sat beside everyday. You finally steel your" << endl;
		cout << "# will and determine to move on." << endl;
		cout << "#" << endl;
	}

	cout << "# There are bulletin boards on the wall and your vomit is now on the floor." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void FirstFloorHallway::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# The first floor hallway is really useful in that it is connected to a lot of other rooms." << endl;
		cout << "# Just be watch your step for that vomit you just beautifully spewed out.... gross." << endl;
		cout << "#" << endl;
	}

	cout << "# Keep in mind how many different rooms can be visited from the first floor hallway!" << endl;
	cout << "#" << endl;
}

int FirstFloorHallway::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}
	printIntro();
	return 0;
}
