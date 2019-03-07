#include "School.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{

	srand(time(NULL));

	School school;
	school.beginGame();

	return 0;
}
