#pragma once
#include <iostream>
#include "CustomerRecord.h"
#include "Variables.h"

class List
{
public:
	List() { counter = 0; };
	//remember to delete records
	bool add(std::string firstName, std::string lastName);
	CustomerRecord& getRecord(int pos) { return (*records[pos]); };
private:
	int counter = 0;
	CustomerRecord* records[recordsMaxSize];
	void swap(int n1, int n2);
};

