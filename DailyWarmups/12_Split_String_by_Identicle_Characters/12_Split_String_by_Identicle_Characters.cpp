#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> splitGroups(const std::string word)
{
	int pVectorSpace = 0;
	int pSplit = 0;
	std::vector<std::string> result;

	for (int i = 1; i < word.size(); i++)
	{
		if (word[i] != word[i - 1])
		{
			std::string pTemp;
			for (int x = pSplit; x < i; x++)
			{
				pTemp.push_back(word[x]);
			}

			result.push_back(pTemp);
			pSplit = i;
			pVectorSpace++;
		}
	}

	if (pSplit == 0)
		result.push_back(word);

	return result;
}


int main()
{

	std::vector<std::string> tResults = splitGroups("555");
	int tLength = tResults.size();

	for (int i = 0; i < tLength; i++)
	{
		std::cout << tResults[i] << ", ";
	}
	std::cout << std::endl;

	tResults = splitGroups("5556667788");
	tLength = tResults.size();

	for (int i = 0; i < tLength; i++)
	{
		std::cout << tResults[i] << ", ";
	}
	std::cout << std::endl;

	tResults = splitGroups("aaabbbaabbab");
	tLength = tResults.size();

	for (int i = 0; i < tLength; i++)
	{
		std::cout << tResults[i] << ", ";
	}
	std::cout << std::endl;

	tResults = splitGroups("abbbcc88999&&!!!_");
	tLength = tResults.size();

	for (int i = 0; i < tLength; i++)
	{
		std::cout << tResults[i] << ", ";
	}

	std::cin.get();
}

