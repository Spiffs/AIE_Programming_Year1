#include "HashFunction.h"
#include <string>
#include <iostream>

void Exists(const std::string& a_exists, HashFunction<std::string, int>& a_table)
{
	if (a_table.Exists(a_exists)) {
		std::cout << a_table.GetValue(a_exists) << std::endl;
	}
	else { std::cout << "Does Not Exist" << std::endl; }
}

int main()
{
	HashFunction<std::string, int> table;

	table.AddEntry("Oscar", 132145);
	table.AddEntry("Petgr", 445433);	// Petgr collides with Oscar
	table.AddEntry("Aaron", 14454);
	table.AddEntry("Oscar", 222222);	// update test

	Exists("Oscar", table);
	Exists("Petgr", table);
	Exists("something", table);

	std::cout << std::endl;

	table.Print();

	std::cin.get();

	return 0;
}

