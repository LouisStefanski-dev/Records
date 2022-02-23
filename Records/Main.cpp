#include "Bank.h"
#include <iostream>


//TODO 
//Work on removing spaces
//Sorting


int main()
{
	Bank bank;
	if (!bank.readInRecords("names.txt")) { return 1; }; //breaks if data file is not read able to be opened to retrieve records
	while (true)
	{
		if (!bank.handleInput()) { break; };
	}
	if (!bank.writeRecordsToFile("names.txt")) { return 1; }; //breaks if data file is not able to be opened to write records
	return 0;
}