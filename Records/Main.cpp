#include "List.h"
#include "Functions.h"
#include <iostream>


//TODO 
//Work on removing spaces
//Sorting


int main()
{
	List newList;
	if (!newList.readInRecords("names.txt")) { return 1; }; //breaks if data file is not read able to be opened to retrieve records
	while (true)
	{
		if (!handleInput(newList)) { break; };
	}
	if (!newList.writeRecordsToFile("names.txt")) { return 1; }; //breaks if data file is not able to be opened to write records
	return 0;
}