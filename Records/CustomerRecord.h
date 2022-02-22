#pragma once
#include <string>

enum class RECORDTYPE {C};

class CustomerRecord
{
public:
	CustomerRecord();
	~CustomerRecord();
	std::string getName(); 
	std::string firstName;
	std::string lastName;
	bool recordActivityStatus; //true means active, false means not active
	int recordId; //from 1000 up
	RECORDTYPE recordType = RECORDTYPE::C;
	
	// temp set to 0
	int firstTransactionNumber = 0;
	int lastTransactionNumber = 0;
};

