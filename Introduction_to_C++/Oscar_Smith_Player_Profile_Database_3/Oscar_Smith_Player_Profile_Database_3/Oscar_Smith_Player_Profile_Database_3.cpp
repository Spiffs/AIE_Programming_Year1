#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <filesystem>
#include "Player.h"
#include "DynamicArray.h"

// using std
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ios;

// constants 
const char* BLUE = "\x1b[94m";
const char* INDENT = "\x1b[5C";
const char* RESET_COLOR = "\x1b[0m";
void Menu();

// array
DynamicArray playerarray;

// print function
void Print()
{
	system("cls");
	cout << endl << "\t" << BLUE << "Score Entries:" << RESET_COLOR << endl << endl;

	for (int i = 0; i < playerarray.Length(); i++)
	{
		Player tempprint = playerarray.PrintAt(i);
		{
			cout << tempprint.m_score;
			cout << "\t" << tempprint.m_name << endl;
		}
	}
	cin.get();
	Menu();
}

// create function
void Create()
{
	char a_name[4];
	int a_score;

	// flushing cin buffer
	cin.seekg(0, ios::end);
	cin.clear();

	system("cls");

	// name input
	cout << endl << BLUE << INDENT << "   Create:" << RESET_COLOR << endl;
	cout << endl << INDENT << "Name (can be max 3 characters long): ";
	cin >> a_name;

	// input Fail Test
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	if (cin.fail() || strlen(a_name) > 3)
	{
		system("cls");
		cout << endl << "\t" << "Try Again, Press enter to continue" << endl;
		cin.get();
		Create();
	}

	// flushing cin buffer
	cin.seekg(0, ios::end);
	cin.clear();

	// score input
	cout << endl << INDENT << "Score: ";
	cin >> a_score;

	// sorts the array by name to prepare for 
	int binarypos = playerarray.BinarySort(a_name);

	if (binarypos == -1)
	{
		playerarray.AddEnd(a_score, a_name);
	}
	else
	{
		playerarray.UpdatePos(binarypos, a_score);
		system("cls");
		cout << playerarray.GetName(binarypos) << " score was updated." << endl;
	}

	cin.get();
	Menu();
}

// menu function
void Menu()
{
	// clears screen
	system("cls");

	// outputs Menu items
	cout << endl << BLUE << INDENT << "   MENU" << RESET_COLOR << endl << endl;
	cout << INDENT << "1. View Highest Scores" << endl;
	cout << INDENT << "2. Create New Entry" << endl;
	cout << INDENT << "3. Sort By Name" << endl;
	cout << INDENT << "4. Save and Exit" << endl;

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

	if (cin.fail() || menuselect > 4 || menuselect < 1)
	{
		system("cls");
		cout << endl << INDENT << "Try Again, Press enter to continue" << endl;
		cin.get();
		Menu();
	}

	if (menuselect == 1)
	{
		playerarray.Highscores();
		Print();
	}
	else if (menuselect == 2)
	{
		Create();
	}

	else if (menuselect == 3)
	{
		playerarray.NameSort();
		Print();
	}
	else if (menuselect == 4)
	{
		playerarray.WriteFile();
		exit(0);
	}
}

int main()
{
	playerarray.ReadFile();
	Menu();

	return 0;
}

