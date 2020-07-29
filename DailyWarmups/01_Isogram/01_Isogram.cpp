#include <iostream>
//#include <string>

using std::cout;
using std::cin;
using std::endl;

//bool isIsogram(const std::string& word)
bool isIsogram(const char a_word[])
{
	int r_lengthofword = strlen(a_word);

	for (int i = 0; i < r_lengthofword; i++)
	{
		for (int x = 0; x < r_lengthofword; x++)
		{
			if (toupper(a_word[i]) == toupper(a_word[x]) && x != i)
			{
				return false;
			}
		}
	}
	return true;
}
int main(int argc, char** argv)
{
	cout << "Aaron" << "\t" << "\t" << isIsogram("Aaron") << endl;

	// random words from a random word generator :P
	cout << "Bake" << "\t" << "\t" << isIsogram("Bake") << endl;
	cout << "Lay" << "\t" << "\t" << isIsogram("Lay") << endl;
	cout << "Issue" << "\t" << "\t" << isIsogram("Issue") << endl;
	cout << "Wood" << "\t" << "\t" << isIsogram("Wood") << endl;
	cout << "Swop" << "\t" << "\t" << isIsogram("Swop") << endl;
	cout << "Coup" << "\t" << "\t" << isIsogram("Coup") << endl;
	cout << "Trouser" << "\t" << "\t" << isIsogram("Trouser") << endl;
	cout << "Superior" << "\t" << isIsogram("Superior") << endl;
	cout << "History" << "\t" << "\t" << isIsogram("History") << endl;
	cout << "Disclose" << "\t" << isIsogram("Disclose") << endl << endl;

	cout << "Press enter to exit" << endl;

	cin.get();

	return 0;
}