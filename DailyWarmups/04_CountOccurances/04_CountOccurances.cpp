#include <iostream>
#include <string>

// counts the repeats of a term defined in the function pass through
int CountOccurances(const std::string& phrase, const std::string& searchTerm)
{
	// neginning with constant ints
	int occurance = 0;
	int phraselength = phrase.length();
	int searchlength = searchTerm.length();

	// loops through looking for repeats of each letter in the phrase and search term
	for (int i = 0; i < phraselength; i++)
	{
		for (int x = 0; x < searchlength; x++)
		{
			if (phrase[i + x] == searchTerm[x])
			{
				if (x == searchlength - 1)
				{
					// if all checks pass, adds to occurance  
					occurance++;
				}
				else { continue; }
			}
			else
			{
				// if the next variable in the phrase does not match the seardh term then break the first for loop 
				break;
			}
		}
	}
	// returns occurance
	return occurance;
}


int main(int argc, char** argv)
{
	std::string phrase1 = "the quick brown fox jumps over the lazy dog";
	std::string phrase2 = "hello world";
	std::string phrase3 = "aaaaaaaaaaa";
	std::cout << CountOccurances(phrase1, "the") << std::endl;  // -> 2
	std::cout << CountOccurances(phrase1, "o") << std::endl;    // -> 4
	std::cout << CountOccurances(phrase2, "l") << std::endl;    // -> 3
	std::cout << CountOccurances(phrase2, "ll") << std::endl;   // -> 1
	std::cout << CountOccurances(phrase3, "aaa") << std::endl;  // -> 9
	std::cout << CountOccurances(phrase3, "a") << std::endl;    // -> 11
	std::cout << CountOccurances(phrase3, "") << std::endl;   // -> 0
	std::cout << CountOccurances("", "a") << std::endl;   // -> 0
	return 0;
}