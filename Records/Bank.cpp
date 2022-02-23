#include "Bank.h"

bool Bank::readInRecords(std::string file) //uses ',' as a delimiter 
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

bool Bank::writeRecordsToFile(std::string file)
{
	std::fstream dataFile(file);
	if (!dataFile)
	{
		std::cout << "Could not open file" << std::endl;
		return false;
	}
	std::string record;
	for (int i = 0; i < newList.size(); i++)
	{
		record = newList.getRecord(i).getName();
		record.at(record.find(" ")) = '_'; //replaces space with '_'
		dataFile << record << "," << newList.getRecord(i).recordId << "\n";
	}
	dataFile.close();
	return true;
}

void Bank::displayAllRecords()
{
	displayOutputInterface();
	int space = 0;
	for (int i = 0; i < newList.size(); i++)
	{
		//16 spaces between
		std::cout << newList.getRecord(i).recordId;
		printSpace(13);
		std::cout << newList.getRecord(i).firstName;

		space = (15 - newList.getRecord(i).firstName.length()) + 10;
		printSpace(space);
		std::cout << newList.getRecord(i).lastName;

		space = (15 - newList.getRecord(i).lastName.length()) + 9;
		printSpace(space);
		std::cout << newList.getRecord(i).recordActivityStatus << std::endl;
	}
}

//parses record into an array deliminated by ',' then adds record to records
//numOfExpectedReturnVals is stored in Variables.h
void Bank::parseRecord(std::string record)
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
	newList.add(name.substr(pos + 1), name.substr(0, pos), stringToInt(dataReadIn[1]));
}

template <typename k, typename z>
void Bank::getinput(k prompt, z& response)
{
	std::cout << prompt;
	std::cin >> response;
}

bool Bank::handleInput()
{
	int input = -1;
	clearScreen();
	getinput("\n\n1. add new customer \n2. display all customers \n3. find customer(by id)\n4.find customer(by name)\n5.edit customer record\n\n0.quit\n: ", input);
	switch (input)
	{
	case 0:
		return false;
		break;
	case 1:
		//add customer input
	{
		std::string firstname, lastname = "";
		while (true)
		{
			getinput("customers first name: ", firstname);
			if (firstname.length() != 0) { break; };
		}
		while (true)
		{
			getinput("customers last name: ", lastname);
			if (!(lastname.length() == 0)) { break; };
		}
		newList.add(firstname, lastname);
		break;
	}
	case 2:
		displayAllRecords();
		if (yorn("Are you done viewing the screen?"))
		{
			break;
		}
	case 3: //search by id
	{
		int id;
		getinput("enter id: ", id);
		std::cout << newList.search(id) << std::endl;
		break;
	}
	case 4: //search by name
	{
		std::string name;
		std::cout << "enter name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		std::cout << name << ":" << std::endl;
		std::cout << newList.search(name) << std::endl;
		break;
	}
	case 5:
		//edit record
		break;
	default:
		//when input is invalid
		break;
	}
	return true;
}

void Bank::clearScreen()
{
	for (int i = 0; i < 256; i++)
	{
		std::cout << "\n";
	}
}

void Bank::printSpace(int spaces)
{
	for (int i = 0; i < spaces; i++)
	{
		std::cout << " ";
	}
}

bool Bank::yorn(std::string prompt)
{
	std::cout << prompt << "\n:";
	std::string input;
	while (true)
	{
		std::cin >> input;
		if (input == "y") 
		{ 
			return true;
			break;
		}
		else if (input == "n")
		{
			std::cout << ":";
		}
		else
		{
			std::cout << "Please input Y or N\n:";
		}
	}
	return false;
}

void Bank::displayOutputInterface()
{
	clearScreen();
	std::cout << "ID               First Name               Last Name               "
		"Activity status\n";
}

int Bank::stringToInt(std::string str)
{
	int returnVal = 0;
	for (int i = 0; i < str.length(); i++)
	{
		returnVal = returnVal * 10 + str[i] - 48;
	}
	return returnVal;
}
