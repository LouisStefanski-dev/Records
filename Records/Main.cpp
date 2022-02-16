#include "List.h"
#include <iostream>

int main()
{
	List newList;
	if (!newList.readInRecords("names.txt")) { return 1; }; //breaks if data file is not read able to be opened to retrieve records
	newList.displayAllRecords();
	if (!newList.writeRecordsToFile("names.txt")) { return 1; }; //breaks if data file is not able to be opened to write records
	return 0;
}