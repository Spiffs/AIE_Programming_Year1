#include <iostream>
#include <vector>
#include <string>

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

float RPN(const char* equation)
{
	int temp = NULL;
	int position = 0;
	bool calculated = false;
	std::vector<std::string> seperated = Explode(' ', equation);
	std::vector<int> stack;

	for (unsigned int i = 0; i < seperated.size(); i++)
	{
		if (std::isdigit(seperated[i][0]))
		{
			stack.push_back(std::stoi(seperated[i]));
		}
		else
		{
			int right = stack.back(); stack.pop_back();
			int left = stack.back(); stack.pop_back();

			switch (seperated[i][0])
			{
				case '+':
					stack.push_back(left + right);
					break;
				case '-':
					stack.push_back(left - right);
					break;
				case '/':
					stack.push_back(left / right);
					break;
				case '*':
					stack.push_back(left * right);
					break;
			}
		}
	}

	if (stack.back()) temp = stack.back();

	return temp;
}

int main(int argc, char** argv)
{
	{
		char equation[] = "10 20 +";
		std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 30" << std::endl;
	}
	{
		char equation[] = "10 20 30 + *";
		std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 500" << std::endl;
	}
	{
		char equation[] = "20 10 / 4 *";
		std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 8" << std::endl;
	}
	{
		char equation[] = "20 10 - 15 +";
		std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 25" << std::endl;
	}
	return 0;
}