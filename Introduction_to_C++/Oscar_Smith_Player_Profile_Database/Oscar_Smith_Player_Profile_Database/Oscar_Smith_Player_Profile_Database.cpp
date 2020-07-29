
#include <iostream>
#include <fstream>
#include <filesystem>
#include "Player.h"
#include "Oscar_Smith_Player_Profile_Database.h"

//#define cout std::cout

//using std
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ios;

//While window loop
bool windowrunning = true;

//Array declaration
int playerlength = 3;
int n;

const char* BLUE = "\x1b[94m";
const char* INDENT = "\x1b[5C";
const char* RESET_COLOR = "\x1b[0m";

//Error avoidance 
void readfile();
void Menu();

//Print function
void Print(Player playerarray[])
{
	system("cls");
	cout << INDENT << "  Players:" << endl;
	for (int i = 0; i < playerlength; i++)
	{
		cout << INDENT << playerarray[i].score << INDENT << playerarray[i].name << endl;
	}
	cin.get();
	Menu();
}

//Insertion sort function for scores
void Insertionsort(Player playerarray[])
{
	int key, x;
	for (int i = 1; i < n; i++)
	{
		key = playerarray[i].score;
		x = i - 1;

		while (x >= 0 && playerarray[x].score > key)
		{
			playerarray[i].score = playerarray[x].score;
			x--;
		}
		playerarray[i].score = key;
	}
}

//Print highest scores
void Highscores(Player playerarray[])
{
	n = sizeof(playerarray) / sizeof(playerarray[0]);
	Insertionsort(playerarray);
	Print(playerarray);
}

//Creating new entries
void Create(Player playerarray[])
{
	int placement;
	char name[8];
	int score;

	//Name input
	cout << endl << BLUE << INDENT << "   Create:" << RESET_COLOR << endl;
	cout << endl << INDENT << "Name: ";
	cin >> name;

	//Input Fail Test
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	if (cin.fail())
	{
		cout << INDENT << "Try Again, Press enter to continue" << endl;
		cin.get();
		Create(playerarray);
	}

	//Score input
	cout << endl << INDENT << "Score: ";
	cin >> score;

	for (int i = 0; i < playerlength; i++)
	{
		if (*playerarray[i].name = name)
		{
			playerarray[i].score = score;
			system("cls");
			cout << playerarray[i].name << " score was updated." << endl;
			break;
		}
	}
	cin.get();
	Menu();
}

void Namesort(Player playerarray[])
{
	string key;
	int x;
	for (int i = 1; i < n; i++)
	{
		key = *playerarray[i].name;
		x = i - 1;

		if (x >= 0 && *playerarray[x].name > key)
		{
			strcpy(*playerarray[i].name, *playerarray[x].name); //strcpy http://www.cplusplus.com/reference/cstring/strcpy/ strcpy (str3,"copy successful"); -> example strcpy(playerarray[i].name, playerarray[x].name) HAXXOR
			x--;
		}
		playerarray[i].setname(key);
	}
	Print(playerarray);
}
//Print and input Menu function
void Menu(Player playerarray[])
{

	//Clears screen
	system("cls");

	//Outputs Menu items
	cout << endl << BLUE << INDENT << "   HIGHSCORES" << RESET_COLOR << endl << endl;
	cout << INDENT << "1. View Highest Scores" << endl;
	cout << INDENT << "2. Create New Entry" << endl;
	cout << INDENT << "3. Sort By Name" << endl;

	//Clear and prepare input
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	//Menu input
	int menuselect;
	cin >> menuselect;

	//Input Fail Test
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	if (cin.fail() || menuselect > 3 || menuselect < 1)
	{
		cout << INDENT << "Try Again, Press enter to continue" << endl;
		cin.get();
		Menu();
	}

	if (std::cin.fail())
		Menu();

	if (menuselect >= 4 || menuselect <= 0)
	{
		cout << "Try Again! ";
		cin.get();
		Menu();
	}

	if (menuselect == 1)
		Highscores(playerarray);

	if (menuselect == 2)
		Create(playerarray);

	if (menuselect == 3)
		Namesort(playerarray);

	//if (menuselect == 4)

}

//const int arrlength()
//{
//	fstream data;
//	data.open("data.dat", ios::in, ios::binary);
//	data.seekg(0, ios::beg);
//	return data.tellg();
//};

//Reads file data to the playerarray
void readfile(Player playerarray[])
{
	fstream data;
	//data.open("data.dat", ios::binary);

	/*if (data.is_open())
	{*/
	//cout << "File exists.";
	data.open("data.dat", ios::in | ios::binary);
	data.seekg(0, ios::beg);
	playerlength = data.tellg();
	for (int i = 0; i < playerlength; i++)
	{
		data.seekg(i + 1, ios::beg);
		playerarray[i] = data.tellg();
	}
	cin.get();
	//}
	//else
	//{
	//	cout << "File does not exist." << endl;
	//	playerlength = 3;
	//	playerarray[0].score = 1400;
	//	playerarray[0].name = "Jay";
	//	playerarray[1].score = 2000;
	//	playerarray[1].name = "Ben";
	//	playerarray[2].score = 1299;
	//	playerarray[2].name = "Len";

	//	//data.write

	//	cout << "File successfully created!" << endl;

	//	cin.get();
	//}
	data.close();
}

//Main function
int main()
{
	playerlength = arrlength();
	Player* playerarray = new Player[playerlength];
	readfile(playerarray);
	cin.get();


	Menu();


	delete[] playerarray;

	return 0;
}