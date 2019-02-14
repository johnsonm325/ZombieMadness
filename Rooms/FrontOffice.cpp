#include "FrontOffice.h"


FrontOffice::FrontOffice() : Space("Front Office")
{
	paSystem = new Item();
	string description = "# This is the system that the principal uses to call students to the office. Maybe I can have a little fun with this.";
	string name = "PA system";
	paSystem->setDummyItem(description, name);

	roomInventory->addItem(paSystem);
}

void FrontOffice::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "# As you step in, you hear a sound closeby, you're not sure if it's in the room you are in, or if it's in another." << endl;
		cout << "# The stench is strong here though, and it gives you a very uneasy feeling in your stomach." << endl;
		cout << "#" << endl;
	}

	cout << "# Two desks sit at the north wall, each with a computer." << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

int FrontOffice::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

        if ((commandVector[0].compare("use") == 0 || commandVector[0].compare("talk") == 0) && (commandVector[1].compare("PA") == 0 || commandVector[1].compare("pa") == 0)) {
                usePA();
        }

        else {
                cout << "# You can't " << commandVector[0] << " the " << commandVector[1] << "." << endl << "#" << endl;
        }

	return 0;
}


void FrontOffice::usePA()
{
	cout << "# You push the button and speak loudly over the intercom, 'GOOD MORNING VIETNAM!!!' ... No response.'" << endl << "#" << endl;
	prin = static_cast<PrincipalsOffice*>(findRoom("Principal's Office"));
	prin->zombiesDead();
}


void FrontOffice::firstTime()
{
	firstTry = false;
}


bool FrontOffice::coltGone()
{
	return goneColt;
}


bool FrontOffice::itemSearch(vector<string> inv, string a)
{
	return false;
}
