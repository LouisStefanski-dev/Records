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

void List::swap(int n1, int n2)
{
	CustomerRecord* temp = records[n1];
	records[n1] = records[n2];
	records[n2] = temp;
}
