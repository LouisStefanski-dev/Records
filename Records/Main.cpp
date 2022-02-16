#include "List.h"
#include <iostream>

int main()
{
	List newList;
	if (!newList.readInRecords("names.txt")) { return 1; }; //breaks if data file is not read able to be opened
	std::cout << newList.getRecord(2).getName() << std::endl;
	newList.add("Austin", "z");
	newList.writeRecordsToFile("names.txt");
	return 0;
}