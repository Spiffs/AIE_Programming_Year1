#include <iostream>
#include <vector>

int GenerateFib(int num)
{
	int total = 0;
	std::vector<int> nums;

	// beginning the Fibonacci sequence 
	nums.push_back(0); nums.push_back(1);

	// find even sum 
	for (int i = 1; nums[i] < num; i++)
	{
		nums.push_back(nums[i] + nums[i - 1]);
		if (nums[i] % 2 == 0)
			total += nums[i];
	}
	return total;
}

int main(int argc, char** argv)
{
	std::cout << GenerateFib(13) << std::endl; // 10 = 2 + 8
	std::cout << GenerateFib(17) << std::endl; // 10 = 2 + 8
	std::cout << GenerateFib(45) << std::endl; // 44 = 2 + 8 + 34
	std::cout << GenerateFib(55) << std::endl; // 44 = 2 + 8 + 34
}