#include "CustomerRecord.h"

CustomerRecord::CustomerRecord()
{
    recordActivityStatus = true;
}

CustomerRecord::~CustomerRecord()
{

}

std::string CustomerRecord::getName()
{
    std::string name = lastName + " " + firstName;
    return (name); //concatenates first + last name
}