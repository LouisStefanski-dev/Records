#include "CustomerRecord.h"

CustomerRecord::CustomerRecord(std::string first, std::string last, int Id)
{
    firstName = first;
    lastName = last;
    recordId = Id;
    recordActivityStatus = true;
}

CustomerRecord::~CustomerRecord()
{
}

std::string CustomerRecord::getName()
{
    return (firstName + " " + lastName); //concatenates first + last name
}
