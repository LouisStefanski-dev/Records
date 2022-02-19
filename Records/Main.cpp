#include "List.h"
#include <iostream>

/// <summary>
/// getInput is a generic function that has a void return type. This function takes in a prompt(type K) and a response(type Z) where response is passed by reference
/// and stores the 'answer'
/// </summary>
/// <typeparam name="K">Generic type belonging to prompt</typeparam>
/// <typeparam name="Z">Generic type belonging to response</typeparam>
/// <param name="prompt">What the user is prompted to respond to</param>
/// <param name="response">Passed by reference, and stores the answer</param>
template <typename K, typename Z>
void getInput(K prompt, Z& response)
{
	std::cout << prompt;
	std::cin >> response;
}

template <typename K> 
bool handleInput(K& list)
{
	int input = -1;
	getInput("\n\n1. Add New Customer \n2. Display all Customers \n3. Find Customer(by ID)\n4.Find Customer(by name)\n5.Edit Customer Record\n\n0.Quit\n: ", input);
	switch (input)
	{
	case 0:
		return false;
		break;
	case 1:
		//add customer input
	{
		std::string firstName, lastName = "";
		while (true)
		{
			getInput("Customers first name: ", firstName);
			if (!(firstName.length() == 0)) { break; };
		}
		while (true)
		{
			getInput("Customers last name: ", lastName);
			if (!(lastName.length() == 0)) { break; };
		}
		list.add(firstName, lastName);
		break;
	}
	case 2:
		list.displayAllRecords();
		break;
	case 3:
		//search by id
		break;
	case 4:
		//search by name
		break;
	case 5:
		//edit record
		break;
	default:
		//when input is invalid
		break;
	}
	return true;
}

int main()
{
	List newList;
	if (!newList.readInRecords("names.txt")) { return 1; }; //breaks if data file is not read able to be opened to retrieve records
	while (true)
	{
		if (!handleInput(newList)) { break; };
	}
	if (!newList.writeRecordsToFile("names.txt")) { return 1; }; //breaks if data file is not able to be opened to write records
	return 0;
}