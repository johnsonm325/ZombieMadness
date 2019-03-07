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
		cout << KMAG "# As you step in, you hear a sound closeby, you're not sure if it's in the room" << endl;
		cout << "# you are in, or if it's in another. The stench is strong here though, and it" << endl;
		cout << "# gives you a very uneasy feeling in your stomach." << endl;
		cout << "#" << endl;
	}

	cout << KMAG "# There is a PA system on the desk and a piece of paper that says, 'Detention List'" << endl;
	cout << "#" << endl;
	if (firstTry == true)
	{
		firstTime();
		cout << "# From here, you can head right into the principal's office, or back to the front office." << endl;
		cout << "#" << endl;
	}

	cout << "# Go east to enter the principal's office and west to go back to the front lobby." RESET << endl;
	cout << "#" << endl;
	cout << "# What do you do now?" << endl;
	cout << "#" << endl;
}

void FrontOffice::usePA()
{
	static_cast<PrincipalsOffice*>(findRoom("Principal's Office"))->getZombie()->die();
}
