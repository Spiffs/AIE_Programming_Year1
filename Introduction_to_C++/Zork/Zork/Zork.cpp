
#include <iostream>
#include <windows.h>
#include <random>
#include <time.h>

//Using std:: to stop repitition in code
using namespace std;

//
const char* ESC = "\x1b";
const char* CSI = "\x1b[";

//Constants
const char* TITLE = "\x1b[5;20H";
const char* INDENT = "\x1b[5C";
const char* RESET_COLOR = "\x1b[0m";
const char* SAVE_CURSOR_POS = "\x1b[s";
const char* RESTORE_CURSOR_POS = "\x1b[u";

//Colours
const char* RED = "\x1b[91m";
const char* BLUE = "\x1b[94m";
const char* WHITE = "\x1b[97m";
const char* GREEN = "\x1b[92m";
const char* YELLOW = "\x1b[93m";
const char* MAGENTA = "\x1b[95m";

int main()
{
	//Stores the Console Mode
	DWORD dwMode = 0;
	//Gets handle of the standard output (akin to an identifier)
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//Gets current output mode
	GetConsoleMode(hOut, &dwMode);
	//Amend the current output mode to include "Enable Virtual Terminal Sequences
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	//Set the console output mode 
	SetConsoleMode(hOut, dwMode);

	//States
	const int EMPTY = 0;
	const int ENEMY = 1;
	const int TREASURE = 2;
	const int FOOD = 3;
	const int ENTRANCE = 4;
	const int EXIT = 5;
	const int MAX_RANDOM_TYPE = FOOD + 1;

	//Maze permeters
	const int MAZE_WIDTH = 10;
	const int MAZE_HEIGHT = 6;

	//Ints
	const int INDENT_X = 5;
	const int ROOM_DESC_Y = 8;
	const int MAP_Y = 13;
	const int PLAYER_INPUT_X = 30;
	const int PLAYER_INPUT_Y = 11;

	//Directions
	const int WEST = 4;
	const int EAST = 6;
	const int NORTH = 8;
	const int SOUTH = 2;

	cout << "Hello world!"; 
	cout << "\x1b[2J\x1b[H"; 
	cout << "Did you see it?";

	int height;
	char firstLetterOfName = 0;
	int avatarHP = 0;

	int rooms[MAZE_HEIGHT][MAZE_WIDTH];

	srand(time(nullptr));

	//Sets values for maze array
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			int type = rand() % (MAX_RANDOM_TYPE * 2);
			if (type < MAX_RANDOM_TYPE)
			{
				rooms[y][x] = type;
			}
			else
			{
				rooms[y][x] = EMPTY;
			}
		}
	}

	//
	rooms[0][0] = ENTRANCE;
	rooms[MAZE_HEIGHT - 1][MAZE_WIDTH - 1] = EXIT;

	cout << TITLE << MAGENTA << "Welcome to ZORP!" << RESET_COLOR << endl;
	cout << INDENT << "ZORK us a gane if adventure, danger, and low cunning." << endl;
	cout << INDENT << "It is definutly not related to any other text'based adventure game." << endl << endl;

	cout << INDENT << "First, some questions" << endl;

	//Saves cursor position
	cout << SAVE_CURSOR_POS;

	///Leaves space for maze
	cout << CSI << MAP_Y << ";" << 0 << "H";

	//Prints values for maze array
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		cout << INDENT;
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			switch (rooms[y][x])
			{
			case EMPTY:
				cout << "[ " << GREEN << "\xb0" << RESET_COLOR << " ] ";
				break;
			case ENEMY:
				cout << "[ " << RED << "\x94" << RESET_COLOR << " ] ";
				break;
			case TREASURE:
				cout << "[ " << YELLOW << "$" << RESET_COLOR << " ] ";
				break;
			case FOOD:
				cout << "[ " << WHITE << "\xcf" << RESET_COLOR << " ] ";
				break;
			case ENTRANCE:
				cout << "[ " << WHITE << "\x9d" << RESET_COLOR << " ] ";
				break;
			case EXIT:
				cout << "[ " << WHITE << "\xFE" << RESET_COLOR << " ] ";
				break;
			}
		}
		cout << endl;
	}

	bool gameOver = false;
	int playerX = 0;
	int playerY = 0;

	//Game loop
	while (!gameOver)
	{
		// prepare screen for output
		// move cursor to start of the 1st Q, then up 1, delete and insert 4 lines
		cout << RESTORE_CURSOR_POS << CSI << "A" << CSI << "4M" << CSI << "4L" << endl;

		// write description of current room
		switch (rooms[playerY][playerX])
		{
		case EMPTY:
			cout << INDENT << "You are in an empty meadow. There is nothing ofnote here. " << endl;
			break;
		case ENEMY:
			cout << INDENT << "BEWARE. An enemy is approaching." << endl;
			break;
		case TREASURE:
			cout << INDENT << "Your journey has been rewarded. You have foundsome treasure" << endl;
			break;
		case FOOD:
			cout << INDENT << "At last! You collect some food to sustain youon your journey." << endl;
			break;
		case ENTRANCE:
			cout << INDENT << "The entrance you used to enter this maze isblocked.There is no going back." << endl;
			break;
		case EXIT:
			cout << INDENT << "Despite all odds, you made it to the exit.Congratulations." << endl;
			gameOver = true;
			continue;
		}

		// list the directions the player can take
		cout << INDENT << "You can see paths leading to the " <<
			((playerX > 0) ? "west, " : "") <<
			((playerX < MAZE_WIDTH - 1) ? "east, " : "") <<
			((playerY > 0) ? "north, " : "") <<
			((playerY < MAZE_HEIGHT - 1) ? "south, " : "") << endl;

		cout << INDENT << "Where to now?";

		int x = INDENT_X + (6 * playerX) + 3;
		int y = MAP_Y + playerY;
		// draw the player's position on the map

		// move cursor to map pos and delete character at current position
		cout << CSI << y << ";" << x << "H";
		cout << MAGENTA << "\x81";

		// move cursor to position for player to enter input
		cout << CSI << PLAYER_INPUT_Y << ";" << PLAYER_INPUT_X << "H" << YELLOW;

		// clear the input buffer, ready for player input
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		int direction = 0;

		cin >> direction;

		cout << RESET_COLOR;
		if (std::cin.fail())
			continue;

		// before updating the player position, redraw the old room character over 
		// the old position
		cout << CSI << y << ";" << x << "H";
		switch (rooms[playerY][playerX])
		{
		case EMPTY:
			cout << GREEN << "\xb0" << RESET_COLOR;
			break;
		case ENEMY:
			cout << RED << "\x94" << RESET_COLOR;
			break;
		case TREASURE:
			cout << YELLOW << "$" << RESET_COLOR;
			break;
		case FOOD:
			cout << WHITE << "\xcf" << RESET_COLOR;
			break;
		case ENTRANCE:
			cout << WHITE << "\x9d" << RESET_COLOR;
			break;
		case EXIT:
			cout << WHITE << "\xFE" << RESET_COLOR;
			break;
		}

		cout << INDENT << "You can see paths leading to the ";

		if (playerX > 0)
		{
			cout << "west, ";
		}
		if (playerX < MAZE_WIDTH - 1)
		{
			cout << "east, ";
		}
		if (playerY > 0)
		{
			cout << "north, ";
		}
		if (playerY < MAZE_HEIGHT - 1)
		{
			cout << "south, ";
		}

		switch (direction) {
		case EAST:
			if (playerX < MAZE_WIDTH - 1)
				playerX++;
			break;
		case WEST:
			if (playerX > 0)
				playerX--;
			break;
		case NORTH:
			if (playerY > 0)
				playerY--;
			break;
		case SOUTH:
			if (playerY < MAZE_HEIGHT - 1)
				playerY++;
		default:
			// do nothing, go back to the top of the loop and ask again
			break;

		}
		cout << std::endl;

		//_____________________________________________________________________________
		cout << endl << "Press Enter to Exit" << endl;
		cin.get();
	}
	return 0;
}

	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started: 
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
