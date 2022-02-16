#include "List.h"
#include <iostream>

int main()
{
	List newList;
	newList.add("louis", "s");
	newList.add("bill", "z");

	std::cout << newList.getRecord(0).getName() << std::endl;
	return 0;
}