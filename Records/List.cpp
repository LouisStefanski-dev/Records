#include "List.h"

bool List::add(std::string firstName, std::string lastName)
{
	// 1000 is added to counter to meet lower bound of recordId
	CustomerRecord* newCustomer = new CustomerRecord(firstName, lastName, counter + 1000);
	if (counter < recordsMaxSize )
	{
		records[counter] = newCustomer;
	}
	counter++;
	return true;
}

bool List::readInRecords(std::string file)
{
	std::ifstream dataFile(file);
	if (!dataFile)
	{
		std::cout << "Could not open file" << std::endl;
		return false;
	}
	std::string record;
	std::size_t pos;
	while (dataFile >> record)
	{
		pos = record.find("_");
		add(record.substr(0, pos), record.substr(pos + 1)); //splits names by delimiter pos
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
		dataFile << record << "\n";
	}
	dataFile.close();
	return true;
}

void List::displayAllRecords()
{
	for (int i = 0; i < counter; i++)
	{
		std::cout << (i + 1) << ". " << records[i]->getName() << std::endl;
	}
}

void List::swap(int n1, int n2)
{
	CustomerRecord* temp = records[n1];
	records[n1] = records[n2];
	records[n2] = temp;
}
