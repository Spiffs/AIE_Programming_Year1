#include <iostream>
#include <vector>

bool overTwentyOne(std::vector<char> cards)
{
	int Acount = 0;
	int sum = 0;

	for (int i = 0; i < cards.size(); i++)
	{
		if (!isdigit(cards[i]))
		{
			if (cards[i] == 'A')
				Acount++;
			else if (cards[i] == 'J' || cards[i] == 'Q' || cards[i] == 'K')
				sum += 10;
		}
		if (isdigit(cards[i]))
			sum += cards[i] - 48; // or could use (int)(cards[i] - '0') instead							HAXXOR
	}

	for (int i = 0; i < Acount; i++)
	{
		if (sum + 10 > 21)
			sum++;
		else
			sum += 11;
	}

	if (sum > 21)
		return true;
	else
		return false;
}


int main()
{
	std::cout << "Game 1: " << overTwentyOne({ '2', '8', 'J' }) << std::endl;

	std::cout << "Game 2: " << overTwentyOne({ 'A', 'J', 'K' }) << std::endl;

	std::cout << "Game 3: " << overTwentyOne({ '5', '5', '3', '9' }) << std::endl;

	std::cout << "Game 4: " << overTwentyOne({ '2', '6', '4', '4', '5' }) << std::endl;

	std::cout << "Game 5: " << overTwentyOne({ 'J' , 'Q', 'K' }) << std::endl;

}
