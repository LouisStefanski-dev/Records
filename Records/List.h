#pragma once
#include <iostream>
#include <fstream>
#include <array>
#include "CustomerRecord.h"
#include "Variables.h"

class List
{
public:
	List() { counter = 0; };
	//remember to delete records
	bool add(std::string firstName, std::string lastName, int recordId = -1);
	bool readInRecords(std::string file);
	bool writeRecordsToFile(std::string file);
	void displayAllRecords();
	bool search(std::string name);
	bool search(int id);
	CustomerRecord getRecord(int pos) { return (records[pos]); };
private:
	int counter = 0;
	bool search(std::string name, int n1, int n2);
	bool search(int id, int n1, int n2);
	CustomerRecord records[recordsMaxSize];
	void swap(int n1, int n2);
	void parseRecord(std::string record);
};

