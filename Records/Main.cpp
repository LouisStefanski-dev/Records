#include "List.h"
#include <iostream>

int main()
{
	List newList;
	if (!newList.readInRecords("names.txt")) { return 1; }; //breaks if data file is not read able to be opened
	std::cout << newList.getRecord(1).getName() << std::endl;
	return 0;
}