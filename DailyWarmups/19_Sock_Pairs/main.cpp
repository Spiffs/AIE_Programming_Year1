#include <iostream>
#include <string>
#include <vector>

int RetrySockPairs(const std::string& socks)
{
	std::vector<char> checked;
	int pairs = 0;
	for (auto& sock : socks)
	{
		auto done = std::find(checked.begin(), checked.end(), sock);
		auto pairer = std::find(socks.begin(), socks.end(), sock);
		if (((*pairer).size()) % 2 == 0 && *done == 0) {
			checked.push_back(sock);
			pairs++;
		}
	}
	return pairs;
}

int SockPairs(const std::string& socks)
{
	std::vector<std::vector<char>> matchedsocks;

	for (int x = 0; x < socks.size(); x++)
	{
		for (int i = 0; i < matchedsocks.size(); i++)
		{
			if (socks[x] == matchedsocks[i][0]) {
				matchedsocks[i].push_back(socks[x]);
				break;
			}
			else if (i == matchedsocks.size() - 1) {
				std::vector<char> newsock;
				newsock.push_back(socks[x]);
				matchedsocks.push_back(newsock);
				break;
			}
		}
		if (matchedsocks.empty()) {
			std::vector<char> newsock;
			newsock.push_back(socks[x]);
			matchedsocks.push_back(newsock);
		}
	}

	int pairs = 0;
	for (auto vector : matchedsocks)
	{
		if (vector.size() % 2 == 0)
			pairs++;
		else
			pairs += vector.size() - 1;
	}
	return pairs;
}

int main(int argc, char** argv)
{
	std::cout << SockPairs("AA") << std::endl;
	std::cout << SockPairs("ABABC") << std::endl;
	std::cout << SockPairs("CABBACCC") << std::endl;

	std::cout << RetrySockPairs("AA") << std::endl;
	std::cout << RetrySockPairs("ABABC") << std::endl;
	std::cout << RetrySockPairs("CABBACCC") << std::endl;
}
