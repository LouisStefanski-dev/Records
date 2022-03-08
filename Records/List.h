#pragma once
#include <iostream>
#include "CustomerRecord.h"
#include "Variables.h"


class List
{
public:
	List() { counter = 0; };
	//remember to delete records
	bool add(std::string firstName, std::string lastName, int recordId = -1, bool activityStatus = true);
	void sort();
	int search(std::string name, int n1 = 0);
	int search(int id);
	int size() { return counter; };
	CustomerRecord getRecord(int pos) { return (records[pos]); };
private:
	void insert(int i);
	int counter = 0;
	CustomerRecord records[recordsMaxSize];
	void swap(int n1, int n2);
};

