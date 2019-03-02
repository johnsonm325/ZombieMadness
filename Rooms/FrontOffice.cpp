#include "FrontOffice.h"

FrontOffice::FrontOffice() : Space("Front Office")
{
	paSystem = new Item();
	string description = "# This is the system that the principal uses to call students to the office.\n# Maybe I can have a little fun with this.";
	string name = "PA system";
	paSystem->setDummyItem(description, name);
	string text = "# You push the button and speak loudly over the intercom, 'GOOD MORNING VIETNAM!!!'\n# ... No response.'";
	paSystem->setAction(text, Use);
	roomInventory->addItem(paSystem);

	detentionList = new Item();
	description = "# On top of one of the desks you spot a list titled 'Detention List'.";
	text = "# You pick it up and read the names on the list:\n# Colt Robinson\n# Michael Johnson\n# Jeremy Einhorn\n# Artem Slivka\n# Ray Rayberson";
	name = "detention list";
	detentionList->setDummyItem(description, name);
	detentionList->setAction(text, Read);
	roomInventory->addItem(detentionList);
}

FrontOffice::~FrontOffice()
{

}

void FrontOffice::printIntro(){
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		cout << "# As you step in, you hear a sound closeby, you're not sure if it's in the room" << endl;
		cout << "# you are in, or if it's in another. The stench is strong here though, and it" << endl;
		cout << "# gives you a very uneasy feeling in your stomach." << endl;
		cout << "#" << endl;
	}

	cout << "# There is a PA system on the desk and a piece of paper that says, 'Detention List'" << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void FrontOffice::printExitDesc()
{
	if (firstTry == true)
	{
		firstTime();
		cout << "# As you leave, you remember how many times you were called down here." << endl;
		cout << "# 'If only Ray kept his mouth shut about the thumbtack I placed on Ms. Brembal's" << endl;
		cout << "# chair, I would have gotten away with that cleanly for sure and would have" << endl;
		cout << "# never had to come down here... Ok well maybe not that one time at least...'" << endl;
		cout << "#" << endl;
	}

	cout << "# You have a clear shot to the principal's office from here, could be some goodies" << endl;
	cout << "# in there!" << endl;
	cout << "#" << endl;
}

int FrontOffice::menu(vector<string> commandVector)
{
	// Evaluates if player is dead and exits the function
	if (coltGone())
	{
		return 40;
	}

	return 0;
}

void FrontOffice::usePA()
{
	static_cast<PrincipalsOffice*>(findRoom("Principal's Office"))->getZombie()->die();
}
