#pragma once
#include <iostream>
#include <string>

template <typename k, typename z>
void getinput(k prompt, z& response);

template <typename k>
bool handleInput(k& list);

/// <summary>
/// getinput is a generic function that has a void return type. this function takes in a prompt(type k) and a response(type z) where response is passed by reference
/// and stores the 'answer'
/// </summary>
/// <typeparam name="k">generic type belonging to prompt</typeparam>
/// <typeparam name="z">generic type belonging to response</typeparam>
/// <param name="prompt">what the user is prompted to respond to</param>
/// <param name="response">passed by reference, and stores the answer</param>
/// 
template <typename k, typename z>
inline void getinput(k prompt, z& response)
{
	std::cout << prompt;
	std::cin >> response;
}

template <typename k>
inline bool handleInput(k& list)
{
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
		list.add(firstname, lastname);
		break;
	}
	case 2:
		list.displayAllRecords();
		break;
	case 3: //search by id
	{
		int id;
		getinput("enter id: ", id);
		std::cout << list.search(id) << std::endl;
		break;
	}
	case 4: //search by name
	{
		std::string name;
		std::cout << "enter name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		std::cout << name << ":" << std::endl;
		std::cout << list.search(name) << std::endl;
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

