#include <iostream>


void printntimes(const char letter, int times)
{
	for (int i = 0; i < times; i++)
	{
		std::cout << letter;
	}
}

void print_pyramid(int height)
{
	int blocks = 1;
	if (height > 0)
	{
		for (int i = height; i > 0; i--)
		{
			std::cout << "\t";
			printntimes(' ', i);
			printntimes('*', blocks);
			std::cout << std::endl;
			blocks += 2;
		}
	}
	else
	{
		blocks = (2 * -height) - 1;

		for (int i = 0; i < -height + 1; i++)
		{
			std::cout << "\t";
			printntimes(' ', i);
			printntimes('*', blocks);
			std::cout << std::endl;
			blocks -= 2;
		}
	}
}


int main(int argc, char** argv)
{
	std::cout << "=======================================" << std::endl;
	print_pyramid(6);
	std::cout << "=======================================" << std::endl;
	print_pyramid(7);
	std::cout << "=======================================" << std::endl;
	print_pyramid(-1);
	std::cout << "=======================================" << std::endl;
	print_pyramid(-6);
}