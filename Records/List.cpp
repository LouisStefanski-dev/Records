#include "List.h"

bool List::add(std::string firstName, std::string lastName, int recordId)
{
	if (recordId == -1) { recordId = counter + 1000; }; //if name does not have an assigned record id the recordId given is counter + 1000
	if (counter < recordsMaxSize)
	{
		CustomerRecord* newCustomer = new CustomerRecord(firstName, lastName, recordId);
		records[counter] = newCustomer;
	}
	counter++;
	return true;
}

bool List::readInRecords(std::string file) //uses ',' as a delimiter 
{
	std::ifstream dataFile(file);
	if (!dataFile)
	{
		std::cout << "Could not open file" << std::endl;
		return false;
	}
	std::string record;
	std::size_t pos;
	while (std::getline(dataFile, record))
	{
		pos = record.find("_");
		int  recordId = std::stoi(record.substr((record.find(",") + 1)));
		add(record.substr(0, pos), record.substr((pos + 1), (record.find(",") - (pos + 1))), recordId); //splits names by delimiter pos
	}
	dataFile.close();
	return true;
}

bool List::writeRecordsToFile(std::string file)
{
	std::fstream dataFile(file);
	if (!dataFile)
	{
		std::cout << "Could not open file" << std::endl;
		return false;
	}
	std::string record;
	for (int i = 0; i < counter; i++)
	{
		record = records[i]->getName();
		record.at(record.find(" ")) = '_'; //replaces space with '_'
		dataFile << record << "," << records[i]->getRecordId() << "\n";
	}
	dataFile.close();
	return true;
}

void List::displayAllRecords()
{
	std::cout << "\n-------------------------------------------------------------------------\n\n";
	for (int i = 0; i < counter; i++)
	{
		std::cout << (i + 1) << ". " << records[i]->getName() << std::endl;
	}
	std::cout << "\n-------------------------------------------------------------------------\n";
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
	if (records[mid]->getName() == name)
	{
		return true;
	}

	if (records[mid]->getName() > name)
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
	if (records[mid]->getRecordId() == id)
	{
		return true;
	}
	if (records[mid]->getRecordId() > id)
	{
		return search(id, n1, mid);
	}
	search(id, mid, n2);
}

void List::swap(int n1, int n2)
{
	CustomerRecord* temp = records[n1];
	records[n1] = records[n2];
	records[n2] = temp;
}
