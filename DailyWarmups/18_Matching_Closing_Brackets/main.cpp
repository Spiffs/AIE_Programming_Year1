#include <string>
#include <iostream>

int MatchClosingBracket(const std::string& str, int loc)
{
	int bracketcount = 1;

	if (loc < 0 || str[loc] != '[') return -1;

	for (int i = loc + 1; bracketcount != -1; i++)
	{
		if (str[i] == '[')			bracketcount++;
		else if (str[i] == ']')		bracketcount--;
		if (bracketcount == 0)		return i;
	}
} 

int main(int argc, char** argv)
{
	std::string bf = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

	std::cout << MatchClosingBracket(bf, 1) << std::endl; // -1
	std::cout << MatchClosingBracket(bf, 8) << std::endl; // 48
	std::cout << MatchClosingBracket(bf, 14) << std::endl; // 33
	std::cout << MatchClosingBracket(bf, 43) << std::endl; // 45
	std::cout << MatchClosingBracket(bf, 101) << std::endl; // -1
	std::cout << MatchClosingBracket(bf, -1) << std::endl; // -1

}