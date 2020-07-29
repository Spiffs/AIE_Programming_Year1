#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <filesystem>
#include "Player.h"

#pragma 

// using std
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ios;

// while window loop
bool windowrunning = true;

// constants 
const char* BLUE = "\x1b[94m";
const char* INDENT = "\x1b[5C";
const char* RESET_COLOR = "\x1b[0m";

// global values 
int playerlength = 0;
Player *player = new Player[4];

void Menu(Player playerarray[]);

void Fillin()
{
	strcpy_s(player[0].m_name, "Osaka");
	player[0].m_score = 99;

	strcpy_s(player[1].m_name, "Jay");
	player[1].m_score = 99999;

	strcpy_s(player[2].m_name, "Duncan");
	player[2].m_score = 21;

	strcpy_s(player[3].m_name, "Jacob");
	player[3].m_score = 1;
}

// prints the array in order from 0 - n
void Print(Player playerarray[])
{
	//cout << INDENT << BLUE << "  Players:" << RESET_COLOR << endl;
	for (int i = 0; i < playerlength; i++)
	{
		cout << INDENT << playerarray[i].m_score << INDENT << playerarray[i].m_name << endl;
	}
	cin.get();
	Menu(playerarray);
}

// sorting numbers using insertion sort 
void Insertionsort(Player playerarray[])
{
	int key, x;
	for (int i = 1; i < playerlength; i++)
	{
		key = playerarray[i].m_score;
		x = i - 1;

		while (x >= 0 && playerarray[x].m_score > key)
		{
			playerarray[x+1].m_score = playerarray[x].m_score;
			x--;
			playerarray[x+1].m_score = key;
		}
	}
}

// print highest scores
void Highscores(Player playerarray[])
{
	system("cls");

	Insertionsort(playerarray);
	cout << INDENT << BLUE << "HIGHSCORES " << RESET_COLOR << endl;
	Print(playerarray);
}

// sorting names by using a modified version of insertion sort
void Namesort(Player playerarray[])
{
	char key[9];
	int x;
	for (int i = 1; i < playerlength; i++)
	{
		for (int x = 0; x < 9; x++)
		{
			key[x] = playerarray[i].m_name[x];
		}
		x = i - 1;

		while(x >= 0 && playerarray[x].m_name > key)
		{
			strcpy(playerarray[x+1].m_name, playerarray[x].m_name);
			x--;
			playerarray[x+1].setname(key);
		}
		
	}
	cout << INDENT << BLUE << "PLAYERS " << RESET_COLOR << endl;
	Print(playerarray);
}

// adding to an array
Player* ExtendArray(Player* playerarray, int addition)
{
	// array declaration
	Player* newarray = new Player[playerlength + 1];
	Player* orgarray = playerarray;

	// swapping variables 
	for (int i = 0; i < playerlength - 1; i++)
	{
		newarray[i] = playerarray[i];
	}

	playerlength += 1;
	playerarray = newarray;
	
	delete[] orgarray;

	return newarray;
}

// create new Player score 
void Create(Player playerarray[])
{
	char name[9];
	int score;

	system("cls");

	// name input
	cout << endl << BLUE << INDENT << "   Create:" << RESET_COLOR << endl;
	cout << endl << INDENT << "Name: ";
	cin >> name;

	// input Fail Test
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	if (cin.fail())
	{
		cout << INDENT << "Try Again, Press enter to continue" << endl;
		cin.get();
		Create(playerarray);
	}

	// score input
	cout << endl << INDENT << "Score: ";
	cin >> score;

	bool update = false;

	// searching for matching name 
	for (int i = 0; i < playerlength; i++)
	{
		if (playerarray[i].m_name == name)
		{
			playerarray[i].m_score = score;
			system("cls");
			cout << playerarray[i].m_name << " score was updated." << endl;

			update;
			break;
		}
	}

	// if not update then add to new value
	if (!update)
	{
		// extending array to fit extra value
		playerarray = ExtendArray(playerarray, 1);

		// adding values to new value
		playerarray[playerlength - 1].setname(name);
		playerarray[playerlength - 1].setscore(score);
	}

	cin.get();
	Menu(playerarray);
}

// menu function
void Menu(Player playerarray[])
{
	// clears screen
	system("cls");

	// outputs Menu items
	cout << endl << BLUE << INDENT << "   MENU" << RESET_COLOR << endl << endl;
	cout << INDENT << "1. View Highest Scores" << endl;
	cout << INDENT << "2. Create New Entry" << endl;
	cout << INDENT << "3. Sort By Name" << endl;

	// clear and prepare input
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	cout << INDENT;

	// menu input
	int menuselect;
	cin >> menuselect;

	// input Fail Test
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	if (cin.fail() || menuselect > 3 || menuselect < 1)
	{
		system("cls");
		cout << endl << INDENT << "Try Again, Press enter to continue" << endl;
		cin.get();
		Menu(playerarray);
	}

	if (std::cin.fail())
	{

		Menu(playerarray);
	}
		
	// menu cin result outcomes 
	if (menuselect >= 4 || menuselect <= 0)
	{
		cout << "Try Again! ";
		cin.get();
		Menu(playerarray);
	}

	if (menuselect == 1)
		Highscores(playerarray);

	if (menuselect == 2)
		Create(playerarray);

	if (menuselect == 3)
		Namesort(playerarray);
}

// read from file on open
void readfile(Player playerarray[])
{
	int newlength;

	fstream data;
	data.open("data.dat", ios::in | ios::binary);
	if (!data)
	{
		data.close();
		data.open("data.dat", ios::out | ios::binary);

		for (int i = 0; i < 4; i++)
		{
			data.write((char*)&player[i], sizeof(Player));
		}

		data.close();
		data.open("data.dat", ios::in | ios::binary);
	}
	data.seekg(0, ios::end);
	newlength = data.tellp() / sizeof(Player);
	data.seekg(0, ios::beg);
	playerarray = ExtendArray(playerarray, newlength);

	for (int i = 0; i < playerlength; i++)
	{
		data.read((char*)&playerarray[i], sizeof(Player));
	}
	data.close();
}

// main function
int main()
{
	Fillin();

	// initialise main array 
	Player* playerarray = new Player[playerlength];

	// begin by reading from file
	readfile(playerarray);

	Menu(playerarray);

	// end main by returning a variable
	return 0;
}
