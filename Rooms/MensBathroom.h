#ifndef MENSBATHROOM_H
#define MENSBATHROOM_H

//#include "<someFile>.h"

class MensBathroom : public Space
{
private:
	string action;		//string action typed in by the user
	bool firstTry = true,
	     goneColt = false;

public:
	MensBathroom();
	int menu(vector<string>*);
	void inspectToilet();
	bool firstTime();
	bool coltGone();
	bool itemSearch(vector<string>, string); 	//function used to search character's inventory to see if they have items needed for a particular action
};
#endif
