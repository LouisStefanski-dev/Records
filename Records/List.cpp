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

bool List::readInRecords(std::string file) //uses ',' as a delimiter 
{
	std::ifstream dataFile(file);
	if (!dataFile)
	{
		std::cout << "Could not open file" << std::endl;
		return false;
	}
	std::string record;
	while (std::getline(dataFile, record))
	{
		parseRecord(record);
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
		record = records[i].getName();
		record.at(record.find(" ")) = '_'; //replaces space with '_'
		dataFile << record << "," << records[i].recordId << "\n";
	}
	dataFile.close();
	return true;
}

void List::displayAllRecords()
{
	std::cout << "\n-------------------------------------------------------------------------\n\n";
	for (int i = 0; i < counter; i++)
	{
		std::cout << (i + 1) << ". " << records[i].getName() << std::endl;
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

//parses record into an array deliminated by ',' then adds record to records
//numOfExpectedReturnVals is stored in Variables.h
void List::parseRecord(std::string record)
{
	int posInArray = 0;
	//length of array is the number of expected return values 
	std::string dataReadIn[numOfExpectedReturnVals];
	while (true)
	{
		if (record.find(",") == std::string::npos)
		{ 
			dataReadIn[posInArray] = record.substr(0);
			break;
		};
		dataReadIn[posInArray] = record.substr(0, record.find(","));
		posInArray++;
		record = record.substr(record.find(",") + 1);
	}
	std::string name = dataReadIn[0];
	std::size_t pos = name.find("_");
	add(name.substr(0, pos), name.substr(pos + 1), std::stoi(dataReadIn[1]));
}
