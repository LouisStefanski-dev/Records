#include "List.h" 

bool List::add(std::string firstName, std::string lastName, int recordId)
{
	if (recordId == -1) { recordId = counter + 1000; }; //if name does not have an assigned record id the recordId given is counter + 1000
	if (counter < recordsMaxSize)
	{
		//CustomerRecord* newCustomer = new CustomerRecord(firstName, lastName, recordId);
		//records[counter] = newCustomer;
		records[counter].firstName = firstName;
		records[counter].lastName = lastName;
		records[counter].recordId = recordId;
	}
	counter++;
	return true;
}

bool List::search(std::string name)
{
	return search(name, 0, counter);
}

bool List::search(int id)
{
	return search(id, 0, counter);
}

bool List::search(std::string name, int n1, int n2)
{
	if ((n2 - n1) < 1)
	{
		return false;
	}

	int mid = (n1 + n2) / 2;
	if (records[mid].getName() == name)
	{
		return true;
	}

	if (records[mid].getName() > name)
	{
		return search(name, n1, mid);
	}
	return search(name, mid, n2);
}

bool List::search(int id, int n1, int n2)
{
	if ((n2 - n1) < 1)
	{
		return false;
	}

	int mid = (n1 + n2) / 2;
	if (records[mid].recordId == id)
	{
		return true;
	}
	if (records[mid].recordId > id)
	{
		return search(id, n1, mid);
	}
	search(id, mid, n2);
}

void List::swap(int n1, int n2)
{
	CustomerRecord temp = records[n1];
	records[n1] = records[n2];
	records[n2] = temp;
}
