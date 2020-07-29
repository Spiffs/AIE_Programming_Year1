#include <iostream>


bool IsValidHexcode(const char hex[])
{
	// test for length
	if (strlen(hex) > 7)
		return false;

	// test for no #
	if (hex[0] != '#')
		return false;

	for (int i = 1; i < 8; i++)
	{
		// test for on hex scale 
		if (!isdigit(hex[i]) && !(toupper(hex[i]) >= 'A' && toupper(hex[i]) <= 'F') && hex[i] != '\0')
			return false;

		// test for non all upper case
		if (i >= 2 && hex[i] != '\0')
		{
			if (!isdigit(hex[i]) && isupper(hex[1]))
			{
				if (!isupper(hex[i]))
					return false;
			}
			else if (!isdigit(hex[i]) && isupper(hex[i]))
				return false;
		}
	}
	return true;
}

int main()
{
	bool pass;


	pass = IsValidHexcode("#CD5C5C");
	std::cout << "#CD5C5C" << "\t\t" << pass << std::endl;

	pass = IsValidHexcode("#EAECEE");
	std::cout << "#EAECEE" << "\t\t" << pass << std::endl;

	pass = IsValidHexcode("#eaecee");
	std::cout << "#eaecee" << "\t\t" << pass << std::endl;

	pass = IsValidHexcode("#CD5C58C");
	std::cout << "#CD5C58C" << "\t" << pass << std::endl;

	// Length exceeds 6
	pass = IsValidHexcode("#CD5C5Z");
	std::cout << "#CD5C5Z" << "\t\t" << pass << std::endl;

	// Not all alphabetic characters in A-F
	pass = IsValidHexcode("#CD5C&C");
	std::cout << "#CD5C&C" << "\t\t" << pass << std::endl;

	// Contains unacceptable character
	pass = IsValidHexcode("CD5C5C");
	std::cout << "CD5C5C" << "\t\t" << pass << std::endl;

	// Missing #
	pass = IsValidHexcode("#cd5C5D");
	std::cout << "#cd5C5D" << "\t\t" << pass << std::endl;

	// all aplphabetic characters must match in case

}
