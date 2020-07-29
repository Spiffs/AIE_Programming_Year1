
#include <iostream>
#include <string>
#include <Windows.h>

//STD namespace definition
using namespace std;

#pragma region || VALUES || 

//constants
const char* RED = "\x1b[91m";
const char* GREEN = "\x1b[92m";
const char* WHITE = "\x1b[97m";
const char* MAGENTA = "\x1b[95m";
const char* INDENT = "\x1b[5C";
const char* RESET_COLOUR = "\x1b[0m";

const char* ESC = "\x1b";

//Play area
int boxes[3][3];

//Game run bool
bool gameover = false;
int wincolumn = 0;
int winrow = 0;
int windiagonal = 0;

//Player bool
bool playerwin = false;
//false = player 1 
//true = player 2

//Cases
const int EMPTY = 0;
const int PLAYER1 = 1;
const int PLAYER2 = 2;

//Temp
int column = 0;
int row = 0;

//Void declaration
void playertwo();
void win();
void gameoverscript();

#pragma endregion

#pragma region || DRAW ||

//Prints the title and simple rules
void printintro()
{
	cout << INDENT << "   " << MAGENTA << "TIC TAC TOE" << RESET_COLOUR << endl;
	cout << INDENT << WHITE << "Player One is X's" << endl;
	cout << INDENT << WHITE << "Player Two is O's" << endl << endl;
}

//Draws Play area, includes freen coloured win prints too 
void drawplayarea()
{
	for (int y = 0; y < 3; y++)
	{
		cout << INDENT;
		for (int x = 0; x < 3; x++)
		{
			switch (boxes[y][x])
			{
				//case EMPTY = 0
			case EMPTY:
				cout << "(   ) ";
				break;
				//case PLAYER1 = 1
			case PLAYER1:
				if (playerwin)
				{
					//Tests for box win, creates green to identify which boxes won if so
					if (gameover && ((wincolumn == y || winrow == x) ||
						((x == 0 && y == 0) && windiagonal == 1) ||
						((x == 1 && y == 1) && windiagonal == 1) ||
						((x == 2 && y == 2) && windiagonal == 1) ||
						((x == 0 && y == 2) && windiagonal == 2) ||
						((x == 1 && y == 1) && windiagonal == 2) ||
						((x == 2 && y == 0) && windiagonal == 2)))
					{
						cout << GREEN << "( X ) " << RESET_COLOUR;
					}
					//If not then print regular text
					else
					{
						cout << "( X ) ";
					}
				}
				//If not then print regular text
				else
				{
					cout << "( X ) ";
				}
				break;
				//case PLAYER2 = 2
			case PLAYER2:
				if (!playerwin)
				{
					//Tests for box win, creates green to identify which boxes won if so
					if (gameover && ((wincolumn == y || winrow == x) ||
						((x == 0 && y == 0) && windiagonal == 1) ||
						((x == 1 && y == 1) && windiagonal == 1) ||
						((x == 2 && y == 2) && windiagonal == 1) ||
						((x == 0 && y == 2) && windiagonal == 2) ||
						((x == 1 && y == 1) && windiagonal == 2) ||
						((x == 2 && y == 0) && windiagonal == 2)))
					{
						cout << GREEN << "( O ) " << RESET_COLOUR;
					}
					//If not then print regular text
					else
					{
						cout << "( O ) ";
					}
				}
				//If not then print regular text
				else
				{
					cout << "( O ) ";
				}
				break;
			}
		}
		cout << endl;
	}
	cout << endl << endl;
}

#pragma endregion

#pragma region || PLAYERS || 

//Player one function which flows into player two
void playerone()
{
	//Clear input buffer
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	column = 0;
	row = 0;

	//Players do their turns 
	//P1 Column
	cout << INDENT << "PLayer One's Turn: " << endl;
	cout << INDENT << "Column: ";
	cin >> column;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	//Tests for input being out of bounds and input fail and for letter input
	if (column < 1 || column > 3 || cin.fail())
	{
		cout << "Try Again, Press enter to continue" << endl;
		cin.get();
	}
	else
	{
		//P1 Row
		cout << INDENT << "Row: ";
		cin >> row;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		//Tests for input being out of bounds and input fail and for letter input
		if (row < 1 || row > 3 || cin.fail())
		{
			cout << INDENT << "Try Again, Press enter to continue" << endl;
			cin.get();
		}
		else
		{
			//Tests for simple input errors
			if (boxes[row - 1][column - 1] == 2)
			{
				cout << INDENT << "Try Again, Press enter to continue" << endl;
				cin.get();
			}
			//If all tests pass then, sets the box to 1 which is the PLAYER1 case
			else
			{
				boxes[row - 1][column - 1] = 1;
				playerwin = true;
				win();
				if (!gameover)
				{
					playertwo();
				}
			}
		}
	}
}

//Player two triggered by player one 
void playertwo()
{
	//Clear input buffer
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	column = 0;
	row = 0;

	//Clear screen
	system("cls");

	//Print 
	printintro();
	drawplayarea();

	//P2 Column
	cout << INDENT << "PLayer Twos's Turn: " << endl;
	cout << INDENT << "Column: ";
	cin >> column;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	//Tests for input being out of bounds and input fail and for letter input
	if (column < 1 || column > 3 || cin.fail())
	{
		cout << INDENT << "Try Again, Press enter to continue" << endl;
		cin.get();
		playertwo();
	}
	else
	{
		//P2 Row
		cout << INDENT << "Row: ";
		cin >> row;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		//Tests for input being out of bounds and input fail and for letter input
		if (row < 1 || row > 3 || cin.fail())
		{
			cout << INDENT << "Try Again, Press enter to continue" << endl;
			cin.get();
			playertwo();
		}
		else
		{
			//Tests for simple input errors
			if (boxes[row - 1][column - 1] == 1)
			{
				cout << INDENT << "Try Again, Press enter to continue" << endl;
				cin.get();
				playertwo();
			}
			//If all tests pass then, sets the box to 2 which is the PLAYER2 case
			else
			{
				boxes[row - 1][column - 1] = 2;
				win();
			}
		}
	}
}

#pragma endregion

//Main script
int main()
{
	//On game beginning sets all boxes to EMPTY which is 0
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			boxes[y][x] = 0;
		}
	}

	while (!gameover)
	{
		//Clear screen
		system("cls");

		//Print 
		printintro();
		drawplayarea();

		//Player One's turn, leads into PlayerTwos turn
		playerone();
	}
	return 0;
}

#pragma region || WIN AND GAMEOVER || 

void win()
{
	//Horizontal Wins
	for (int y = 0; y < 3; y++)
	{
		if (boxes[y][0] != 0)
		{
			if ((boxes[y][0] == boxes[y][1]) && (boxes[y][0] == boxes[y][2]))
			{
				gameover = true;
				wincolumn = y;
				winrow = 4;
				gameoverscript();
			}
		}
	}

	//Verticle Wins 
	for (int x = 0; x < 3; x++)
	{
		if (boxes[0][x] != 0)
		{
			if (boxes[0][x] == boxes[1][x] && boxes[0][x] == boxes[2][x])
			{
				gameover = true;
				winrow = x;
				wincolumn = 4;
				gameoverscript();
			}
		}
	}

	//Diagonal Wins
	if (boxes[0][0] != 0)
	{
		if (boxes[0][0] == boxes[1][1] && boxes[0][0] == boxes[2][2])
		{
			gameover = true;
			windiagonal = 1;
			wincolumn = 4;
			winrow = 4;
			gameoverscript();
		}
	}

	if (boxes[0][2] != 0)
	{
		if (boxes[0][2] == boxes[1][1] && boxes[0][2] == boxes[2][0])
		{
			gameover = true;
			windiagonal = 2;
			wincolumn = 4;
			winrow = 4;
			gameoverscript();
		}
	}
	playerwin = false;
}

void gameoverscript()
{
	//Clear screen
	system("cls");

	//Print 
	printintro();
	drawplayarea();

	string player;

	if (playerwin) { player = "Player One"; }
	else { player = "Player Two"; }

	cout << INDENT << GREEN << "  " << player << " Won!" << RESET_COLOUR << endl;
	cout << INDENT << "Press Enter to exit" << endl;
	cin.get();

	ESC;
}

#pragma endregion