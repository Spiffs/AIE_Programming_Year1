#include <iostream>
#include <list>

int sharedLetters(const std::string& _a, const std::string& _b)
{
	int _aLength = _a.length();
	int _bLength = _b.length();
	int repeats = 0;

	for (int i = 0; i < _aLength; i++)
	{
		for (int x = 0; x < _bLength; x++)
		{
			if (_a.at(i) == _b.at(x))
			{
				repeats++;
			}
		}
	}
	return repeats;
}

int main()
{
	std::cout << sharedLetters("apple", "meaty") << std::endl;
	std::cout << sharedLetters("fan", "forsook") << std::endl;
	std::cout << sharedLetters("spout", "shout") << std::endl;
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
