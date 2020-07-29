#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Explode(char seperator, const char* str)
{
	std::vector<std::string> result;

	int length = strlen(str);
	int lastseperator = 0;
	std::string entry;

	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] == seperator || i == length)
		{
			int x = lastseperator;
			lastseperator = i;
			if (str[x] == seperator) { x++; }

			while (x < lastseperator)
			{
				entry += str[x];
				x++;
			}
			result.push_back(entry);
			entry.clear();
		}
	}
	return result;
}

int main(int argc, char* argv)
{
	std::cout << "---------------------------------------------------------" << std::endl;
	auto words = Explode(' ', "the quick brown fox jumps over the lazy dog");
	std::cout << "There are: " << words.size() << std::endl << std::endl;
	for (auto& w : words) {
		std::cout << w << std::endl;
	}
	std::cout << "---------------------------------------------------------" << std::endl;

	std::cout << "---------------------------------------------------------" << std::endl;
	auto kvp = Explode('&', "aaa:10&bbb:20ccc:30&&&&&ddd:30");
	std::cout << "There are: " << kvp.size() << std::endl << std::endl;
	for (auto& w : kvp) {
		std::cout << w << std::endl;
	}
	std::cout << "---------------------------------------------------------" << std::endl;

	float _new = 'new';
	std::cout << _new;

	return 0;
}