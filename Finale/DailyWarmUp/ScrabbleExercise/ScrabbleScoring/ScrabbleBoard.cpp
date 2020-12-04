
#include "ScrabbleBoard.h"

#include <cstring>

#include <cctype>

ScrabbleBoard::ScrabbleBoard(int rows, int cols) :
	ROWS(rows), COLS(cols)
{
	m_boardModifiers = new unsigned int[ROWS * COLS];
	m_boardCharacters = new char[ROWS * COLS];

	// Initialise board values
	for (int i = 0; i < ROWS * COLS; i++)
	{
		m_boardModifiers[i] = (int)EScoreMod::NO;
		m_boardCharacters[i] = ' ';
	}
}

ScrabbleBoard::~ScrabbleBoard()
{
	delete[] m_boardModifiers;
	delete[] m_boardCharacters;
}

ScrabbleBoard::EScoreMod ScrabbleBoard::GetBoardModifier(int xIndex, int yIndex)
{
	int index = yIndex * ROWS + xIndex;
	return (EScoreMod)m_boardModifiers[index];
}

char ScrabbleBoard::GetBoardCharacter(int xIndex, int yIndex)
{
	int index = yIndex * ROWS + xIndex;
	return m_boardCharacters[index];
}

void ScrabbleBoard::SetBoardCharacter(int xIndex, int yIndex, char c)
{
	if (xIndex < 0 || yIndex < 0 || xIndex >= COLS || yIndex >= ROWS)
		return;

	int index = yIndex * ROWS + xIndex;
	m_boardCharacters[index] = c;
}

void ScrabbleBoard::SetBoardScoreModifiers(unsigned int* board)
{
	for (int i = 0; i < ROWS * COLS; i++)
		m_boardModifiers[i] = board[i];
}

void ScrabbleBoard::PlaceText(int xIndex, int yIndex, const char* text, EDirection dir)
{
	int xo = 0, yo = 0;
	switch (dir)
	{
	case EDirection::RIGHT: xo = 1; break;
	case EDirection::DOWN:  yo = 1; break;
	}

	int len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		int xi = xIndex + (i * xo);
		int yi = yIndex + (i * yo);

		SetBoardCharacter(xi, yi, text[i]);
	}

	int score = CalculateScore(xIndex, yIndex, text, dir);
	m_totalScore += score;
}

unsigned int ScrabbleBoard::GetTotalScore()
{
	return m_totalScore;
}

bool ScrabbleBoard::CanPlaceText(int xIndex, int yIndex, const char* text, EDirection dir)
{
	// ========================================================================
	// DAILY WARMUP - TODO
	// ========================================================================
	// write your code here



	return true;
}

unsigned int ScrabbleBoard::GetCharacterWorth(const char& _char)
{
#pragma region LETTER WORTH DEFINITIONS

	char nChar = _char;
	tolower(nChar);

	if (_char == 'a')
		return 1;
	else if (_char == 'b')
		return 3;
	else if (_char == 'c')
		return 3;
	else if (_char == 'd')
		return 2;
	else if (_char == 'e')
		return 1;
	else if (_char == 'f')
		return 4;
	else if (_char == 'g')
		return 2;
	else if (_char == 'h')
		return 4;
	else if (_char == 'i')
		return 1;
	else if (_char == 'j')
		return 8;
	else if (_char == 'k')
		return 5;
	else if (_char == 'l')
		return 2;
	else if (_char == 'm')
		return 3;
	else if (_char == 'n')
		return 1;
	else if (_char == 'o')
		return 1;
	else if (_char == 'p')
		return 3;
	else if (_char == 'q')
		return 10;
	else if (_char == 'r')
		return 1;
	else if (_char == 's')
		return 1;
	else if (_char == 't')
		return 1;
	else if (_char == 'u')
		return 1;
	else if (_char == 'v')
		return 4;
	else if (_char == 'w')
		return 4;
	else if (_char == 'x')
		return 8;
	else if (_char == 'y')
		return 4;
	else if (_char == 'z')
		return 10;
	else
	{
		return 100;
	}

#pragma endregion
}

unsigned int ScrabbleBoard::CalculateScore(int xIndex, int yIndex, const char* text, EDirection dir)
{
	// ========================================================================
	// DAILY WARMUP - TODO
	// ========================================================================
	// write your code here

	int len = strlen(text);
	int totalscore = 0;
	int endwordmultiplier = 1;
	int xo = 0, yo = 0;

	switch (dir)
	{
	case EDirection::RIGHT: xo = 1; break;
	case EDirection::DOWN:  yo = 1; break;
	}

	for (int i = 0; i < len; i++)
	{
		int xi = xIndex + (i * xo);
		int yi = yIndex + (i * yo);


		auto characterworth = GetCharacterWorth(text[i]);
		auto modifier = GetBoardModifier(xi, yi);

		switch (modifier)
		{
		case ScrabbleBoard::EScoreMod::NO:
		{
			totalscore += characterworth;
			break;
		}
		case ScrabbleBoard::EScoreMod::DL:
		{
			totalscore += characterworth * 2;
			break;
		}
		case ScrabbleBoard::EScoreMod::TL:
		{
			totalscore += characterworth * 3;
			break;
		}
		case ScrabbleBoard::EScoreMod::DW:
		{
			if (endwordmultiplier == 1)
			{
				endwordmultiplier = 2;
			}
			else
			{
				endwordmultiplier *= 2;
			}
			totalscore += characterworth;
			break;
		}
		case ScrabbleBoard::EScoreMod::TW:
		{
			if (endwordmultiplier == 1)
			{
				endwordmultiplier = 3;
			}
			else
			{
				endwordmultiplier *= 3;
			}
			totalscore += characterworth;
			break;
		}
		}
	}


	return totalscore * endwordmultiplier;
}