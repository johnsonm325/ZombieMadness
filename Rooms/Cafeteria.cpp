#include "Cafeteria.h"

Cafeteria::Cafeteria() : Space("Cafeteria")
{
	food = new Item();
	string description = "# There are chunks of food strewn around the room. Some of it is gloopy, and you don't want to touch that. But some, you can pick up.";
	string name = "food";
	food->setDummyItem(description, name);
	roomInventory->addItem(food);
}

Cafeteria::~Cafeteria(){

}

void Cafeteria::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# You look around a see a few stray zombies littered throughout the large room. There is a lot of" << endl;
		cout << "# space in between them, so taking them out shouldn't be too hard. 'If I'm smart, I may be able to" << endl;
		cout << "# avoid them altogether.'" << endl;
		cout << "#" << endl;
	}

	cout << "# Long lunch tables fill the room and lunch trays are littered on the tables and floor. Food debris is" << endl;
	cout << "# thrown about the room." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
}

void Cafeteria::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# You are sad to leave to Cafeteria actually.  It didn't smell half as bad as the other rooms" << endl;
		cout << "# in this school and food!  'I don't want to leave the food room, it has food..." << endl;
		cout << "# Fooooooooooooooooooddddddddddddd'" << endl;
		cout << "#" << endl;
	}

	cout << "# You remember looking out the massive windows at the Football field during lunch" << endl;
	cout << "# and remember when you used to grab a quick snack before Gym class in the next room" << endl;
	cout << "#" << endl;
}

int Cafeteria::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

        if (commandVector[0].compare("throw") == 0 && commandVector[1].compare("food") == 0) {
                throwFood();
        }

        else {
                cout << "# You can't " << commandVector[0] << " the " << commandVector[1] << "." << endl << "#" << endl;
        }

	return 0;
}

void Cafeteria::throwFood()
{
	cout << "# You hurl the chunks of food across the room. They stick to the wall and satisfyingly slide down to the floor. 'I've always wanted to do that,' you say." << endl << "#" << endl;
	chem = static_cast<Chemistry*>(findRoom("Chemistry"));
	chem->zombiesDead();
}


