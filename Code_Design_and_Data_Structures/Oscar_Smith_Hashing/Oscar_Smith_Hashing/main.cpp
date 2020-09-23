#include "HashFunction.h"
#include <string>
#include <iostream>

int main()
{
	HashFunction<std::string, int> table;

	table.AddEntry("Oscar", 132145);
	table.AddEntry("Petgr", 445433);	// Petgr collides with Oscar
	table.AddEntry("Aaron", 14454);
	table.AddEntry("Oscar", 222222);	// update test

	std::cout << table.GetValue("Oscar") << std::endl;
	std::cout << table.GetValue("Petgr") << std::endl;
	if (table.Exists("something"))
	{
		std::cout << table.GetValue("something") << std::endl;
	}
	else { std::cout << "Does Not Exist" << std::endl; }

	std::cout << std::endl;

	table.Print();

	std::cin.get();

	return 0;
}

