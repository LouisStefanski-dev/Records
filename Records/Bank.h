#pragma once
#include <fstream>
#include <string>
#include "List.h"

class Bank
{
public:
	bool readInRecords(std::string file);
	bool writeRecordsToFile(std::string file);
	void displayAllRecords();
	void parseRecord(std::string record);
	template <typename k, typename z>
	void getinput(k prompt, z& response);
	bool handleInput();
	void clearScreen();
	void printSpace(int spaces);
	bool yorn(std::string prompt);
	void displayOutputInterface();
	int stringToInt(std::string str);
	void toLowerCase(std::string& input);
	void displayRecord(int record);

private:
	List newList;
};