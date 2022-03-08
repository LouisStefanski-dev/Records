#include "List.h" 

bool List::add(std::string firstName, std::string lastName, int recordId, bool activityStatus)
{
	if (recordId == -1) { recordId = counter + 1000; }; //if name does not have an assigned record id the recordId given is counter + 1000
	
	if ((search(recordId) != -1))
	{
		if (counter < recordsMaxSize)
		{
			int posOfRecord = search(recordId);
			records[posOfRecord].firstName = firstName;
			records[posOfRecord].lastName = lastName;
			records[posOfRecord].recordActivityStatus = activityStatus;
		}
	}
	else
	{
		//CustomerRecord* newCustomer = new CustomerRecord(firstName, lastName, recordId);
		//records[counter] = newCustomer;
		records[counter].firstName = firstName;
		records[counter].lastName = lastName;
		records[counter].recordId = recordId;
		records[counter].recordActivityStatus = activityStatus;
		counter++;
	}
	sort();
	return true;
}

void List::sort()
{
	for (int i = 0; i < counter; i++)
	{
		insert(i);
	}
	//     * OLD TEST CODE *
	//int key, j;
	//for (int i = 1; i < counter; i++)
	//{
	//	key = i;
	//	j = i - 1;
	//	while (j >= 0 && (records[j].getName() > records[key].getName()))
	//	{
	//		swap(j + 1, j--);
	//	}
	//	swap(j + 1, key);
	//}
}

void List::insert(int i)
{
	if (i < 1)
	{
		return;
	}

	if (records[i - 1].getName() < records[i].getName())
	{
		return;
	}
	swap((i - 1), i);
	insert(i - 1);
}

//returns -1 if search fails, else returns index of name
int List::search(std::string name, int n1)
{
	if (counter == 0) { return -1; };
	for (int i = n1; i < counter; i++)
	{
		if (name == records[i].lastName)
		{
			return i;
		}
	}
	return -1;
}

//returns -1 if search fails, else returns index of id
int List::search(int id)
{
	if (counter == 0) { return -1; };
	for (int i = 0; i < counter; i++)
	{
		if (id == records[i].recordId)
		{
			return i;
		}
	}
	return -1;
}

void List::swap(int n1, int n2)
{
	CustomerRecord temp = records[n1];
	records[n1] = records[n2];
	records[n2] = temp;
}
