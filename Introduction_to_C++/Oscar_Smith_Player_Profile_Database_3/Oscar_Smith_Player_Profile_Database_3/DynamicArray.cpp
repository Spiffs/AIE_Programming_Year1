#include "DynamicArray.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <filesystem>

// empty constructor
DynamicArray::DynamicArray()
{
	m_DA = new Player[5];
}

// int constructor using array length 
DynamicArray::DynamicArray(int a_length)
{
	m_DA = new Player[5 + a_length];

	m_allocatedlength = 5 + a_length;
}

// destructor
DynamicArray::~DynamicArray()
{
	delete[] m_DA;
}

// removes the last value of the array
void DynamicArray::RemoveEnd()
{
	m_usedlength--;
	m_DA[m_usedlength].SetName(NULL);
	m_DA[m_usedlength].SetScore(NULL);

	if (m_allocatedlength <= m_usedlength + 5)
	{
		ChangeLength(5);
	}
}

// adds a value to the end of the array
void DynamicArray::AddEnd(int a_score, char a_name[4])
{
	m_DA[m_usedlength].SetScore(a_score);
	m_DA[m_usedlength].SetName(a_name);
	m_usedlength++;
	CheckLength();
}

// removes the middle value of the array
// (if the array length is an odd number it will round down)
void DynamicArray::RemoveMiddle()
{
	if (m_usedlength >= 2)
	{
		m_DA[m_usedlength / 2].SetScore(NULL);
		m_DA[m_usedlength / 2].SetName(NULL);
	}

	// moves all values after the removed value to fill in empty space
	for (int i = (m_usedlength / 2) + 1; i < m_usedlength; i++)
	{
		m_DA[i - 1] = m_DA[i];
	}
}

// adds a value into the middle of the array
void DynamicArray::AddMiddle(int a_score, char a_name[4])
{
	for (int i = (m_usedlength - 1); i > m_usedlength / 2; i--)
	{
		m_DA[i] = m_DA[i + 1];
	}

	m_DA[m_usedlength / 2].SetScore(a_score);
	m_DA[m_usedlength / 2].SetName(a_name);
	m_usedlength++;
	CheckLength();
}

// adds to a certain value of the array
void DynamicArray::UpdatePos(int position, int a_score)
{
	m_DA[position].m_score = a_score;
}

// changes the length of the arrays allocated length
void DynamicArray::ChangeLength(int a_length)
{
	Player* newarr = new Player[m_allocatedlength + a_length];
	Player* orgarr = m_DA;

	for (int i = 0; i < m_usedlength; i++)
	{
		newarr[i] = m_DA[i];
	}

	m_DA = newarr;
	m_allocatedlength += a_length;

	delete[] orgarr;
}

// checks only if there is not enough space in the array to hold length while inputting values
void DynamicArray::CheckOnlyPositiveLength()
{
	if (m_allocatedlength <= m_usedlength + 5)
	{
		ChangeLength(5);
	}
}

// checks the length of the array and resizes if too large or too small to save on memory
void DynamicArray::CheckLength()
{
	if (m_allocatedlength <= m_usedlength + 5)
	{
		ChangeLength(5);
	}
	if (m_allocatedlength >= m_usedlength + 15)
	{
		ChangeLength(-5);
	}
}

int DynamicArray::Length()
{
	return m_usedlength;
}

Player DynamicArray::PrintAt(int i)
{
	Player a_player;
	a_player.SetScore(m_DA[i].m_score);
	a_player.SetName(m_DA[i].m_name);

	return a_player;
}

void DynamicArray::Clear()
{
	for (int i = m_usedlength - 1; i > 0; i--)
	{
		m_DA[i].SetScore(NULL);
		m_DA[i].SetName(NULL);
		CheckLength();
	}

	m_usedlength = 0;
}

void DynamicArray::ReadFile()
{
	int newlength;

	std::fstream data;
	data.open("data.dat", std::ios_base::in | std::ios_base::binary);
	if (!data.good())
	{
		data.close();
		data.open("data.dat", std::ios_base::out | std::ios_base::binary);
		data.close();
		data.open("data.dat", std::ios_base::in | std::ios_base::binary);
	}
	// fetching the initial length of the array
	data.seekg(0, std::ios_base::end);
	newlength = data.tellp() / sizeof(Player);
	ChangeLength(newlength);

	// resetting the cursor
	data.seekg(0, std::ios_base::beg);
	
	// reading from file 
	int i = 0;
	if (data.is_open())
	{
		while (!data.eof() && data.peek() != EOF)
		{
			data.read((char*)&m_DA[i], sizeof(Player));
			i++;
		}
		m_usedlength += i;
		data.close();
	}
	//																										HAXXOR
}

// writes all entries to file 
void DynamicArray::WriteFile()
{
	// length gets the array length to write for
	int length = Length();

	std::fstream data;
	data.open("data.dat", std::ios_base::out | std::ios_base::binary);
	if (data.good())
	{
		// cycles through and writes
		for (int i = 0; i < length; i++)
		{
			data.write((char*)&m_DA[i], sizeof(Player));
		}
		data.close();
	}
}

// sorts array by score using insertion sort
void DynamicArray::Highscores()
{
	Player key;
	int x;
	for (int i = 1; i < m_usedlength; i++)
	{
		key = m_DA[i];
		x = i - 1;

		while (x >= 0 && m_DA[x].m_score < key.m_score)
		{
			m_DA[x + 1] = m_DA[x];
			x--;
			m_DA[x + 1] = key;
		}
	}
}

// sorts the names of the array using bubble sort
void DynamicArray::NameSort()
{
	int result;
	for (int i = 0; i < m_usedlength; i++)
	{
		for (int j = 0; j < m_usedlength - 1 - i; ++j)
		{            
			result = strcmp(m_DA[j].m_name, m_DA[j + 1].m_name);
              
			if (result > 0)
				std::swap(m_DA[j], m_DA[j + 1]);
		}	 	
	}
}

int DynamicArray::BinarySort(char a_name[4])
{
	NameSort();

	int L = 0;
	int R = m_usedlength - 1;

	while (L <= R)
	{
		int M = (L + R) / 2;

		if (strcmp(m_DA[M].m_name, a_name) == 0)
		{
			return M;
		}
		else if (m_DA[M].m_name > a_name)
		{
			L = M + 1;
		}
		else if (m_DA[M].m_name < a_name)
		{
			R = M - 1;
		}
	}
	return -1;
}

int DynamicArray::GetScore(int position)
{
	return m_DA[position].m_score;
}

char* DynamicArray::GetName(int position)
{
	return m_DA[position].m_name;
}