#include "Bank.h"

//reads records using standard ',' delimination
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

//writes records from to indicated file
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
		record.at(record.find(" ")) = ','; //replaces space with '_'
		dataFile << record << "," << newList.getRecord(i).recordId << "\n";
	}
	dataFile.close();
	return true;
}

void Bank::displayAllRecords()
{
	displayOutputInterface();
	for (int i = 0; i < newList.size(); i++)
	{
		displayRecord(i);
	}
}

//parses record into an array deliminated by ',' then adds record to records
//numOfExpectedReturnVals is stored in Variables.h
void Bank::parseRecord(std::string record)
{
	int posInArray = 0;
	int pos = 0;
	//length of array is the number of expected return values 
	std::string dataReadIn[numOfExpectedReturnVals];
	while (true)
	{
		if (record.find(",") == std::string::npos) //covers i
		{
			dataReadIn[posInArray] = record.substr(0);
			break;
		};
		pos = record.find(",");
		dataReadIn[posInArray++] = record.substr(0, pos);
		record = record.substr(record.find(",") + 1);
		//id is covered by default above
	}
	//last name comes first then first name, so firstNames pos is 1 
	if (!newList.add(dataReadIn[1], dataReadIn[0], stringToInt(dataReadIn[2])))
	{
		std::cout << "Error adding record to file" << std::endl;
	};
}

//takes a generic prompt and assigns response to a generic response of type z
template <typename k, typename z>
void Bank::getinput(k prompt, z& response) 
{
	std::cout << prompt;
	std::cin >> response;
}

//displays a single record denoted by the record argument
void Bank::displayRecord(int record)
{
	int space = 0;

	//16 spaces between
	std::cout << newList.getRecord(record).recordId;
	printSpace(13);
	std::cout << newList.getRecord(record).lastName;

	space = (15 - newList.getRecord(record).lastName.length()) + 10;
	printSpace(space);
	std::cout << newList.getRecord(record).firstName;

	space = (15 - newList.getRecord(record).firstName.length()) + 9;
	printSpace(space);
	std::cout << ((newList.getRecord(record).recordActivityStatus) ? "Y" : "N") << std::endl;
}

//displays input menu and handles responses from user approriately
bool Bank::handleInput()
{
	clearScreen();
	int input = -1;
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
		bool gotInput = false;
		while (!gotInput)
		{

			getinput("customers first name: ", firstname);
			toLowerCase(firstname);
			if (firstname.length() != 0) { gotInput = true ; };
		}
		gotInput = false;
		while (!gotInput)
		{
			getinput("customers last name: ", lastname);
			toLowerCase(lastname);
			if (!(lastname.length() == 0)) { gotInput = true; };
		}
		
		//make sure input is correct
		clearScreen();
		std::cout << "First name: " << firstname << "\nLast name: " << lastname << std::endl;
		std::cout << "Is this information correct?\n: ";
		std::string ans;
		std::cin >> ans;
		toLowerCase(ans);
		if (ans == "y")
		{
			newList.add(firstname, lastname);
		}
		break;
	}
	case 2: //disolay all records
		displayAllRecords();
		if (yorn("Are you done viewing the screen?"))
		{
			break;
		}
	case 3: //search by id
	{
		int id, pos;
		getinput("enter id: ", id);
		displayOutputInterface();
		pos = newList.search(id);
		if (pos != -1)
		{
			displayRecord(pos);
		}
		if (yorn("Are you done looking at this screen?"))
		{
			break;
		}
	}
	case 4: //search by name
	{
		std::string name;
		std::cout << "enter name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		displayOutputInterface();
		bool nameSearchFinished = false;
		int record = -2; //-2 is an initial check for search operation
		while (!nameSearchFinished)
		{
			record = (record == -2) ? newList.search(name, record) : newList.search(name, record+1);
			if (record != -1)
			{
				displayRecord(record);
			}
			else if (record == -1)
			{
				nameSearchFinished = true;
			}
		}
		if (yorn("Are you done looking at the screen? "))
		{
			break;
		}
	}
	case 5:
	{
		CustomerRecord tempRecord;
		int recordId = -1;
		std::string activityStatus;
		std::string answer;
		std::string firstName = "";
		std::string lastName = "";
		while (true)
		{
			getinput("What record would you like to edit?(ID)\n: ", recordId);
			if (recordId >= 1000) { break; }
			else { std::cout << "Please input a  proper ID\n"; };
		}
		while (firstName.length() == 0)
		{
			getinput("What is the first name?\n: ", answer);
			toLowerCase(answer);
			if (answer.length() > 0) { firstName = answer; };
			answer = "";
		}
		while (lastName.length() == 0)
		{
			getinput("What is the last name?\n: ", answer);
			toLowerCase(answer);
			if (answer.length() > 0) { lastName = answer; };
		}
		while (true)
		{
			getinput("Is this user active still? (Y or N)?\n: ", activityStatus);
			toLowerCase(activityStatus);
			if (activityStatus == "n" || activityStatus == "y") { break; };
		}
		newList.add(firstName, lastName, recordId, (activityStatus == "y") ? true : false);
		break;
	}
	default:
		//when input is invalid
		break;
	}
	return true;
}

//clears screen with 256 newlines
void Bank::clearScreen()
{
	for (int i = 0; i < 256; i++)
	{
		std::cout << "\n";
	}
}

//prints # of spaces indicated
void Bank::printSpace(int spaces)
{
	for (int i = 0; i < spaces; i++)
	{
		std::cout << " ";
	}
}

//yes or no prompt returns true or false, format question in prompt argument
bool Bank::yorn(std::string prompt)
{
	std::cout << prompt << "\n:";
	std::string input;
	while (true)
	{
		std::cin >> input;
		toLowerCase(input);
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
	std::cout << "ID               Last Name               First Name               "
		"Activity status\n\n";
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

void Bank::toLowerCase(std::string& input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] < 91)
		{
			input[i] = input[i] + 32;
		}
	}
}
